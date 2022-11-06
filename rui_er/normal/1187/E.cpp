//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;

int n, depth[N] = {-1}, sz[N], dp[N], ans;
struct Edge {
	int v, nxt;
	Edge() {}
	Edge(int a, int b) : v(a), nxt(b) {}
}e[N<<1];
int ne, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]);
	h[u] = ne;
	e[++ne] = Edge(u, h[v]);
	h[v] = ne;
}

void dfs(int u, int f) {
	depth[u] = depth[f] + 1;
	sz[u] = 1;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
	ans += sz[u];
}
void dfs2(int u, int f) {
	ans = max(ans, dp[u]);
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f) {
			dp[v] = dp[u] + sz[1] - 2 * sz[v];
			dfs2(v, u);
		}
	}
}

signed main() {
	scanf("%lld", &n);
	for(int i=1;i<n;i++) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		add(u, v);
	}
	dfs(1, 0);
	dp[1] = ans;
	dfs2(1, 0);
	printf("%lld\n", ans);
	return 0;
}