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

const ll MAXN = 2e5 + 10;
const ll LOG = 20;

int par[MAXN][LOG], F[MAXN][LOG], H[MAXN], n, m, q, 
    ans[MAXN], tin[MAXN], tout[MAXN], t, dp[MAXN];
vector<int> adj[MAXN];
set<int> st_t[MAXN];
vector<pair<int, pll>> Q[MAXN];

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

inline int LCA(int u, int v) {
	if (H[u] > H[v]) swap(u, v);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

inline pll low(int v, int u) {
	int ans = 0;
	for (int i = LOG - 1; i >= 0; i--) {
		if (H[F[v][i]] > H[u]) {
			v = F[v][i];
			ans ^= (1 << i);
		}
	}

	return {ans, v};
}

template<typename T>
inline void sackMerge(T& a, T& b) {
	if (a.size() < b.size())
		a.swap(b);
	for (auto e : b)
		a.insert(e);
	b.clear();
}

void tdfs(int v) {
	tin[v] = ++t;
	for (int u : adj[v])
		tdfs(u);
	tout[v] = t;
}

void dfs1(int v) {
	for (int u : adj[v]) {
		dfs1(u);
		dp[v] = min(dp[v], dp[u]);
	}

	F[v][0] = Par(v, H[v] - dp[v]);
}

void dfs2(int v) {
	for (int u : adj[v]) {
		dfs2(u);
		sackMerge(st_t[v], st_t[u]);
	}

	for (auto e : Q[v]) {
		auto it = st_t[v].lower_bound(e.Y.X);
		if (it != st_t[v].end() && *it <= e.Y.Y)
			ans[e.X]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	H[1] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> par[i][0];
		adj[par[i][0]].push_back(i);
		dp[i] = H[i] = H[par[i][0]] + 1;
	}

	tdfs(1);

	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, lca;
		cin >> u >> v;
		lca = LCA(u, v);
		dp[v] = min(dp[v], H[lca]);
		dp[u] = min(dp[u], H[lca]);
		st_t[v].insert(tin[u]);
		st_t[u].insert(tin[v]);
	}

	dfs1(1);	
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			F[v][i] = F[F[v][i - 1]][i - 1];

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v, lca;
		cin >> u >> v;
		
		if (H[u] > H[v]) swap(u, v);
		lca = LCA(u, v);

		if (max(H[F[v][LOG - 1]], H[F[u][LOG - 1]]) > H[lca]) {
			ans[i] = -1;
			continue;
		}

		pll vlow = low(v, lca), ulow = low(u, lca);
		if (lca == u) ans[i] = vlow.X + 1;
		else {
			ans[i] = vlow.X + ulow.X + 2;
			Q[vlow.Y].push_back({i, {tin[ulow.Y], tout[ulow.Y]}});
		}

	}

	dfs2(1);
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}