#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
const int inf = 0x3f3f3f3f;
vector<pair<int, int>> g[N];
int dis[N], col[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		g[y].emplace_back(x, z);
	}
	queue<int> q;
	q.push(n);
	memset(dis, 63, sizeof dis);
	memset(col, -1, sizeof col);
	dis[n] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (auto i: g[p]) {
			if (dis[i.first] != inf) continue;
			if (col[i.first] == -1) col[i.first] = !i.second;
			else if (col[i.first] == i.second) dis[i.first] = dis[p] + 1, q.push(i.first);
		}
	}
	if (dis[1] == inf) cout << -1 << '\n';
	else cout << dis[1] << '\n';
	for (int i = 1; i <= n; ++i) cout << (col[i] == -1 ? 0 : col[i]);
	cout << '\n';
	return 0;
}