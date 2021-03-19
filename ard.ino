#include <SoftwareSerial.h>

SoftwareSerial hc06(2,3);

String cmd="";
float sensor_val=0;

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Initialize Bluetooth Serial Port
  hc06.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
}

void loop(){
  //Read data from HC06
  while(hc06.available()>0){
    cmd+=(char)hc06.read();
  }

  //Select function with cmd
  if(cmd!=""){
    Serial.print("Command recieved : ");
    Serial.println(cmd);
    cmd = cmd.charAt(cmd.length()-1);
    // We expect ON or OFF from bluetooth
    if(cmd=="s"){
        Serial.println("Function is on");
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,HIGH);
    }else if(cmd=="w"){
        Serial.println("Function is off");
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
    }else if(cmd=="d"){
        Serial.println("Function is off");
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,HIGH);
        digitalWrite(11,LOW);
        digitalWrite(12,HIGH);
    }else if(cmd=="a"){
        Serial.println("Function is off");
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(9,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(11,HIGH);
        digitalWrite(12,LOW);
    }else{
      digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        Serial.println("Function is off by default");wsdawasd
    }
    cmd=""; //reset cmd
  }
  // Simulate sensor measurement
  sensor_val=(float)random(256); // random number between 0 and 255
    
  //Write sensor data to HC06
  hc06.print(sensor_val);
  delay(100);
}
