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

int n, m, k;
vector<pair<int, pll>> adj[MAXN];
ll dist[MAXN], par[MAXN];

inline void Dijkstra() {
	memset(dist, 63, sizeof dist);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (auto e : adj[v]) {
			int u = e.X, w = e.Y.X, p_val = e.Y.Y;
			if (d_v + w < dist[u]) {
				dist[u] = d_v + w;
				par[u] = p_val;
				pq.push({dist[u], u});
			} else if (d_v + w == dist[u] && p_val < par[u]) par[u] = p_val;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, {w, 0ll}});
		adj[v].push_back({u, {w, 0ll}});
	}

	for (int i = 0; i < k; i++) {
		int v, w;
		cin >> v >> w;
		adj[1].push_back({v, {w, 1ll}});
	}

	Dijkstra();
	int ans = k;
	for (int i = 1; i <= n; i++) if (par[i]) ans--;
	cout << ans << endl;
	return 0;
}