#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	short counter;
	cin>>counter;
	counter = 0;
	cin>>s;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[i - 1]){
			counter++;
		}
	}
	cout<<counter<<endl;
	return 0;
}