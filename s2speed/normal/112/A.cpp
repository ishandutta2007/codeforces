#include<iostream>
#include<string>

using namespace std;

string a , b;

string ch(string s){
	string h;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] < 97){
			h += s[i] + 32;
		} else {
			h += s[i];
		}
	}
	return h;
}

int main(){
	int checker[2] , counter = 0;
	cin>>a>>b;
	a = ch(a);
	b = ch(b);
	if(a > b){
		cout<<1<<endl;
	} else if(a < b){
		cout<<-1<<endl;
	} else {
		cout<<0<<endl;
	}
	return 0;
}