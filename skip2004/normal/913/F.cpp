#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int mod = 998244353;
const int maxn = 2020;

typedef long long ll;
int n;
int a, b;
int p, q;
int powp[maxn], powq[maxn];
inline int pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}

int dp[maxn][maxn];
int f[maxn];
int g[maxn];
inline void fms(int & x, int y, int z) {
	x = (x + ll(mod - y) * z) % mod;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> a >> b;
	p = pow(b, mod - 2, a);
	q = mod + 1 - p;
	* powp = * powq = 1;
	for(int i = 1;i <= n;++i) {
		powp[i] = (ll) powp[i - 1] * p % mod;
		powq[i] = (ll) powq[i - 1] * q % mod;
	}
	for(int i = 0;i <= n;++i) {
		dp[i][0] = 1;
		for(int j = 1;j <= i;++j) {
			dp[i][j] = ((ll) dp[i - 1][j] * powq[j] + (ll) dp[i - 1][j - 1] * powp[i - j]) % mod;
		}
	}
	for(int i = 1;i <= n;++i) {
		f[i] = 1;
		for(int j = 1;j < i;++j) {
			fms(f[i], f[j], dp[i][j]);
		}
	}
	for(int i = 2;i <= n;++i) {
		ll s = (ll) f[i] * (i * (i - 1) / 2) % mod;
		for(int k = 1;k < i;++k) {
			ll mul = (ll) f[k] * dp[i][k] % mod;
			s += (g[i - k] + g[k] + k * (k - 1) / 2 + (i - k) * k) * mul % mod;
		}
		g[i] = pow(mod + 1 - f[i], mod - 2, s % mod);
	}
	cout << g[n] << '\n';
}