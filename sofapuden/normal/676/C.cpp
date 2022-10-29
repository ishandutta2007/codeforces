#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0;
	for(char c = 'a'; c <= 'z'; ++c){
		int r = 0;
		int cn = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] != c){
				cn++;
			}
			while(cn > k){
				if(s[r] != c)cn--;
				r++;
			}
			ans = max(ans,i-r+1);
		}
	}
	cout << ans << '\n';
}