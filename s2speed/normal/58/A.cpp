#include<iostream>
#include<string>

using namespace std;

int main(){
	bool check = false;
	string s;
	cin>>s;
	for(int i = 0 ; i < s.size() ;){
		for(int j = i ; j < s.size() ; j++){
			if(s[j] == 'h'){
				i = j + 1;
				check = true;
				break;
			}
		}
		if(check == false){
			break;
		}
		else{
			check = false;
		}
		for(int j = i ; j < s.size() ; j++){
			if(s[j] == 'e'){
				i = j + 1;
				check = true;
				break;
			}
		}
		if(check == false){
			break;
		}
		else{
			check = false;
		}
		for(int j = i ; j < s.size() ; j++){
			if(s[j] == 'l'){
				i = j + 1;
				check = true;
				break;
			}
		}
		if(check == false){
			break;
		}
		else{
			check = false;
		}
		for(int j = i ; j < s.size() ; j++){
			if(s[j] == 'l'){
				i = j + 1;
				check = true;
				break;
			}
		}if(check == false){
			break;
		}
		else{
			check = false;
		}
		for(int j = i ; j < s.size() ; j++){
			if(s[j] == 'o'){
				check = true;
				break;
			}
		}
		break;
	}
	if(check == true){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}