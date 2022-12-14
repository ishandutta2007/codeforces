#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, m, op[N][3], tot, fa[N], now[N], in[N], out[N], dfs_clock, tag[N << 2], size[N];
long long t[N], ans[N];
vector<int> g[N];
vector<pair<int, int>> qry[N];

void update(int x, int y) {
	for (; x <= dfs_clock; x += x & -x)
		t[x] += y;
}
long long query(int x) {
	long long s = 0;
	for (; x; x &= x - 1) s += t[x];
	return s;
}

void dfs(int u) {
	in[u] = ++dfs_clock;
	size[u] = u <= n;
	for (int v : g[u])
		dfs(v), size[u] += size[v];
	out[u] = dfs_clock;
}

void pushdown(int u) {
	if (tag[u]) {
		tag[u << 1] = tag[u << 1 | 1] = tag[u];
		tag[u] = 0;
	}
}
void update(int u, int l, int r, int ql, int qr, int v) {
	if (l >= ql && r <= qr) {
		tag[u] = v;
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (ql <= mid) update(u << 1, l, mid, ql, qr, v);
	if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, v);
}
int query(int u, int l, int r, int pos) {
	if (l == r) return tag[u];
	int mid = l + r >> 1;
	pushdown(u);
	if (pos <= mid) return query(u << 1, l, mid, pos);
	return query(u << 1 | 1, mid + 1, r, pos);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		char s[5];
		scanf("%s", s);
		if (s[0] == 'U') {
			op[i][0] = 0;
			scanf("%d%d", op[i] + 1, op[i] + 2);
		} else if (s[0] == 'M') {
			op[i][0] = 1;
			scanf("%d%d", op[i] + 1, op[i] + 2);
		} else if (s[0] == 'A') {
			op[i][0] = 2;
			scanf("%d", op[i] + 1);
		} else if (s[0] == 'Z') {
			op[i][0] = 3;
			scanf("%d", op[i] + 1);
		} else {
			op[i][0] = 4;
			scanf("%d", op[i] + 1);
		}
	}
	for (int i = 1; i <= n; ++i)
		now[i] = i;
	tot = n;
	for (int i = 1; i <= m; ++i)
		if (op[i][0] == 1)
			fa[now[op[i][1]]] = fa[now[op[i][2]]] = ++tot, now[op[i][1]] = tot;
	for (int i = 1; i <= tot; ++i)
		g[fa[i]].push_back(i);
	dfs(0);
	for (int i = 1; i <= n; ++i)
		now[i] = i;
	for (int i = 1; i <= m; ++i)
		if (op[i][0] == 1)
			now[op[i][1]] = fa[now[op[i][1]]];
		else if (op[i][0] == 3)
			update(1, 1, dfs_clock, in[now[op[i][1]]], out[now[op[i][1]]], i);
		else if (op[i][0] == 4) {
			qry[i].emplace_back(i, op[i][1]);
			qry[query(1, 1, dfs_clock, in[op[i][1]])].emplace_back(i, -op[i][1]);
		}
	for (int i = 0; i <= tot; ++i)
		g[i].clear(), fa[i] = 0;
	for (int i = 1; i <= n; ++i)
		now[i] = i;
	tot = n;
	for (int i = 1; i <= m; ++i)
		if (op[i][0] == 0)
			fa[now[op[i][1]]] = fa[now[op[i][2]]] = ++tot, now[op[i][1]] = tot;
	for (int i = 1; i <= tot; ++i)
		g[fa[i]].push_back(i);
	dfs_clock = 0;
	dfs(0);
	for (int i = 1; i <= n; ++i)
		now[i] = i;
	for (int i = 1; i <= m; ++i) {
		if (op[i][0] == 0)
			now[op[i][1]] = fa[now[op[i][1]]];
		else if (op[i][0] == 2)
			update(in[now[op[i][1]]], size[now[op[i][1]]]), update(out[now[op[i][1]]] + 1, -size[now[op[i][1]]]);
		for (const auto &x : qry[i])
			ans[x.first] += (x.second > 0 ? 1 : -1) * query(in[abs(x.second)]);
	}
	for (int i = 1; i <= m; ++i)
		if (op[i][0] == 4)
			printf("%lld\n", ans[i]);
	return 0;
}