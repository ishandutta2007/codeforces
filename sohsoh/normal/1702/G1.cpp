#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

int n, tin[MAXN], tout[MAXN], t, q, par[MAXN][LOG], H[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	tin[v] = ++t;
	par[v][0] = p;
	H[v] = H[p] + 1;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	
	tout[v] = t;
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

inline bool is_par(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		if (k == 1) {
			int x;
			cin >> x;
			cout << "YES" << endl;
			continue;
		}

		bool flag = true;
		int u, v;
		cin >> u >> v;

		for (int i = 3; i <= k; i++) {
			int w;
			cin >> w;
			
			if (H[v] < H[u]) swap(v, u);
			if (is_par(u, v)) {
				int lca = LCA(v, w);	
				if (lca == v) v = w;
				else if (H[lca] <= H[u]) u = w;
				else if (!is_par(w, v)) flag = false;
			} else {
				if (is_par(u, w)) u = w;
				else if (is_par(v, w)) v = w;
				else if (H[w] < H[LCA(u, v)] || (!is_par(w, v) && !is_par(w, u))) flag = false;
			}
		}

		cout << (flag ? "YES" : "NO") << endl;

	}
	return 0;
}