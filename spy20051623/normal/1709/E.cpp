#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 5;
int a[N], m[N];
std::vector<int> g[N];
std::set<int> dp[N];
int cnt;

void dfs(int p, int f) {
	int c = 0;
	for (int i: g[p]) {
		if (i == f) continue;
		++c;
		dfs(i, p);
	}
	if (c == 0) {
		dp[p].clear();
		m[p] = 0;
		dp[p].insert(a[p]);
		return;
	}
	int mx = 0;
	for (int i: g[p]) {
		if (i == f) continue;
		if (dp[i].size() > dp[mx].size()) mx = i;
	}
	if (dp[mx].count(a[p] ^ m[mx])) {
		m[p] = 0;
		dp[p].clear();
		++cnt;
		return;
	}
	std::swap(dp[p], dp[mx]);
	m[p] = a[p] ^ m[mx];
	dp[p].insert(m[mx]);
	for (int i: g[p]) {
		if (i == f || i == mx) continue;
		for (int j: dp[i]) {
			int x = j ^ m[i] ^ m[mx];
			if (dp[p].count(x ^ a[p])) {
				m[p] = 0;
				dp[p].clear();
				++cnt;
				return;
			}
		}
		for (int j: dp[i]) {
			int x = j ^ m[i] ^ m[mx];
			dp[p].insert(x);
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		g[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	std::cout << cnt << '\n';
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