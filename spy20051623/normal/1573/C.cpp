#include <bits/stdc++.h>

using namespace std;

int deg[200005];
vector<int> g[200005];
int vis[200005];
int dep[200005];

int dfs(int p) {
	if (dep[p] != -1) return dep[p];
	dep[p] = 1;
	for (int i: g[p]) {
		if (i < p) dep[p] = max(dep[p], dfs(i) + 1);
		else dep[p] = max(dep[p], dfs(i));
	}
	return dep[p];
}

void solve() {
	int n;
	scanf("%d", &n);
	memset(vis, 0, (n + 5) << 2);
	memset(dep, -1, (n + 5) << 2);
	for (int i = 1; i <= n; ++i) g[i].clear();
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &deg[i]);
		for (int j = 0; j < deg[i]; ++j) {
			int p;
			scanf("%d", &p);
			g[p].push_back(i);
		}
		if (!deg[i]) {
			vis[i] = -1;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i: g[p]) {
			--deg[i];
			if (!deg[i]) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			printf("-1\n");
			return;
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dfs(i));
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}