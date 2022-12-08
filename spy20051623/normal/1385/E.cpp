#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 5;
vector<pii> g[N];
int in[N], vis[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) g[i].clear(), in[i] = vis[i] = 0;
	for (int i = 0; i < m; ++i) {
		int k, x, y;
		cin >> k >> x >> y;
		if (k) {
			g[x].emplace_back(y, 1);
			++in[y];
		} else {
			g[x].emplace_back(y, 0);
			g[y].emplace_back(x, 0);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (!in[i]) q.push(i);
	}
	vector<pii> v;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		vis[p] = 1;
		for (pii i: g[p]) {
			if (vis[i.first]) continue;
			v.emplace_back(p, i.first);
			if (i.second) --in[i.first], !in[i.first] ? q.push(i.first), 0 : 0;
		}
	}
	if (v.size() < m) cout << "NO\n";
	else {
		cout << "YES\n";
		for (pii i: v) cout << i.first << ' ' << i.second << '\n';
	}
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