#include <bits/stdc++.h>
using namespace std;

const int N = 100005, pw[6] = {1, 10, 100, 1000, 10000, 100000}, P = 1000000007;
int n, m, a[N], b[N], len[N], dis[N], f[N], tot, ch[6 * N][10], fa[6 * N][20], dep[6 * N], num[6 * N];
vector<int> g[N], g2[N];

int kth(int u, int k) {
	for (int i = 19; i >= 0; --i)
		if (k >> i & 1) u = fa[u][i];
	return u;
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 19; i >= 0; --i)
		if (fa[u][i] && dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; --i)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
bool cmp(int u, int v) {
	if (u == v) return false;
	int t = lca(u, v);
	int ux = kth(u, dep[u] - dep[t] - 1), vx = kth(v, dep[v] - dep[t] - 1), d1, d2;
	for (d1 = 0; d1 < 10; ++d1)
		if (ch[t][d1] == ux) break;
	for (d2 = 0; d2 < 10; ++d2)
		if (ch[t][d2] == vx) break;
	return d1 < d2;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		len[i] = len[i / 10] + 1;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", a + i, b + i);
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	fill(dis + 1, dis + 1 + n, n * len[m]);
	priority_queue<pair<int, int>> q;
	q.emplace(dis[1] = 0, 1);
	while (!q.empty()) {
		auto t = q.top(); q.pop();
		if (dis[t.second] != -t.first) continue;
		for (int e : g[t.second]) {
			int v = a[e] + b[e] - t.second, w = len[e];
			if (dis[v] > -t.first + w)
				q.emplace(-(dis[v] = -t.first + w), v);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (dis[a[i]] > dis[b[i]]) swap(a[i], b[i]);
		if (dis[a[i]] + len[i] == dis[b[i]])
			g2[a[i]].push_back(i);
	}
	static int id[N];
	for (int i = 1; i <= n; ++i) id[i] = i;
	sort(id + 1, id + 1 + n, [](int x, int y) { return dis[x] < dis[y]; });
	f[1] = tot = 1;
	for (int i = 1; i < n; ++i)
		for (int e : g2[id[i]]) {
			int u = a[e], v = b[e], x = f[u], y = f[u];
			for (int j = len[e] - 1; j >= 0; --j) {
				if (!ch[y][e / pw[j] % 10]) {
					ch[y][e / pw[j] % 10] = ++tot;
					dep[tot] = dep[y] + 1;
					fa[tot][0] = y;
					for (int j = 1; j <= 19; ++j)
						fa[tot][j] = fa[fa[tot][j - 1]][j - 1];
					num[tot] = (10LL * num[y] + e / pw[j] % 10) % P;
				}
				y = ch[y][e / pw[j] % 10];
			}
			if (!f[v]) f[v] = y;
			else if (cmp(y, f[v])) f[v] = y;
		}
	for (int i = 2; i <= n; ++i)
		printf("%d\n", num[f[i]]);
}