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

ld dp1[MAXN], dp2[MAXN];
vector<int> adj[MAXN], adj_t[MAXN];
int dist[MAXN], n, m;
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	for (int u : adj_t[v]) {	
		if (!vis[u]) dfs(u);
		dp2[v] += dp2[u];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dist, 63, sizeof dist);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	dp1[1] = dp2[n] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				q.push(u);
				adj_t[v].push_back(u);
				dp1[u] += dp1[v];
			} else if (dist[u] == dist[v] + 1) adj_t[v].push_back(u), dp1[u] += dp1[v];
		}
	}

	dfs(1);

	ld tot = dp2[1], ans = 1;
	for (int i = 2; i < n; i++) ans = max(ans, dp1[i] / tot * dp2[i] * 2);
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}