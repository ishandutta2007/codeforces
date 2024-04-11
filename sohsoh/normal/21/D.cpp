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

const ll MAXN = 16;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dp[1 << MAXN], deg[MAXN], dist[MAXN][MAXN], n, m, ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dist[i][j] = INF;
	fill(dp, dp + (1 << MAXN), INF);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		deg[v]++;
		deg[u]++;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
		ans += w;	
	}

	for (int t = 0; t < n; t++) for (int v = 0; v < n; v++) for (int u = 0; u < n; u++) dist[v][u] = min(dist[v][u], dist[v][t] + dist[t][u]);
	
	int MSK = (1 << n), ODD_MSK = 0;
	for (int i = 0; i < n; i++) if (deg[i] & 1) ODD_MSK ^= (1 << i);
	
	dp[0] = 0;
	for (int msk = 0; msk < MSK; msk++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((msk & (1 << i)) && (msk & (1 << j))) {
					dp[msk] = min(dp[msk], dp[msk ^ (1 << i) ^ (1 << j)] + dist[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) if (deg[i] && dist[0][i] >= INF) return cout << -1 << endl, 0;
	cout << ans + dp[ODD_MSK] << endl;
	return 0;
}