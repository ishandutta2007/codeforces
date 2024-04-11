#include<bits/stdc++.h>
const int maxn = 4040;
typedef long long ll;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
int n;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2;i <= n;++i) {
		const int * a = dp[i - 1];
		int	* b = dp[i];
		for(int j = 0;j <= n;++j) {
			ll x = 0;
			for(int k = 0;k < j;++k) x += (ll) a[k] * a[j - k - 1] % mod;
			for(int k = 0;k <= j;++k) {
				x += (ll) a[k] * a[j - k] % mod * (j + j + 1);
				x += 2ll * a[k] * a[j - k + 1] % mod * k * (j - k + 1);
			}
			for(int k = 0;k <= j + 1;++k) {
				x += 2ll * a[k] * a[j - k + 1] % mod * k * (k - 1);
			}
			b[j] = x % mod;
		}
	}
	std::cout << dp[n][1] << '\n';
}