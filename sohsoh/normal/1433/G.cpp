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

ll dist[MAXN][MAXN], n, m, k;
vector<pll> adj[MAXN], R, E;

void dijkstra(ll s) {
	fill(dist[s], dist[s] + MAXN, INF);
	dist[s][s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[s][v]) continue;
		for (pll u : adj[v]) {
			if (dist[s][v] + u.Y < dist[s][u.X]) {
				dist[s][u.X] = dist[s][v] + u.Y;
				pq.push({dist[s][u.X], u.X});
			}
		}
	}
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		E.push_back({u, v});
	}

	for (int i = 0; i < k; i++) {
		ll u, v;
		cin >> u >> v;
		R.push_back({u, v});
	}

	for (int i = 1; i <= n; i++) dijkstra(i);
	ll ans = INF;
	for (pll e : E) {
		ll tans = 0;
		for (pll e2 : R) {
			ll u = e2.X, v = e2.Y, a = e.X, b = e.Y;
			tans += min(dist[u][v], min(dist[u][a] + dist[b][v], dist[u][b] + dist[a][v]));
		}
		
		ans = min(ans, tans);
	}

	cout << ans << endl;
	return 0;
}