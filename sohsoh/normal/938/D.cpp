#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    long long

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m;
vector<pll> adj[MAXN];
ll dist[MAXN];

inline void Dijkstra() {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int i = 1; i <= n; i++) pq.push({dist[i], i});
	while (!pq.empty()) {
		ll d_v = pq.top().X, v = pq.top().Y;
		pq.pop();
		if (dist[v] != d_v) continue;

		for (pll e : adj[v]) {
			int u = e.X, w = e.Y;
			if (2 * w + d_v < dist[u]) {
				dist[u] = 2 * w + d_v;
				pq.push({dist[u], u});
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	for (int i = 1; i <= n; i++) cin >> dist[i];
	Dijkstra();
	for (int i = 1; i <= n; i++) cout << dist[i] << sep;
	return 0;
}