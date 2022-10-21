#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

bool cons(char a){
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
		return false;
	}
	return true;
}

int main(){
	string str;
	getline(cin,str);
	int pos = 0;
	while(str.length() > 2){
		if(cons(str[pos]) && cons(str[pos+1]) && cons(str[pos+2]) && !(str[pos] == str[pos+1] && str[pos+1] == str[pos+2])){
			cout<<str.substr(0,pos+2)<<" ";
			str.erase(0,pos+2);
			pos = 0;
		}
		else{
			pos++;
		}
	}
	cout<<str;
}