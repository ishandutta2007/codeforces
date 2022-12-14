#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
int n, s, t, dep[N], fa[N], a[N], ta[N], b[N], p, u, v;
vector<int> g[N], av, bv;
bool mark[N];

void dfs(int u) {
	for (int v : g[u])
		if (v != fa[u])
			fa[v] = u, dep[v] = dep[u] + 1, dfs(v);
}
void get(int u) {
	if (u != p) av.push_back(ta[u]), bv.push_back(b[u]);
	mark[u] = true;
	bool flag = false;
	for (int v : g[u])
		if (!mark[v] && (v == p || ta[v] != b[v])) {
			flag = true;
			get(v);
			break;
		}
	if (!flag) v = u;
}
int dis(int u, int v) {
	int d = 0;
	while (u != v) ++d, dep[u] > dep[v] ? u = fa[u] : v = fa[v];
	return d;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), ta[i] = a[i], !a[i] ? s = i : 0;
	for (int i = 1; i <= n; ++i) scanf("%d", b + i), !b[i] ? t = i : 0;
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(t);
	int cnt = 0;
	for (int u = s; u != t; u = fa[u]) ++cnt, swap(ta[u], ta[fa[u]]);
	p = -1;
	for (int i = 1; i <= n; ++i)
		if (ta[i] != b[i]) {
			if (p == -1 || dep[i] < dep[p]) p = i;
			if (dep[i] >= dep[u]) u = i;
		}
	if (p == -1) return printf("0 %d\n", cnt), 0;
	p = fa[p];
	get(u);
	for (int i = 1; i <= n; ++i)
		if (mark[i] != (ta[i] != b[i] || i == p)) return puts("-1"), 0;
	int c = -1;
	for (int i = 0; i < bv.size(); ++i) if (bv[i] == av[0]) c = i;
	if (c == -1) return puts("-1"), 0;
	for (int i = 0; i < av.size(); ++i) if (av[i] != bv[(i + c) % av.size()]) return puts("-1"), 0;
	printf("%d %d %lld\n", min(u, v), max(u, v), min(dis(s, u) + 1 + (ll)(dis(u, v) + 1) * (c - 1) + dis(v, t), dis(s, v) + 1 + (dis(u, v) + 1) * ((ll)av.size() - c - 1) + dis(u, t)));
}