#include<bits/stdc++.h>
const int N = 105;
const int mod = 998244353;
using std::cin;
using std::cout;
char s[N];
int len;
int a[N];
int m0[N];
int m1[N];
int mul0, mul1, full;
int dp[2][2][N][1 << 4][1 << 4][9][9];
inline void reduce(int & x) {
	x += x >> 31 & mod;
}
inline int dfs(int now, int h0, int h1, int s0, int s1, int p0, int p1) {
	if(now == len) {
		return p0 == 0 && p1 == 0 && (s0 & s1);
	}
	if(s0 & s1) s0 = s1 = full;
	int & ans = dp[h0][h1][now][s0][s1][p0][p1];
	if(~ans) return ans;
	ans = 0;
	for(int i = 0;i < (h0 ? a[now] + 1 : 10);++i) {
		for(int k = 0;k < 9;++k) if((i * mul0 + k) / 10 == p0) {
			for(int j = 0;j < (h1 ? a[now] + 1 : 10);++j) {
				int l = (i * mul0 + k + (10 - j) * mul1) % 10;
				if(l < 9 && (j * mul1 + l) / 10 == p1) {
					int S0 = m0[i] >= 0 ? s0 | 1 << m0[i] : s0;
					int S1 = m1[j] >= 0 ? s1 | 1 << m1[j] : s1;
					reduce(ans += dfs(now + 1, h0 && i == a[now], h1 && j == a[now], S0, S1, k, l) - mod);
				}
			}
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> s, len = strlen(s);
	int ans = 0;
	for(int i = 0;i < len;++i) {
		a[i] = s[i] - '0';
		ans = (ans * 10ll + a[i]) % mod;
	}
	for(int x = 1;x <= 9;++x) {
		for(int y = x == 1 ? 2 : 1;y <= 9;++y) if(std::__gcd(x, y) == 1) {
			for(int i = 0;i < 10;++i) {
				m0[i] = m1[i] = -1;
			}
			const int t = 9 / std::max(x, y);
			for(int i = 1;i <= t;++i) {
				m0[i * x] = i - 1;
				m1[i * y] = i - 1;
			}
			memset(dp, -1, sizeof dp);
			full = (1 << t) - 1;
			mul0 = y;
			mul1 = x;
			for(int i = 0;i < 9;++i)
			reduce(ans += dfs(0, 1, 1, 0, 0, i, i) - mod);
		}
	}
	cout << ans << '\n';
}