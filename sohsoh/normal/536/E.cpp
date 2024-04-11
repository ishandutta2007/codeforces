#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

struct node {
	int val, len, lb, rb;
	node(int val = 0, int t = 0): val(val), len(1), lb(t), rb(t) {}
};

int f[MAXN], par[MAXN][LOG], n, q, head[MAXN], id[MAXN], 
    H[MAXN], t, sz[MAXN], hv[MAXN], ans[MAXN];
vector<int> adj[MAXN];
vector<pair<pll, pll>> Q; 
node sg[MAXN];

inline node merge(node a, node b) {
	if (a.lb < 0) return b;
	if (b.lb < 0) return a;

	node ans = node();
	ans.val = a.val + b.val - f[a.rb] - f[b.lb] + f[a.rb + b.lb];
	ans.len = a.len + b.len;

	ans.lb = (a.lb < a.len ? a.lb : a.lb + b.lb);
	ans.rb = (b.rb < b.len ? b.rb : b.rb + a.rb);
	return ans;
}

void add(int ind, int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(f[1], 1);
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) add(ind, l, mid, v << 1);
		else add(ind, mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return node(0, -1);
	if (ql <= l && qr >= r) return sg[v];
	
	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1), 
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

void dfs1(int v, int p) {
	par[v][0] = p;
	sz[v] = 1;
	head[v] = v;
	H[v] = H[p] + 1;

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs1(u, v);
		sz[v] += sz[u];
		hv[v] = (sz[u] > sz[hv[v]] ? u : hv[v]);
	}
}

void dfs2(int v, int p) {
	id[v] = ++t;
	if (hv[v]) {
		head[hv[v]] = head[v];
		dfs2(hv[v], v);
	}

	for (int u : adj[v])
		if (u != p && u != hv[v])
			dfs2(u, v);
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

inline int LCA(int u, int v) {
	if (H[v] < H[u]) swap(v, u);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

inline node HLD(int v, int p) {
	node ans = node(0, -1);
	while (H[v] > H[p]) {
		int l = (H[head[v]] <= H[p] ? id[v] - (H[v] - H[p] - 1) : id[head[v]]);
		ans = merge(query(l, id[v]), ans);
		v = par[head[v]][0];
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++) cin >> f[i];

	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Q.push_back({{w, 0}, {u, v}}); //
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	for (int i = 1; i <= q; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Q.push_back({{w - 1, i}, {u, v}});
	}

	sort(all(Q), greater<pair<pll, pll>>());
	for (auto e : Q) {
		int u, v;
		tie(u, v) = e.Y;

		int ind = e.X.Y;
		if (!ind) {
			if (H[v] < H[u]) swap(v, u);
			add(id[v]);
		} else {
			int lca = LCA(u, v);
			node a = HLD(u, lca), b = HLD(v, lca);
			swap(a.lb, a.rb);
			ans[ind] = merge(a, b).val;
		}
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}