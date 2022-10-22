#include<iostream>

using namespace std;

int main(){
	int  a , b , c , q;
	long long counter;
	cin>>q;
	while(q > 0){
		counter = 0;
		cin>>a>>b>>c;
		if(a >= b){
			counter += a - b;
		}
		else{
			counter += b - a;
		}
		if(a >= c){
			counter += a - c;
		}
		else{
			counter += c - a;
		}
		if(b >= c){
			counter += b - c;
		}
		else{
			counter += c - b;
		}
		if(counter <= 4){
			cout<<"0"<<endl;
		}
		else{
			cout<<counter - 4<<endl;
		}
		q--;
	}
	return 0;
}