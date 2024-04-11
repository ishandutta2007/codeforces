#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5+5;
const int M = 998244353;

void solve(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<vector<ll>> dp(2,vector<ll> (n+1,0));
	vector<ll> ans(n+1,0);
	dp[0][0] = 1;
	ll cn = 0;
	for(int i = k; cn <= n; ++i){
		dp[1].clear();
		dp[1].resize(n+1,0);
		for(int j = cn; j <= n-i; ++j){
			dp[1][j+i] += dp[0][j] + dp[1][j];
			dp[1][j+i] %= M;
		}
		for(int j = 0; j <= n; ++j){ans[j]+=dp[1][j];ans[j]%=M;}
		swap(dp[0],dp[1]);
		cn+=i;
	}
	for(int i = 1; i <= n; ++i)cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	solve();
}