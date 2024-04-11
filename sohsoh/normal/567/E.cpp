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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<pll> adj[MAXN], adj_r[MAXN], dag_adj[MAXN], dag_adj_u[MAXN];
int n, m, s, t, depth[MAXN], low[MAXN];
ll dist[MAXN], dist_t[MAXN];
pair<pll, ll> edges[MAXN];
bool D[MAXN], vis[MAXN], dp[MAXN], edge_vis[MAXN];

inline void Dijkstra(int s) {
	fill(dist, dist + MAXN, 1e18);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		ll d_v = pq.top().X, v = pq.top().Y;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (pll e : adj[v]) {
			int u = e.X, w = e.Y;
			if (d_v + w < dist[u]) {
				dist[u] = d_v + w;
				pq.push({dist[u], u});
			}	
		}
	}
}

void dfs(int v) {
	if (v == t) dp[v] = true;
	vis[v] = true;
	for (pll e : dag_adj[v]) {
		int u = e.X;
		if (!vis[u]) dfs(u);
		dp[v] |= dp[u];
	}
}

void dfs2(int v) {
	vis[v] = true;
	low[v] = depth[v];
	for (auto e : dag_adj_u[v]) {
		if (edge_vis[e.Y]) continue;
		edge_vis[e.Y] = true;
		int u = e.X;
		if (!dp[u]) continue;
		if (!vis[u]) {	
			depth[u] = depth[v] + 1;
			dfs2(u);
			low[v] = min(low[v], low[u]);
		} else low[v] = min(low[v], depth[u]);	
	}
} 

void dfs3(int v) {
	vis[v] = true;
	for (auto e : dag_adj_u[v]) {
		if (edge_vis[e.Y]) continue;	
		edge_vis[e.Y] = true;
		int u = e.X;
		if (!dp[u]) continue;
		if (low[u] > depth[v]) D[e.Y] = true;
		if (!vis[u]) dfs3(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	fill(low, low + MAXN, 1e9);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj_r[v].push_back({u, w});
		edges[i] = {{u, v}, w};
	}
	
	swap(adj, adj_r);
	Dijkstra(t);
	for (int i = 1; i <= n; i++) dist_t[i] = dist[i];
	swap(adj, adj_r);
	Dijkstra(s);
	for (int i = 0; i < m; i++) {
		int u = edges[i].X.X, v = edges[i].X.Y, w = edges[i].Y;
		if (dist[u] + w == dist[v]) {
			dag_adj[u].push_back({v, i});
			dag_adj_u[u].push_back({v, i});
			dag_adj_u[v].push_back({u, i});
			debug(i)
		}
	}

	dfs(s);
	memset(vis, false, sizeof vis);
	dfs2(s);
	memset(vis, false, sizeof vis);
	memset(edge_vis, false, sizeof edge_vis);
	dfs3(s);
	
	ll SP = dist[t];
	for (int i = 0; i < m; i++) {
		if (D[i]) cout << "YES" << endl;
		else {
			auto e = edges[i];
			ll P = dist[e.X.X] + dist_t[e.X.Y] + e.Y;
			if (P - e.Y + 1 > SP - 1) cout << "NO" << endl;
			else {
				cout << "CAN " << P - SP + 1 << endl;
			}
		}
	}
	return 0;
}