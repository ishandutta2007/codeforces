#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> g[N], ring, line, gg[N];
int vis[N], co[N];
int n, m, k;
set<int> s;

int dfs(int p, int d, int f) {
	if (vis[p]) {
		if (s.find(p) != s.end()) {
			ring.push_back(p);
			return 1;
		} else return 0;
	}
	if (d > k) return 0;
	s.insert(p);
	vis[p] = 1;
	gg[f].push_back(p);
	for (int i: g[p]) {
		if (i == f) continue;
		int res = dfs(i, d + 1, p);
		if (res == 1) {
			if (p != ring[0]) {
				ring.push_back(p);
				return 1;
			} else return -1;
		}
		if (res == 2) {
			line.push_back(p);
			return 2;
		}
		if (res == -1) return -1;
	}
	if (d == k) {
		line.push_back(p);
		return 2;
	}
	s.erase(p);
	return 0;
}

void col(int p, int c) {
	co[p] = c;
	for (int i: gg[p]) col(i, c ^ 1);
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int fd = dfs(1, 1, 0);
	if (fd == 1 || fd == -1) {
		cout << "2\n";
		cout << ring.size() << '\n';
		for (int i: ring) cout << i << ' ';
		return;
	}
	if (fd == 2) {
		cout << "1\n";
		for (int i = 0; i < (k + 1) / 2; ++i) {
			cout << line[i + i] << ' ';
		}
		return;
	}
	memset(co, -1, sizeof co);
	col(1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (co[i] == 1) ++cnt;
	}
	if (cnt >= (k + 1) / 2) {
		cout << "1\n";
		int p = 1;
		for (int i = 0; i < (k + 1) / 2; ++i) {
			while (co[p] != 1) ++p;
			cout << p << ' ';
			++p;
		}
	} else {
		cout << "1\n";
		int p = 1;
		for (int i = 0; i < (k + 1) / 2; ++i) {
			while (co[p] != 0) ++p;
			cout << p << ' ';
			++p;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}