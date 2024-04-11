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

vector<int> d_adj[MAXN];
int n, m, dist[MAXN][MAXN], col[MAXN];

void dfs(int v) {
	for (int u : d_adj[v]) {
		if (col[u] == 0) {
			col[u] = 3 - col[v];
			dfs(u);
		} else if (col[u] == col[v]) cout << "NO" << endl, exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) memset(dist[i], 63, sizeof dist[i]), dist[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		if (d) dist[u][v] = 1, dist[v][u] = -1;
		else dist[u][v] = dist[v][u] = 1;
		d_adj[u].push_back(v);
		d_adj[v].push_back(u);
	}
	
	col[1] = 1;
	dfs(1);
	
	for (int k = 1; k <= n; k++) 
		for (int v = 1; v <= n; v++) 
			for (int u = 1; u <= n; u++)
				dist[v][u] = min(dist[v][u], dist[v][k] + dist[k][u]);
	for (int i = 1; i <= n; i++) if (dist[i][i] < 0) return cout << "NO" << endl, 0;
	
	int diam_v = 1, diam_u = 1;
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++) 
			if (dist[diam_v][diam_u] < dist[v][u])
				diam_v = v, diam_u = u;
	cout << "YES" << endl << dist[diam_v][diam_u] << endl;
	for (int i = 1; i <= n; i++) cout << dist[diam_v][i] + 1000 << sep;
	return 0;
}