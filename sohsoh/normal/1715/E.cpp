#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define int			ll

const ll MAXN = 1e6 + 10;
const ll MAXK = 23;

namespace CHT {
	const ll INF = 1e18;
	vector<pair<ll, pll>> vec;
	inline ll isect(pll a, pll b) {
		if (a.X == b.X)
			return a.Y < b.Y ? INF : -INF;
		if (a.X > b.X) swap(a, b);
		return (a.Y - b.Y + (a.Y <= b.Y ? 0 : 1) * (b.X - a.X - 1)) / (b.X - a.X);
	}
 
	inline void add(ll m, ll a) {
		pll line = {m, a};
		while (!vec.empty()) {
			ll x = isect(vec.back().Y, line);
			if (x <= vec.back().X) vec.pop_back();
			else {
				vec.push_back({x, line});
				return;	
			}
		}
 
		vec.push_back({-INF, line});
	}
 
	inline ll query(ll x) {
		pll line = prev(upper_bound(all(vec), make_pair(x, make_pair(INF, INF)))) -> Y;
		return line.X * x + line.Y;
	}
}

const ll INF = 1e12;

ll dist[MAXK][MAXN], n, m, k;
vector<pll> adj[MAXN];

inline void dijkstra(int i) {	
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int v = 1; v <= n; v++)
		pq.push({dist[i][v], v});

	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[i][v]) continue;

		for (auto [u, w] : adj[v]) {
			ll d_u = d_v + w;
			if (d_u < dist[i][u]) {
				dist[i][u] = d_u;
				pq.push({d_u, u});
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for (int i = 0; i < MAXK; i++)
		fill(dist[i], dist[i] + MAXN, INF);


	dist[0][1] = 0;
	dijkstra(0);

	for (int i = 1; i <= k; i++) {
		vector<pll> vec;
		for (int v = 1; v <= n; v++)
			vec.push_back({-2 * v, dist[i - 1][v] + v * v});

		CHT::vec.clear();
		sort(all(vec), greater<pll>()); //
		for (pll e : vec)
			CHT::add(e.X, e.Y);
		
		for (int v = 1; v <= n; v++)
			dist[i][v] = CHT::query(v) + v * v;
		
		dijkstra(i);
	}

	for (int i = 1; i <= n; i++)
		cout << dist[k][i] << sep;
	cout << endl;
	return 0;
}