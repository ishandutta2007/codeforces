#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	int counter = 0;
	cin>>s;
	for(int i = 0 ; i < s.size() ; i++){
		for(int j = i - 1 ; j >= 0 ; j--){
			if(s[i] == s[j]){
				break;
			}
			if(j == 0){
				counter++;
			}
		}
	}
	if(counter % 2 == 1){
		cout<<"CHAT WITH HER!"<<endl;
	}
	else{
		cout<<"IGNORE HIM!"<<endl;
	}
	return 0;
}