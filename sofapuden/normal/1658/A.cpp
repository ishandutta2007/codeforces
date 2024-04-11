#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < n-1; ++i){
		if(s[i] == '0' && s[i+1] == '0')ans+=2;
	}
	for(int i = 0; i < n-2; ++i){
		if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0')ans++;
	}
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}