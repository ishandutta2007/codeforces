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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k, s1, s2, f;
ll dist[3][MAXN];
pair<pll, ll> edges[MAXN];
pll LR[MAXN];
vector<pll> adj[MAXN];

inline void Dijkstra(int s, int ind) {
	memset(dist[ind], 63, sizeof dist[ind]);
	dist[ind][s] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, s});	

	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();	
		if (d_v != dist[ind][v]) continue;

		for (pll e : adj[v]) {
			ll u = e.X, d_u = e.Y + d_v;
			if (d_u < dist[ind][u]) {
				dist[ind][u] = d_u;
				pq.push({d_u, u});
			}
		}
	}
}

inline void Majik(bool eq = false) {
	Dijkstra(s1, 1);
	Dijkstra(s2, 2);
	for (int i = 1; i <= k; i++) {
		ll u = edges[i].X.X, v = edges[i].X.Y, w = edges[i].Y, L = LR[i].X;
		if (w == L) continue;
		if (dist[1][u] < dist[2][u] - int(eq)) {
			edges[i].Y = L;
			find(all(adj[u]), make_pair(v, w)) -> Y = L;
			Majik(eq);
			break;
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> s1 >> s2 >> f;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}	

	for (int i = 1; i <= k; i++) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		adj[u].push_back({v, r});
		LR[i] = {l, r};
		edges[i] = {{u, v}, r};
	}

	Majik(false);
	if (dist[1][f] < dist[2][f]) {
		cout << "WIN" << endl;
		for (int i = 1; i <= k; i++) cout << edges[i].Y << sep;
		cout << endl;
		return 0;
	}

	Majik(true);
	if (dist[1][f] <= dist[2][f]) {
		cout << "DRAW" << endl;
		for (int i = 1; i <= k; i++) cout << edges[i].Y << sep;
		cout << endl;
		return 0;
	}

	cout << "LOSE" << endl;
	return 0;
}