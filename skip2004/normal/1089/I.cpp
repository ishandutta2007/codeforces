#include<bits/stdc++.h>
const int maxn = 1100;
typedef long long ll;
using std::cin;
using std::cout;

int t, mod, inv2;

inline void add(int & x, const int & y) {
	x += y - mod, x += x >> 31 & mod;
}
inline void sub(int & x, const int & y) {
	x -= y, x += x >> 31 & mod;
}
inline void fma(int & x, const int & y, const int & z) {
	x = (x + (ll) y * z) % mod;
}
inline void fms(int & x, const int & y, const int & z) {
	x = (x + (ll) (mod - y) * z) % mod;
}

int fac[maxn];
int g[maxn];
int dp[maxn][maxn];
int ans[maxn];
inline void init() {
	const int N = 400;
	*fac = 1;
	for(int i = 1;i <= N;++i) {
		fac[i] = (ll) fac[i - 1] * i % mod;
	}
	for(int i = 1;i <= N;++i) {
		g[i] = fac[i];
		for(int j = 1;j < i;++j) {
			fms(g[i], g[j], fac[i - j]);
		}
	}
	dp[0][0] = 1;
	for(int i = 1;i <= N;++i) {
		for(int j = 1;j <= i;++j) {
			for(int k = 1;k <= i;++k) {
				fma(dp[i][j], dp[i - k][j - 1], fac[k]);
			}
		}
	}
	for(int i = 1;i <= N;++i){
		ans[i] = fac[i];
		for(int j = 1;j < i;++j) fms(ans[i], g[j], 2 * fac[i - j]);
		for(int j = 3;j < i;++j) fms(ans[i], dp[i][j], ans[j]);
	}
	ans[2] = 2;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> t >> mod;
	init();
	for(int i = 0, x;i < t;++i) {
		cin >> x;
		cout << ans[x] << '\n';
	}
}