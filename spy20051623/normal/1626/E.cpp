#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
int a[N], c[N], ans[N];
vector<int> g[N], gg[N];

int dfs1(int p, int f) {
	if (a[p]) c[p] = 1;
	for (int i: g[p]) {
		if (i == f) continue;
		c[p] += dfs1(i, p);
		if (c[i] >= 2) gg[i].push_back(p);
	}
	return c[p];
}

void dfs2(int p, int f, int k) {
	if (k >= 2) gg[f].push_back(p);
	int s = a[p] + k;
	for (int i: g[p]) {
		if (i == f) continue;
		s += c[i];
	}
	for (int i: g[p]) {
		if (i == f) continue;
		dfs2(i, p, s - c[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!a[i]) continue;
		ans[i] = 1;
		for (int j: g[i]) ans[j] = 1;
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) q.push(i);
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i: gg[p]) {
			if (!ans[i]) {
				ans[i] = 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}