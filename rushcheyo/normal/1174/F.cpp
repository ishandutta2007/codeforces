#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, dep[N], size[N], son[N], bot[N], dx;
vector<int> g[N];

void dfs(int u, int fa) {
	size[u] = 1;
	for (int v : g[u])
		if (v != fa) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
			size[u] += size[v];
			if (size[v] > size[son[u]])
				son[u] = v;
		}
	if (son[u])
		bot[u] = bot[son[u]];
	else
		bot[u] = u;
}
int queryd(int u) {
	printf("d %d\n", u);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
int querys(int u) {
	printf("s %d\n", u);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
void out(int u) {
	printf("! %d\n", u);
	fflush(stdout);
}
int solve(int now) {
	if (dep[now] == dx)
		return now;
	if (dx - dep[now] == 1)
		return querys(now);
	int t = bot[now];
	int dlca = dep[t] + dx - queryd(t) >> 1;
	if (dep[now] == dlca)
		return solve(querys(now));
	while (dep[now] != dlca && dep[now] != dx)
		now = son[now];
	return solve(now);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	dx = queryd(1);
	out(solve(1));
	return 0;
}