#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	short t , counter = 0;
	cin>>t;
	while(t > 0){
		cin>>s;
		if(s[1] == '-'){
			counter--;
		}
		else{
			counter++;
		}
		t--;
	}
	cout<<counter<<endl;
	return 0;
}