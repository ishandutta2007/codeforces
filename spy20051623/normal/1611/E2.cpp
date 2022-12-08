#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
vector<int> g[N];
int fa[N], dis[N], mk[N], ans;

int dfs(int p) {
	if (mk[p]) return dis[p] = 0;
	for (int i: g[p]) {
		if (i == fa[p]) continue;
		fa[i] = p;
		dis[p] = min(dis[p], dfs(i) + 1);
	}
	return dis[p];
}

bool dfs1(int p, int d) {
	if (p != 1 && g[p].size() == 1) return true;
	for (int i: g[p]) {
		if (i == fa[p]) continue;
		if (dis[i] <= d + 1) ++ans;
		else if (dfs1(i, d + 1)) return true;
	}
	return false;
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i) {
		g[i].clear();
		dis[i] = inf;
		fa[i] = 0;
		mk[i] = 0;
	}
	ans = 0;
	for (int i = 0; i < k; ++i) {
		int p;
		scanf("%d", &p);
		mk[p] = 1;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	if (dfs1(1, 0)) puts("-1");
	else printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}