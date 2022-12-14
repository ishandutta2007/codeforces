// In the name of God

#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5, oo = 1000 * 1000 * 1000 + 7;

int par[N], seg[N << 2], tree_pos[N], n, m, q;
multiset<int> best[N];
int query(int i, int j, int v = 1, int b = 0, int e = 2 * n) {
	if (i >= e || b >= j)
		return oo;
	if (i <= b && e <= j)
		return seg[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return min(query(i, j, l, b, m), query(i, j, r, m, e));
}

void update(int pos, int x, int v = 1, int b = 0, int e = 2 * n) {
	if (b + 1 == e) {
		seg[v] = x;
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (pos < m)
		update(pos, x, l, b, m);
	else
		update(pos, x, r, m, e);
	seg[v] = min(seg[l], seg[r]);
}
int h[N], sz[N], heavy[N], head[N];
vector<int> g[N];
void dfs_hld(int v, int p = -1) {
	par[v] = p;
	sz[v] = 1;
	int maxsz = 0;
	for (int u : g[v]) if (u != p) {
		h[u] = h[v] + 1;
		dfs_hld(u, v);
		sz[v] += sz[u];
		if (maxsz < sz[u])
			heavy[v] = u, maxsz = sz[u];
	}

}

void build_hld() {
	memset(h, 0, sizeof h);
	memset(heavy, -1, sizeof heavy);
	memset(par, -1, sizeof par);
//	for (int v = 0; v < n; ++v)
//		if (par[v] == -1)
	dfs_hld(0);
	int used = 0;
	for (int v = 0; v < 2 * n; ++v) if ((int) g[v].size())
		if (par[v] == -1 || heavy[par[v]] != v)
			for (int u = v; u != -1; u = heavy[u])
				tree_pos[u] = used++, head[u] = v;
}

int val[N], low[N], s[N], t[N], mark[N], cc[N], cut_vertex[N];
vector<int> adj[N];
int get_path(int u, int v) {
	int res = oo;
	while (head[u] != head[v]) {
		if (h[head[u]] > h[head[v]])
			swap(u, v);
		res = min(res, query(tree_pos[head[v]], tree_pos[v] + 1));
		v = par[head[v]];
	}
	if (h[v] < h[u])
		swap(u, v);
	res = min(res, query(tree_pos[u], tree_pos[v] + 1));
	if (par[u] != -1 && u >= n)
		res = min(res, *(best[par[u]].begin()));
	return res;
}

vector<int> comp[N];
stack<int> st;
int dfs_bcc(int v, int p = -1) {
	if (mark[v]++) {
		return h[v];
	}
	h[v] = (p == -1? 0: h[p] + 1);
	low[v] = h[v];
	st.push(v);
	for (int u : adj[v])
		low[v] = min(low[v], dfs_bcc(u, v));
	if (h[v] - 1 == low[v]) {
		while (st.top() != v) {
			int u = st.top(); st.pop();
			comp[u].push_back(v + n);
		}
		comp[v].push_back(v + n);
		st.pop();
		comp[p].push_back(v + n);
	}
	return low[v];
}

void upd(int v, int last, int now) {
	if (v == -1)
		return;
	int l = (best[v].size()? *(best[v].begin()): oo);
	if (last != -1)
		best[v].erase(best[v].find(last));
	best[v].insert(now);
	int w = *(best[v].begin());
	if (l != w)
		update(tree_pos[v], w);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> q;	
	for (int v = 0; v < n; ++v)
		cin >> val[v];
	for (int e = 0; e < m; ++e) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_bcc(0);
	for (int v = 0; v < n; ++v) {
		for (int c : comp[v]) {
			g[c].push_back(v), g[v].push_back(c);
			//cout << v << ' ' << c << endl;
		}
	}
	build_hld();
	for (int v = 0; v < n; ++v) {
		upd(v, -1, val[v]);
		upd(par[v], -1, val[v]);
	}	
	while (q--) {
		char c;
		cin >> c;
		if (c == 'C') {
			int v, w;
			cin >> v >> w;
			v--;
			upd(v, val[v], w);
			upd(par[v], val[v], w);
			val[v] = w;
		} else {
			int u, v;
			cin >> u >> v;
			--u, --v;
			cout << get_path(u, v) << '\n';
		}
	}
}