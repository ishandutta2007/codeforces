#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimize("O3,no-stack-protector,unroll-loops,fast-math")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;

int n, q, id[MAXN], V[MAXN], sz[MAXN];
ll dp_up[MAXN], f[MAXN], l;
pll dp[MAXN];
vector<pll> adj[MAXN];
vector<int> C[MAXN];
bool B[MAXN];

void dfs(int v, int p) {
	for (pll e : adj[v]) {
		ll u = e.X, w = e.Y;
		if (u == p) continue;
		dfs(u, v);

		ll x = dp[u].X + w;
		if (x > dp[v].X) dp[v].Y = dp[v].X, dp[v].X = x;
		else if (x > dp[v].Y) dp[v].Y = x;
	}
}

void dfs2(int v, int p) {
	for (pll e : adj[v]) {
		ll u = e.X, w = e.Y;
		if (u == p) continue;
		
		dp_up[u] = dp_up[v] + w;
		if (dp[u].X + w != dp[v].X) dp_up[u] = max(dp_up[u], dp[v].X + w);
		else dp_up[u] = max(dp_up[u], dp[v].Y + w);
	
		dfs2(u, v);
	}

	f[v] = max(dp[v].X, dp_up[v]);
}

inline void update(int v, int d) {
	sz[v] += d;
}

inline void merge(int v, int u) {
	if (!B[v] || !B[u]) return;
	v = id[v], u = id[u];
	
	if (v == u) return;
	if (C[v].size() > C[u].size()) swap(v, u);

	for (int e : C[v]) {
		id[e] = u;
		C[u].push_back(e);
	}

	update(u, sz[v]);
	C[v].clear();
}

inline void add(int v) {
	B[v] = true;
	update(id[v], 1);
	for (pll e : adj[v])
		merge(v, e.X);
}

inline void remove(int v) {
	if (B[v]) {
		B[v] = false;
		update(id[v], -1);
	}
}

inline void solve() {
	int p = n;
	for (int i = 1; i <= n; i++) {
		id[i] = i;
		B[i] = false;
		sz[i] = 0;
		C[i] = {i};	
	}

	int ans = 1;
	for (int i = n; i > 0; i--) {
		while (f[V[p]] - f[V[i]] > l) remove(V[p--]);
		add(V[i]);
		ans = max(ans, sz[id[V[i]]]);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dfs(1, 0);
	dfs2(1, 0);

	for (int i = 1; i <= n; i++) V[i] = i;
	sort(V + 1, V + n + 1, [] (int v, int u) {
		return f[v] < f[u];
	});

	cin >> q;
	while (q--) {
		cin >> l;
		solve();
	}
	return 0;
}