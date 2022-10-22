#include<iostream>
#include<string>

using namespace std;

int main(){
	int t;
	cin>>t;
	string s;
	while(t > 0){
		cin>>s;
		if(s.size() > 10){
			cout<<s[0]<<s.size() - 2<<s[s.size() - 1]<<endl;
		}
		else{
			cout<<s<<endl;
		}
		t--;
	}
	return 0;
}