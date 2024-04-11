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

vector<pll> adj[MAXN];
ll par[MAXN], dist[MAXN], n, m;

void dijkstra(ll s) {
	fill(dist, dist + MAXN, INF);
	fill(par, par + MAXN, -1);

	dist[s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, s});
	while (!q.empty()) {
		ll v = q.top().Y;
		ll d_v = q.top().X;
		q.pop();
		if (d_v != dist[v]) continue;
		for (pll eg : adj[v]) {
			ll u = eg.X, len = eg.Y;
		       	
			if (dist[v] + len < dist[u]) {
				dist[u] = dist[v] + len;
				par[u] = v;
				q.push({dist[u], u});
			}	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}

	dijkstra(1);

	if (dist[n] == INF) return cout << -1 << endl, 0;
	stack<ll> st;
	ll v = n;
	while (par[v] >= 0) {
		st.push(v);
		v = par[v];
	}

	cout << 1 << sep;
	while (!st.empty()) cout << st.top() << sep, st.pop();
	cout << endl;
	return 0;
}