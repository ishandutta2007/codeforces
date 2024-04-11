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

vector<pair<int, pll>> adj[MAXN]; // v, w, ind
ll dist[MAXN], n, m,  par[MAXN], W[MAXN];

inline void Dijkstra(int s) {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, s});
	dist[s] = 0;
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (auto e : adj[v]) {
			int u = e.X, w = e.Y.X, ind = e.Y.Y;
			if (d_v + w < dist[u]) {
				dist[u] = d_v + w;
				par[u] = ind;
				pq.push({dist[u], u});
			} else if (d_v + w == dist[u] && w < W[par[u]])	par[u] = ind;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(dist, dist + MAXN, INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		W[i + 1] = w;
		adj[u].push_back({v, {w, i + 1}});
		adj[v].push_back({u, {w, i + 1}});
	}

	int s;
	cin >> s;
	Dijkstra(s);
	ll ans = 0;
	vector<int> ans_v;
	for (int i = 1; i <= n; i++) if (i != s) ans += W[par[i]], ans_v.push_back(par[i]);
	cout << ans << endl;
	sort(all(ans_v));
	for (int e : ans_v) cout << e << sep;
	cout << endl;
	return 0;
}