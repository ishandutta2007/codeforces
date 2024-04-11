#include<iostream>
#include<string>

using namespace std;

int main(){
	short counter[3];
	for(int i = 0 ; i < 3 ; i++){
		counter[i] = 0;
	}
	string s;
	cin>>s;
	for(int i = 0 ; i < s.size() ; i += 2){
		if(s[i] == '1'){
			counter[1]++;
		}
		else if(s[i] == '2'){
			counter[2]++;
		}
		else if(s[i] == '3'){
			counter[0]++;
		}
	}
	while(counter[1] > 0){
		cout<<"1";
		if(counter[1] + counter[2] + counter[0] > 1){
			cout<<"+";
		}
		counter[1]--;
	}
	while(counter[2] > 0){
		cout<<"2";
		if(counter[1] + counter[2] + counter[0] > 1){
			cout<<"+";
		}
		counter[2]--;
	}
	while(counter[0] > 0){
		cout<<"3";
		if(counter[1] + counter[2] + counter[0] > 1){
			cout<<"+";
		}
		counter[0]--;
	}
	return 0;
}