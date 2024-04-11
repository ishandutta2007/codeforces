#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			ans+=s[i]-'0';
		}
		for(int i = 0; i < n-1; ++i){
			ans+=(s[i] != '0');
		}
		cout << ans << '\n';
	}
}