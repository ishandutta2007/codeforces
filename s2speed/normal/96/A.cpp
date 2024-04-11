#include<iostream>
#include<string>

using namespace std;

int main(){
	int counter = 1;
	string s;
	cin>>s;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[i - 1]){
			counter++;
			if(counter == 7){
				break;
			}	
		}
		else{
			counter = 1;
		}
	}
	if(counter == 7){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}