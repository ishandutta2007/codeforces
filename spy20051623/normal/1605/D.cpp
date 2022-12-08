#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
int u[1 << 18], vis[N], ans[N];

void dfs(int p, int f) {
	for (int i: g[p]) {
		if (i != f) {
			vis[i] = vis[p] ^ 1;
			dfs(i, p);
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) ++cnt;
	}
	bool rev = false;
	if (cnt > n - cnt) {
		rev = true;
		cnt = n - cnt;
	}
	queue<int> q, qq;
	for (int i = 1; i <= n; ++i) {
		if (cnt >> u[i] & 1) q.push(i);
		else qq.push(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == rev) ans[i] = q.front(), q.pop();
		else ans[i] = qq.front(), qq.pop();
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < 1 << i; ++j) {
			u[(1 << i) + j] = i;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}