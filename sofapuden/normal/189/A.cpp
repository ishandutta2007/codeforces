#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n, a, b, c; cin >> n >> a >> b >> c;
	int dp[8005];
	dp[0] = 1;
	for(int i = 0; i <= n; ++i){
		dp[i+a] = max(dp[i]+min(dp[i],1),dp[i+a]);
		dp[i+b] = max(dp[i]+min(dp[i],1),dp[i+b]);
		dp[i+c] = max(dp[i]+min(dp[i],1),dp[i+c]);
	}
	cout << dp[n]-1 << "\n";
}