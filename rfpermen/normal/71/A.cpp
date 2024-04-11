#include<bits/stdc++.h>
using namespace std;

int n,sz;
string s;

int main(){
	cin>>n;
	while(n--){
		cin>>s;
		sz = s.size();
		if(sz<=10)cout<<s<<endl;
		else cout<<s[0]<<sz-2<<s[sz-1]<<endl;
	}
	return 0;
}