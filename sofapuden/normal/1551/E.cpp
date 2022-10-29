#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MX = 1e9;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<vector<ll>> dp(n+1, vector<ll> (n+1,0));
		vector<int> v(n);
		ll ans = MX;
		for(auto &x : v) cin >> x;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= i; ++j){
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
				dp[i][j] += v[i] == (j+1);
				dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
				if(dp[i][j] >= k){
					ans = min(ans, (ll)i-j);
				}
			}
		}
		cout << (ans == MX ? -1 : ans) << '\n';
	}
}