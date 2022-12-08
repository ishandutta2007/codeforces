#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int d[N], vis[N];

int dfs(int p, int x, int f) {
	if (p == x) return 0;
	for (int i: g[p]) {
		if (i == f) continue;
		int a = dfs(i, x, p);
		if (a != -1) return a + 1;
	}
	return -1;
}

void solve() {
	int n, a, b, da, db;
	cin >> n >> a >> b >> da >> db;
	for (int i = 1; i <= n; ++i) g[i].clear(), d[i] = vis[i] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		++d[x], ++d[y];
	}
	if (da * 2 >= db) {
		cout << "Alice\n";
		return;
	}
	if (dfs(a, b, 0) <= da) {
		cout << "Alice\n";
		return;
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 1) v.push_back(i);
	}
	int cnt = 0;
	while (v.size() > 1) {
		++cnt;
		vector<int> tv;
		for (int i: v) {
			vis[i] = 1;
			for (int j: g[i]) {
				if (vis[j]) continue;
				--d[j];
				if (d[j] == 1) tv.push_back(j);
			}
		}
		v = tv;
	}
	int sz = v.size() + cnt * 2;
	if (2 * da + 1 >= sz) cout << "Alice\n";
	else cout << "Bob\n";
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