int signalLed = 13;
int ESrelay = 4;
int Beep = 2;



void setup() {
  pinMode(ESrelay, OUTPUT);
  pinMode(signalLed, OUTPUT);
  pinMode(Beep, OUTPUT);
  digitalWrite(Beep, LOW);
  digitalWrite(ESrelay, LOW);
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial.available()) {
    ; // wait for serial port to connect. Needed for native USB
  }
}


void loop() {

	delay(3000);
	digitalWrite(signalLed, HIGH);
	Serial.println("Trial start");
	for(int j=0; j<5; j++){
	    delay(30000);
	    for(int i=0; i<30; i++){
	        digitalWrite(ESrelay, HIGH); 
	        Serial.println("ES on");
	        delay(500);                   
	        digitalWrite(ESrelay, LOW);
	        Serial.println("ES off");
	        delay(500);
	    }
	}
	Serial.println("Trial end");
	digitalWrite(signalLed, LOW);
	digitalWrite(Beep, HIGH);
    delay(5000);
    
    for(int i=0; i<10; i++){
        digitalWrite(Beep, LOW);
        delay(29000);
        digitalWrite(Beep, HIGH);
        delay(1000);
    }

	while(true){
	    digitalWrite(Beep, LOW);
	    delay(5000);
	    digitalWrite(Beep, HIGH);
	    delay(2000);
	}
}
