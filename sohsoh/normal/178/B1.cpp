#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 17;

int par[MAXN][LOG], dp[MAXN], low[MAXN], depth[MAXN], n, m, k;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v, int p, int d) {
	vis[v] = true;
	par[v][0] = p;
	low[v] = depth[v] = d;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (!vis[u]) dfs(u, v, d + 1), low[v] = min(low[v], low[u]);
		else low[v] = min(low[v], depth[u]);
	} 
}

void dfs2(int v, int br) {
	vis[v] = true;
	dp[v] = br;
	for (int u : adj[v]) {
		if (!vis[u]) {
			if (low[u] > depth[v]) dfs2(u, br + 1);
			else dfs2(u, br);
		}
	}	
}

int i_th_par(int v, int i) {
	int j = 0;
	while (i > 0) {
		if (i & 1) v = par[v][j]; 
		j++;
		i >>= 1;
	}

	return v;
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	v = i_th_par(v, depth[v] - depth[u]);
	int L = 0, R = n;
	while (L < R) {
		int mid = (L + R) / 2;
		if (i_th_par(v, mid) == i_th_par(u, mid)) R = mid;
		else L = mid + 1;
	}

	return i_th_par(v, L);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 1);
	for (int i = 1; i < LOG; i++) for (int v = 1; v <= n; v++) par[v][i] = par[par[v][i - 1]][i - 1];
	memset(vis, false, sizeof vis);
	dfs2(1, 0);
	
	cin >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		cout << dp[u] + dp[v] - 2 * dp[lca(u, v)] << endl;
	}
	return 0;
}