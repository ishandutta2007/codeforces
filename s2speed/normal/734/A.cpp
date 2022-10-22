#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int counter;
	cin>>counter;
	counter = 0;
	cin>>s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'A'){
			counter++;
		}
		else{
			counter--;
		}
	}
	if(counter > 0){
		cout<<"Anton"<<endl;
	}
	else if(counter == 0){
		cout<<"Friendship"<<endl;
	}
	else{
		cout<<"Danik"<<endl;
	}
	return 0;
}