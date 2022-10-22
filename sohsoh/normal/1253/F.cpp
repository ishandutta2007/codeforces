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
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

priority_queue<pll, vector<pll>, greater<pll>> q;
int n, m, k, qr, par[MAXN], src[MAXN];
ll dist[MAXN], ans[MAXN], T;
vector<int> C[MAXN];
vector<pll> adj[MAXN], q_adj[MAXN];
vector<pair<ll, pll>> edges;

inline void Dijkstra() {
	while (!q.empty()) {
		int v = q.top().Y;
		ll d_v = q.top().X;
		q.pop();
		if (d_v != dist[v]) continue;
		for (pll e : adj[v]) {
			if (dist[e.X] > d_v + e.Y) {
				dist[e.X] = d_v + e.Y;
				q.push({dist[e.X], e.X});
				src[e.X] = src[v];
			}
		}
	}
}

inline void Union(int u, int v) {
	u = par[u];
	v = par[v];
	if (u == v) return;
	if (C[u].size() < C[v].size()) swap(v, u);
	for (int e : C[v]) {
		for (pll qr_e : q_adj[e]) {
			if (par[qr_e.X] == u) {
				ans[qr_e.Y] = min(ans[qr_e.Y], T);
			}
		}
	}

	for (int e : C[v]) {
		par[e] = u;
		C[u].push_back(e);
	}

	C[v].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(dist, dist + MAXN, INF);
	fill(ans, ans + MAXN, INF);
	cin >> n >> m >> k >> qr;
	for (int i = 1; i <= k; i++) {
		dist[i] = 0;
		q.push({0, i});
		src[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	Dijkstra();

	for (int v = 1; v <= n; v++) {
		par[v] = v;
		C[v].push_back(v);
		for (pll e : adj[v]) {
			int u = e.X;
			if (src[u] != src[v])
				edges.push_back({dist[u] + dist[v] + e.Y, {src[u], src[v]}});
		}
	}

	sort(all(edges));
	for (int i = 1; i <= qr; i++) {
		int u, v;
		cin >> u >> v;
		q_adj[u].push_back({v, i});
		q_adj[v].push_back({u, i});
	}

	for (auto e : edges) {
		T = e.X;
		Union(e.Y.X, e.Y.Y);
	}

	for (int i = 1; i <= qr; i++) cout << ans[i] << endl;
	return 0;
}