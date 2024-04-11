//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 49;
const int lgn = 20;


vector<int> up[N][lgn], adj[N], pep[N];
int par[N][lgn], h[N];

vector<int> fix(vector<int> x, vector<int> y) {
	vector<int> res;
	for (auto p : y)
		res.push_back(p);
	for (auto p : x)
		res.push_back(p);
	sort(res.begin(), res.end());
	while (res.size() > 10)
		res.pop_back();
	return res;	
}

void dfs(int v, int p = -1) {
	h[v] = ~p? h[p] + 1: 0;
	par[v][0] = ~p? p: v;
	for (int i = 1; i < lgn; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	up[v][0] = pep[v];
	for (int i = 1; i < lgn; i++)
		up[v][i] = fix(up[v][i - 1], up[par[v][i - 1]][i - 1]);
	for (auto u : adj[v]) if (u != p)
		dfs(u, v);
}

int go_up(int v, int k) {
	for (int i = 0; i < lgn; i++)
		if (k >> i & 1)
			v = par[v][i];
	return v;	
}

vector<int> get_up(int v, int k) {
	vector<int> cur;
	for (int i = 0; i < lgn; i++)
		if (k >> i & 1)
			cur = fix(cur, up[v][i]), v = par[v][i];
	return cur;
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	u = go_up(u, h[u] - h[v]);
	if (u == v)
		return v;
	for (int i = lgn - 1; ~i; --i)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for (int i = 0; i < n - 1; i++) { 
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		int pe; cin >> pe; pe--;
		pep[pe].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		sort(pep[i].begin(), pep[i].end());
		while (pep[i].size() > 10)
			pep[i].pop_back();
	}
	dfs(0);
	while (q--) {
		int u, v, a; cin >> u >> v >> a; --u, --v;
		int p = lca(u, v);
		if (h[u] > h[v]) swap(u, v);
		vector<int> x, y;
		x = get_up(v, h[v] - h[p] + 1);
		y = get_up(u, h[u] - h[p]);
		x = fix(x, y);
		cout << min(a, (int) x.size()) << ' ';
		for (int i = 0; i < min(a, (int) x.size()); i++)
			cout << x[i] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}