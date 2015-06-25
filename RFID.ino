//RFID.ino
#include <SoftwareSerial.h>

SoftwareSerial Reader(2, 3);
String code, known; 
char val;
int LED = 13;

void setup(){
  Serial.begin(9600);
  Serial.println("Serial OK");

  Reader.begin(9600);
  Serial.println("RFID OK");
  pinMode(LED, OUTPUT);
  known = "54004FEA7687 54004F7088E3 1800392A2E25";
}

void loop(){
  while(Reader.available() > 0){
    //keep reading if data available
    val =  Reader.read(); code += val;
    Serial.println(code);
  }
  code = code.substring(1,13);
  if(code.length() > 10) validate(); code = "";
}

void validate(){
    if(known.indexOf(code) >= 0){
      //Tag is known, do something useful.
      Serial.println("Ok.");
      digitalWrite(LED, HIGH); 
      delay(2000); 
      digitalWrite(LED, LOW);
    }
    else
        //Do nothing.
        Serial.println("Denied.");
}


