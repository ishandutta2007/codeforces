#include<bits/stdc++.h>
typedef long long ll;
const int maxk = 100100;
const int maxn = 2100;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(; b; b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
int n, m, a, b, k;
int fac[maxk], ifac[maxk], inv[maxk];
int val[maxn];
int dp[maxn][maxn];
int sum0[maxn];
int sum1[maxn];
int pre[maxn][maxn];
int suf[maxn][maxn];
int f[maxn], g[maxn];
int f1[maxn], g1[maxn];
inline void reduce(int& x) { x += x >> 31 & mod; }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> a >> b >> k;
	a = pow(b, mod - 2, a);
	fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
	for(int i = 2;i < maxk;++i) {
		inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (ll) fac[i - 1] * i % mod;
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
	}
	for(int i = 0;i <= m && i <= k;++i) val[i] = (ll) fac[k] * ifac[i] % mod * ifac[k - i] % mod * pow(a, i) % mod * pow(mod + 1 - a, k - i) % mod;
	for(int i = 1;i <= m;++i) for(int j = i;j <= m;++j) {
		dp[i][j] = (ll) val[i - 1] * val[m - j] % mod;
		f[j] = (f[j] + dp[i][j]) % mod;
		g[i] = (g[i] + dp[i][j]) % mod;
	}
	for(int i = 1;i <= m;++i) {
		for(int j = 1;j <= m;++j) reduce(sum0[j] += dp[i][j] - mod);
		for(int j = 1;j <= m;++j) reduce(sum1[i] += dp[i][j] - mod);
	}
	for(int i = 1;i <= m;++i) reduce(f[i] += f[i - 1] - mod);
	for(int i = m;i >= 1;--i) reduce(g[i] += g[i + 1] - mod);
	for(int i = 1;i < n;++i) {
		ll all = 0ll + f[m] + mod + mod;
		for(int k = 1, sum = 0;k <= m;++k){
			f1[k] = (all - g[k + 1]) * sum0[k] % mod;
			sum = (sum + (ll) (mod - f[k - 1]) * val[k - 1]) % mod;
			f1[k] = (f1[k] + (ll) sum * val[m - k]) % mod;
		}
		for(int j = m, sum = 0;j >= 1;--j){
			g1[j] = (all - f[j - 1]) * sum1[j] % mod;
			sum = (sum + (ll)(mod - g[j + 1]) * val[m - j]) % mod; 
			g1[j] = (g1[j] + (ll) val[j - 1] * sum) % mod;
		}
		for(int i = 1;i <= m;++i) f[i] = f1[i], g[i] = g1[i], f1[i] = g1[i] = 0;
		for(int i = 1;i <= m;++i) reduce(f[i] += f[i - 1] - mod);
		for(int i = m;i >= 1;--i) reduce(g[i] += g[i + 1] - mod);
	}
	std::cout << f[m] << '\n';
}