#include<iostream>
#include<string>

using namespace std;

int main(){
	string s , a;
	cin>>s;
	for(int i = 0 ; i < 5 ; i++){
		cin>>a;
		if(a[0] == s[0] || s[1] == a[1]){
			cout<<"YES"<<endl;
			break;
		}
		if(i == 4){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}