#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

bool is_pali(string s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	return s==s1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n=sz(s);
	int cnt=count(s.begin(),s.end(),s[0]);
	if(cnt==n||cnt==n-1&&n%2==1){
		 cout<<"Impossible\n";
		 return 0;
	}
	bool ok=false;
	for(int i=0;i<n;++i){
		string a=s.substr(0,i),b=s.substr(i);
		string t=b+a;
		if(t!=s&&is_pali(t))ok=true;
	}
	if(ok)cout<<1<<'\n';
	else
	cout<<2<<'\n';
	return 0;
}