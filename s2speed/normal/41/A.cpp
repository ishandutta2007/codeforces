#include<iostream>
#include<string>

using namespace std;

int main(){
	string s , a;
	cin>>s>>a;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] != a[a.size() - i - 1]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}