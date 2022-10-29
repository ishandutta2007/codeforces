#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> v(n);
		for(auto &x : v)cin >> x;
		int ans = 0;
		for(char c = 'a'; c <= 'e'; ++c){
			vector<int> z;
			for(auto s : v){
				int cn = 0;
				for(char x : s){
					if(x == c)cn++;
					else cn--;
				}
				z.push_back(cn);
			}
			sort(z.rbegin(),z.rend());
			int cn = 0;
			for(int i = 0; i < n; ++i){
				cn+=z[i];
				if(cn <= 0){
					ans = max(ans,i);
					break;
				}
			}
			if(cn > 0)ans = n;
		}
		cout << ans << '\n';
	}

}