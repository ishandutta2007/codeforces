#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 3610;
const int mod = 998244353;
typedef long long ll;

inline void reduce(int & x) { x += x >> 31 & mod; }
inline void add(int & x, int y) { x += y - mod, x += x >> 31 & mod; }

typedef int AI[maxn];
AI c[maxn], dp0[maxn], dp1[maxn];
int h, w, n;
int v0[maxn], v1[maxn];
int fac[maxn];
inline int dp(int N, int* v, AI* dp) {
	v[0] = 1, dp[0][0] = 1;
	int sum = 0;
	for(int i = 1;i <= N;++i) {
		for(int j = 0;j + j <= i;++j) {
			dp[i][j] = dp[i - 1][j];
			if(!v[i] && !v[i - 1] && j) add(dp[i][j], dp[i - 2][j - 1]);
		}
		sum += !v[i];
	}
	return sum;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	* fac = 1;
	for(int i = 1;i < maxn;++i) {
		fac[i] = (ll) fac[i - 1] * i % mod;
	}
	for(int i = 0;i < maxn;++i) {
		for(int j = c[i][0] = 1;j <= i;++j) {
			reduce(c[i][j] = c[i - 1][j] + c[i - 1][j - 1] - mod);
		}
	}
	cin >> h >> w >> n;
	for(int i = 0, r, c;i < n + n;++i) {
		cin >> r >> c;
		v0[r] = 1;
		v1[c] = 1;
	}
	const int s0 = dp(h, v0, dp0);
	const int s1 = dp(w, v1, dp1);
	int ans = 0;
	for(int i = 0;i + i <= s0;++i) {
		for(int j = 0;j + j <= s1;++j) {
			const int v = (ll) dp0[h][i] * dp1[w][j] % mod;
			ans = (ans + (ll) v * fac[i] % mod * fac[j] % mod * c[s0 - i - i][j] % mod * c[s1 - j - j][i]) % mod;
		}
	}
	cout << ans << '\n';
}