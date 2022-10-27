#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 50 + 2;
int dp[N][N * N / 2];
int ret[N][N * N / 2];
int c[N][N], sum[N * N / 2], tmp[N * N / 2], fac[N*N/2];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, mod;
	cin >> n >> mod;
	fac[0] = 1;
	for (int i = 1; i < N; i ++) fac[i] = 1ll*fac[i-1]*i%mod;
	for (int i = 0; i < N; i ++) c[i][0] = 1;
	for (int i = 1; i < N; i ++) {
		for (int j = 1; j < N; j ++) {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
		}
	}

 	auto add = [&](int &x,int y) {
		x += y;
		if (x >= mod) x -= mod;
	};

	dp[0][0] = 1;
	ll ans = 0;
	for (int i = 0; i < n; i ++) {
		ll tmpans = 0;
		for (int k = i; k >= 0; k --) {
			memset(tmp,0,sizeof(tmp));
			for (int j = 0; j <= i * (i-1) / 2; j ++) add(tmp[j+k], dp[i][j]);
			
			int tot = 0;
			for (int j = 0; j <= i * (i+1) / 2; j ++) {
				tmpans = (tmpans + 1ll * tot * tmp[j] % mod) % mod;
				add(tot, dp[i+1][j]);
			}
			for (int j = 0; j <= i * (i-1) / 2; j ++) add(dp[i+1][j+k], dp[i][j]);
			
		}
		(ans += tmpans * c[n][i+1] % mod * fac[n-i-1] % mod) %= mod;
	}
	cout << ans << endl;
}