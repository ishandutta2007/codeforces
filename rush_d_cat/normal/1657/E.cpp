#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll c[252][252];
ll dp[252][252];
ll mpow(ll a, ll x) {
	if (x == 0) return 1;
	ll t = mpow(a,x>>1);
	if (x%2==0) return t*t%mod;
	return t*t%mod*a%mod;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	for (int i = 0; i < 252; i ++) c[i][0] = 1;
	for (int i = 1; i <= 250; i ++) {
		for (int j = 1; j <= i; j ++) 
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}

	int n, k;
	cin >> n >> k;
	n --;
	dp[0][0] = 1;
	for (int i = 0; i <= k; i ++) {
		for (int j = 0; j <= n; j ++) {
			if (dp[i][j] == 0) continue;
			//printf("%d %d %d\n", i, j, dp[i][j]);
			for (int x = 0; x <= n - j; x ++) {
				ll w1 = c[n-j][x];
				ll w2 = (j+x)*(j+x-1)/2 - j*(j-1)/2;
				w2 = mpow(k - i, w2);
				//if (i+1 == 2 && j+x == 2)
				//printf("%d %d , %d %d, add = %lld\n", i+1,j+x,i,j,dp[i][j] * w1 % mod * w2 % mod);
				dp[i+1][j+x] += dp[i][j] * w1 % mod * w2 % mod;
				dp[i+1][j+x] %= mod;
			}
		}
	}
	cout << dp[k][n] << "\n";
}
/*


w(1,u) <= w(u,v)
1 1 1
1 1 2
1 2 2
2 1 2
2 2 2


w[2], .... w[n]


f[i][j]

ways(u,v) = k - max(w[u], w[v]) + 1
*/