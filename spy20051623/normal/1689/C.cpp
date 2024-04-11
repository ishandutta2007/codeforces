#include <bits/stdc++.h>

std::vector<std::vector<int>> g;
std::vector<int> sz;

int dfs(int p, int f) {
	for (int i = 0; i < g[p].size(); ++i) {
		if (g[p][i] == f) g[p].erase(g[p].begin() + i);
	}
	sz[p] = 1;
	int ld = 0, rd = 0, ls = 0, rs = 0;
	if (g[p].size() >= 1) ld = dfs(g[p][0], p), ls = sz[g[p][0]];
	if (g[p].size() >= 2) rd = dfs(g[p][1], p), rs = sz[g[p][1]];
	sz[p] += ls + rs;
	return std::max(0, std::max(ld + rs - 1, rd + ls - 1));
}

void solve() {
	int n;
	std::cin >> n;
	g = std::vector<std::vector<int>>(n + 1, std::vector<int>());
	sz = std::vector<int>(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	std::cout << dfs(1, 0) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
}