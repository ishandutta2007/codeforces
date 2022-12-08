#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 5;
vector<pii> b[N], g[N];
int a[2][N], vis[N], ans[N];

bool dfs1(int p, int x) {
	if (ans[p] != -1) return ans[p] == x;
	ans[p] = x;
	for (pii i: g[p]) {
		if (!dfs1(i.first, x ^ i.second)) return false;
	}
	return true;
}

long long dfs2(int p) {
	if (vis[p]) return 0;
	vis[p] = 1;
	long long x = 1000000 + ans[p];
	for (pii i: g[p]) x += dfs2(i.first);
	return x;
}

void dfs3(int p) {
	if (!vis[p]) return;
	vis[p] = 0;
	ans[p] ^= 1;
	for (pii i: g[p]) dfs3(i.first);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		b[i].clear();
		g[i].clear();
		vis[i] = 0;
		ans[i] = -1;
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			b[a[i][j]].emplace_back(j, i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (b[i].size() != 2) {
			cout << "-1\n";
			return;
		}
		if (b[i][0].first == b[i][1].first) continue;
		if (b[i][0].second == b[i][1].second) {
			g[b[i][0].first].emplace_back(b[i][1].first, 1);
			g[b[i][1].first].emplace_back(b[i][0].first, 1);
		} else {
			g[b[i][0].first].emplace_back(b[i][1].first, 0);
			g[b[i][1].first].emplace_back(b[i][0].first, 0);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == -1) {
			if (!dfs1(i, 0)) {
				cout << "-1\n";
				return;
			}
			long long w = dfs2(i);
			int x = w / 1000000, y = w % 1000000;
			if (y > x - y) dfs3(i);
		}
	}
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		c += ans[i];
	}
	cout << c << '\n';
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) cout << i << ' ';
	}
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}