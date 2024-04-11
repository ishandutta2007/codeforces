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

int n, m, k, src[MAXN], par[MAXN], H[MAXN];
vector<pll> adj[MAXN];
vector<pair<ll, pll>> mst_edges;
ll dist[MAXN], ans;
priority_queue<pll, vector<pll>, greater<pll>> pq;

inline void Dijkstra() {
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (pll e : adj[v]) {
			ll t_d = d_v + e.Y, u = e.X;
			if (dist[u] > t_d) {
				dist[u] = t_d;
				src[u] = src[v];
				pq.push({t_d, u});
			}	
		}
	}
} 

inline void make_source(int v) {
	if (dist[v] == 0) return;
	dist[v] = 0;
	pq.push({0, v});
	src[v] = v;
	par[v] = v;
}

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline void Union(int v, int u) {
	v = Find(v);
	u = Find(u);
	if (v == u) return;
	if (H[v] > H[u]) swap(v, u);
	par[v] = u;
	if (H[v] == H[u]) H[u]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(dist, dist + MAXN, INF);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	cin >> k;
	vector<int> vec;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		make_source(x);
	}

	Dijkstra();
	for (int v = 1; v <= n; v++) {
		for (pll e : adj[v]) {
			int u = e.X;
			if (src[u] != src[v]) {
				mst_edges.push_back({dist[u] + dist[v] + e.Y, {src[u], src[v]}});
			}
		}
	}

	sort(all(mst_edges));
	for (auto e : mst_edges) {
		if (Find(e.Y.X) != Find(e.Y.Y)) {
			ans += e.X;
			Union(e.Y.X, e.Y.Y);
		}
	}

	fill(dist, dist + MAXN, INF);
	while (!pq.empty()) pq.pop();
	make_source(1);
	Dijkstra();

	ll mn_dist = INF;
	for (int e : vec)
		mn_dist = min(mn_dist, dist[e]);
	
	cout << ans + mn_dist << endl;
	return 0;
}