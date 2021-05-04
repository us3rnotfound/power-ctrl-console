
int output_pin = 13;
int state = 0; // state of output
unsigned char incoming_byte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(output_pin, OUTPUT);
  digitalWrite(output_pin, LOW); // default to low.

  print_status();
}

void loop()
{
  if (Serial.available()>0)
  {
    incoming_byte = Serial.read();
    
    if (incoming_byte == '0')
      digitalWrite(output_pin, LOW);
    else if (incoming_byte == '1')
      digitalWrite(output_pin, HIGH);
    else
    {
      Serial.print("Invalid character: ");
      Serial.println(incoming_byte);
    }
    
    print_status();
  }
}

void print_status()
{
  state = digitalRead(output_pin);
  
  Serial.print("Current state: ");
  if (state)
    Serial.println("on");
  else
    Serial.println("off");

  Serial.println("Send 0 to turn OFF and 1 to turn ON");
}
