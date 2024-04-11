#include<iostream>
#include<string>

using namespace std;

int main(){
	int counter = 0;
	string s;
	cin>>s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] < 96){
			counter--;
		}
		else{
			counter++;
		}
	}
	if(counter < 0){
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] > 96){
				s[i] -= 32;
			}
		}
	}
	else{
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] < 96){
				s[i] += 32;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}