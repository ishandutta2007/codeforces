#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	cin>>s;
	if(s[0] > 96){
		s[0] -= 32;
	}
	cout<<s<<endl;
	return 0;
}