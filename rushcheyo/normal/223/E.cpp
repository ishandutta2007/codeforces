#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int n, m, sz[N];
bool vis[N];
vector<int> sum[N];
vector<pair<int, int>> g[N];
map<int, int> id[N];

struct point {
	int x, y;
} p[N];

point operator-(const point &a, const point &b) {
	return {a.x - b.x, a.y - b.y};
}
ll det(const point &a, const point &b) {
	return 1ll * a.x * b.y - 1ll * b.x * a.y;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	vis[u] = true;
	int *tmp;
	for (auto &e : g[u]) {
		int v = e.first;
		int &w = e.second;
		if (!vis[v]) {
			dfs(v, u);
			sz[u] += sz[v];
			w = -sz[v];
		} else if (v == fa)
			tmp = &w;
	}
	if (fa) *tmp = sz[u];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		g[u].emplace_back(v, 0), g[v].emplace_back(u, 0);
	}
	for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
	for (int i = 1; i <= n; ++i)
		sort(g[i].begin(), g[i].end(), [&](auto x, auto y) {
			point px = p[x.first] - p[i], py = p[y.first] - p[i];
			bool qx = px.x > 0 || (px.x == 0 && px.y > 0), qy = py.x > 0 || (py.x == 0 && py.y > 0);
			if (qx != qy) return qx;
			return det(px, py) > 0;
		});
	int x = 1;
	for (int i = 2; i <= n; ++i)
		if (p[i].x < p[x].x || (p[i].x == p[x].x && p[i].y < p[x].y)) x = i;
	dfs(x, 0);
	for (int i = 1; i <= n; ++i) {
		sum[i].resize(g[i].size());
		for (int j = 0; j < g[i].size(); ++j)
			sum[i][j] = (!j ? 0 : sum[i][j - 1]) + g[i][j].second, id[i][g[i][j].first] = j;
	}
	int len, q;
	cin >> q;
	while (q--) {
		cin >> len;
		vector<int> c(len);
		for (int i = 0; i < len; ++i) cin >> c[i];
		ll area = 0;
		for (int i = 0; i < len; ++i)
			area += det(p[c[i]], p[c[(i + 1) % len]]);
		if (area < 0) reverse(c.begin(), c.end());
		int res = 0;
		for (int i = 0; i < len; ++i) {
			int x = c[i], a = c[(i + 1) % len], b = c[(i + len - 1) % len];
			int l = id[x][a], r = id[x][b];
			if (l <= r) res += sum[x][r] - (!l ? 0 : sum[x][l - 1]);
			else res += sum[x].back() - (sum[x][l - 1] - sum[x][r]);
		}
		cout << abs(res) + len << '\n';
	}
}