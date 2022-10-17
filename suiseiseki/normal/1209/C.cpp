#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,mi,ma,i,j;
	string s,ans="";
	cin>>n>>s;
	for(i=0; i<10; i++) {
		mi=0;
		ma=i;
		ans="";
		for(j=0; j<n; j++) {
			if(ma<=s[j]-'0') {
				ma=s[j]-'0';
				ans+='2';
			} else {
				ans+='1';
				if(mi>s[j]-'0' || s[j]-'0'>i)break;
				mi=s[j]-'0';
			}
		}
		if(j==n) {
			cout<<ans<<'\n';
			return;
		}
	}
	cout<<"-\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
}