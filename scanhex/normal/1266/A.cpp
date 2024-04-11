#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		int ans=0;
		int c=0;
		for(auto x:s){
			ans+=x-'0';
			if((x-'0')%2==0)++c;
		}
		if(ans%3==0&&c>1&&count(s.begin(),s.end(),'0'))
			cout<<"red"<<'\n';
		else
			cout<<"cyan\n";
	}
	return 0;
}