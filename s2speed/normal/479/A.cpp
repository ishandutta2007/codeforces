#include<iostream>

using namespace std;

int main(){
	int a , b , c;
	cin>>a>>b>>c;
	if(a == 1 && b == 1 && c == 1){
		cout<<"3"<<endl;
	}
	else if(a == 1 && b == 1){
		cout<<c * 2<<endl;
	}
	else if(a == 1 && c == 1){
		cout<<b + 2<<endl;
	}
	else if(b == 1 && c == 1){
		cout<<a * 2<<endl;
	}
	else if(a == 1){
		cout<<(1 + b)*c<<endl;
	}
	else if(b == 1){
		cout<<(1 + min(a,c))*max(a,c)<<endl;
	}
	else if(c == 1){
		cout<<(1 + b)*a<<endl;
	}
	else{
		cout<<a*b*c<<endl;
	}
	return 0;
}