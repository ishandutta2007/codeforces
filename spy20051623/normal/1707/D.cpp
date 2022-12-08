#include <bits/stdc++.h>

using i64 = long long;
const int N = 2005;
int mod;
i64 C[N][N], dp[N][N], s[N][N], pre[N][N], suf[N][N], id[N], ans[N];
std::vector<int> g[N];

int n;

void dfs(int p, int f) {
	int cnt = 0;
	for (int i: g[p]) {
		if (i == f) continue;
		dfs(i, p);
	}
	for (int i: g[p]) {
		if (i == f) continue;
		++cnt;
		id[cnt] = i;
		for (int j = 0; j < n; ++j) {
			pre[cnt][j] = suf[cnt][j] = s[i][j];
		}
	}
	for (int i = 1; i < n; ++i) {
		pre[0][i] = suf[cnt + 1][i] = 1;
		for (int j = 1; j <= cnt; ++j) pre[j][i] = pre[j][i] * pre[j - 1][i] % mod;
		for (int j = cnt; j >= 1; --j) suf[j][i] = suf[j][i] * suf[j + 1][i] % mod;
		dp[p][i] = pre[cnt][i];
	}
	if (p == 1) return;
	for (int i = 1; i <= cnt; ++i) {
		i64 sum = 0;
		for (int j = 1; j < n; ++j) {
			dp[p][j] = (dp[p][j] + sum * dp[id[i]][j]) % mod;
			sum = (sum + pre[i - 1][j] * suf[i + 1][j]) % mod;
		}
	}
	for (int i = 1; i < n; ++i) {
		s[p][i] = (s[p][i - 1] + dp[p][i]) % mod;
	}
}

void solve() {
	std::cin >> n >> mod;
	C[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i < n; ++i) {
		ans[i] = dp[1][i];
		for (int j = 1; j < i; ++j) {
			ans[i] = (ans[i] - C[i][j] * ans[j]) % mod;
		}
		ans[i] = (ans[i] + mod) % mod;
	}
	for (int i = 1; i < n; ++i) {
		std::cout << ans[i] << ' ';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}