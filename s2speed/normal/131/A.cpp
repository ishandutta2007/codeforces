#include<iostream>
#include<string>

using namespace std;

int main(){
	bool check = false;
	char helper;
	string s;
	cin>>s;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] > 96){
			cout<<s<<endl;
			return 0;
		}
	}
	if(s[0] > 90){
		check = true;
	}
	for(int i = 0 ; i < s.size() ; i++){
		if(i == 0 && check == true){
			helper = s[i] - 32;
		}
		else{
			helper = s[i] + 32;
		}
		cout<<helper;
	}
	return 0;
}