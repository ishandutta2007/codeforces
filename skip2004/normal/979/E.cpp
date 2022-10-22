#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 53;
typedef long long ll;
const int mod = 1e9 + 7;
int dp[maxn][maxn][maxn];
// dijk : last i node 
// j is 1 and goto n is 1
// k is 0 and goto n is 1

int c[maxn];
int n, p;
int pw[maxn];
inline ll dfs(int i, int j, int k) {
	if(j < 0 || k < 0) return 0;
	if(i == n) {
		if(j == 0) return k == 1 && c[n] != 1;
		if(k == 0) return j == 1 && c[n] != 0;
		return 0;
	}
	int & ans = dp[i][j][k];
	if(~ans) return ans;
	ans = 0;
	rep(i0, 0, 1) if(i0 ^ c[i] ^ 1) {
		if(i0 ? k : j) {
			ans = (ans + (ll) dfs(i + 1, j, k) * pw[n - i - 1]) % mod;
			-- (i0 ? j : k);
			ans = (ans + (ll) dfs(i + 1, j, k) * pw[n - i - 1]) % mod;
			++ (i0 ? j : k);
		} else {
			-- (i0 ? j : k);
			ans = (ans + (ll) dfs(i + 1, j, k) * pw[n - i]) % mod;
			++ (i0 ? j : k);
		}
	}
	return ans;
}
int main() {
	memset(dp, -1, sizeof dp);
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> p;
	rep(i, 1, n) {
		cin >> c[i];
	}
	int ans = 0;
	*pw = 1;
	for(int i = 1;i <= n;++i) {
		pw[i] = pw[i - 1] * 2 % mod;
	}
	rep(i, 0, n) rep(j, 0, n) if(i + j <= n && (i + j) % 2 == p) {
		ans += dfs(1, i, j) - mod;
		ans += ans >> 31 & mod;
	}
	cout << ans << '\n';
}