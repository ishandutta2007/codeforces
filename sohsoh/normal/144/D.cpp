#include <bits/stdc++.h>

using namespace std;

#define int	long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

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

int n, m, dist[MAXN], s, l;
vector<pll> adj[MAXN];
vector<pair<pll, int>> edges;

inline void Dijkstra(int s) {
	fill(dist, dist + MAXN, INF);
	dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		int v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		for (pll e : adj[v]) {
			int u = e.X, w = e.Y;
			if (dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				pq.push({dist[u], u});
			} 
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
		edges.push_back({{u, v}, w});
	}

	cin >> l;

	Dijkstra(s);
	int ans = count(dist + 1, dist + n + 1, l);
	for (auto e : edges) {
		int u = e.X.X, v = e.X.Y, w = e.Y;
		if (dist[u] < dist[v]) swap(u, v);
		if (l > dist[v] && l < dist[v] + w && 2 * l <= dist[v] + dist[u] + w) ans++;
		if (l > dist[u] && l < dist[u] + w && 2 * l < dist[v] + dist[u] + w) ans++;
	}

	cout << ans << endl;
	return 0;
}