#include<bits/stdc++.h>
 
using namespace std;


void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int suf = 0;
	for(int i = n-1; ~i; --i){
		if(s[i] == '0')suf++;
		else break;
	}
	int pref = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0')pref++;
		else break;
	}
	int ans = 0;
	if(suf < n && suf <= m){
		swap(s[n-suf-1],s.back());
		m-=suf;
	}
	if(pref < n-1 && pref <= m){
		swap(s[0],s[pref]);
	}
	for(int i = 0; i < n-1; ++i){
		ans+=(s[i]-'0')*10;
	}
	for(int i = 1; i < n; ++i){
		ans+=(s[i]-'0')*1;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}