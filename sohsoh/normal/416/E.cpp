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

const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, D[MAXN][MAXN], dist[MAXN][MAXN];
vector<pll> adj[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) memset(dist[i], 63, sizeof dist[i]), dist[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		dist[u][v] = min(dist[u][v], l);
		dist[v][u] = min(dist[v][u], l);
		adj[v].push_back({u, l});
		adj[u].push_back({v, l});
	}

	for (int k = 1; k <= n; k++) 
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
	

	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			for (pll e : adj[v]) 
				if (e.Y + dist[e.X][u] == dist[v][u]) D[v][u]++;	
	
	for (int s = 1; s <= n; s++) {
		for (int t = s + 1; t <= n; t++) {
			int tans = 0;
			for (int k = 1; k <= n; k++) {
				if (dist[s][k] + dist[k][t] > dist[s][t]) continue;
			
				tans += D[k][t];
			}

			cout << tans << sep;
		}
	}

	cout << endl;
	return 0;
}