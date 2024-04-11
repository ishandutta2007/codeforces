#include <bits/stdc++.h>

using i64 = long long;

const int N = 4005;

int fa[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		fa[i] = i;
	}
	std::vector<int> deg(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] - '0' && find(i) != find(j)) fa[find(i)] = find(j);
			if (a[i][j] - '0') ++deg[i];
		}
	}
	std::vector<std::vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		v[find(i)].push_back(i);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (!v[i].empty()) ++cnt;
	}
	if (cnt == 1) return std::cout << "0\n", void();
	for (int i = 0; i < n; ++i) {
		if (v[i].empty()) continue;
		int sz = v[i].size();
		if (sz == 1) return std::cout << "1\n" << i + 1 << '\n', void();
		for (int j = 0; j < sz; ++j) {
			for (int k = 0; k < j; ++k) {
				if (!(a[v[i][j]][v[i][k]] - '0')) {
					int mn = 0;
					for (int l = 0; l < sz; ++l) {
						if (deg[v[i][l]] < deg[v[i][mn]]) mn = l;
					}
					return std::cout << "1\n" << v[i][mn] + 1 << '\n', void();
				}
			}
		}
	}
	int x, y;
	for (int i = 0; i < n; ++i) {
		if (!v[i].empty()) {
			x = i;
			break;
		}
	}
	for (int i = x + 1; i < n; ++i) {
		if (!v[i].empty()) {
			y = i;
			break;
		}
	}
	if (cnt == 2) {
		std::vector<int> &vv = v[x].size() < v[y].size() ? v[x] : v[y];
		std::cout << vv.size() << '\n';
		for (int i: vv) std::cout << i + 1 << ' ';
		std::cout << '\n';
	} else {
		std::cout << "2\n" << v[x][0] + 1 << ' ' << v[y][0] + 1 << '\n';
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
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}