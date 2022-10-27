#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int t, n, m, p[N], h[N], sz[N], cnt[N], flag = true;
vector<int> g[N];
void dfs(int u, int f) {
	//printf("dfs %d %d\n", u, f);
	sz[u] = p[u];
	for (auto v: g[u]) {
		if (v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}

	if (h[u] > sz[u]) flag = false;
	if ((h[u] + sz[u])%2) flag = false;
	cnt[u] = (sz[u] + h[u]) / 2;
	//printf("cnt[%d]=%d\n", u,cnt[u]);
	int sum = 0;
	for (auto v: g[u]) {
		if (v == f) continue;
		sum += cnt[v];
	}
	if (sum > cnt[u]) flag = false;
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			g[i].clear();
		}
		flag = true;
		for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
		for (int i = 1; i < n; i ++) {
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,1);
		printf("%s\n", flag?"YES":"NO");
	}	
}
/*
x1 + x2 = sz[u]
x1 - x2 = h
*/