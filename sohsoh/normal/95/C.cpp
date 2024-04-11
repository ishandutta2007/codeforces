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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dist[MAXN], n, m, T[MAXN], C[MAXN], x, y;
vector<pll> adj[MAXN], adj_t[MAXN];

inline void Dijkstra(int s) {
	fill(dist, dist + MAXN, INF);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (pll e : adj[v]) {
			int u = e.X, w = e.Y;
			if (dist[u] > d_v + w) {
				dist[u] = d_v + w;
				pq.push({dist[u], u});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> C[i];
		Dijkstra(i);
		for (int j = 1; j <= n; j++)
			if (dist[j] <= T[i]) adj_t[i].push_back({j, C[i]}); 
	}

	swap(adj, adj_t);

	Dijkstra(x);
	if (dist[y] == INF) return cout << -1 << endl, 0;
	cout << dist[y] << endl;
	return 0;
}