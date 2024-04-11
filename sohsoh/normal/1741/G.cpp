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

const ll MAXN = 1e4 + 10;
const ll MAXK = 6;

int V[MAXN], dist[MAXK + 1][MAXN], n, c, k, m, T[MAXK];
bool f[MAXN][1 << MAXK], dp[1 << MAXK];
vector<int> adj[MAXN];

inline void BFS(int ind, int v) {
	queue<int> q;
	q.push(v);
	fill(dist[ind], dist[ind] + n + 5, MAXN);
	dist[ind][v] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[ind][u] == MAXN) {
				dist[ind][u] = dist[ind][v] + 1;
				q.push(u);
			}
		}
	}
}

inline void try_dp(int v) {
	f[v][0] = true;

	int ind = 0;
	while (ind < k && T[ind] != v) ind++;

	if (ind < k) f[v][1 << ind] = true;
	for (int mask = 0; mask < (1 << k); mask++) {
		for (int i = 0; i < k; i++) {
			if (T[i] == v || !(mask & (1 << i))) continue;

			int tmask = mask;
			
			if (ind < k) tmask = ((tmask | (1 << ind)) ^ (1 << ind));
			if (dist[k][V[T[i]]] + dist[i][V[v]] == dist[k][V[v]]) f[v][mask] |= f[T[i]][tmask];
		}
	}
}

inline void solve() {
	memset(dp, false, sizeof dp);
	for (int i = 0; i <= max(c, n) + 5; i++) {
		memset(f[i], false, sizeof f[i]);
		adj[i].clear();
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> c;
	for (int i = 1; i <= c; i++) cin >> V[i];
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> T[i];
		BFS(i, V[T[i]]);
	}

	BFS(k, 1);
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < k; j++)
			try_dp(T[j]);
	
	for (int i = 1; i <= c; i++)
		try_dp(i);

	dp[0] = true;
	for (int i = 1; i <= c; i++) {
		if (find(T, T + k, i) != T + k) continue;
		for (int mask = (1 << k) - 1; mask >= 0; mask--)
			for (int smask = mask; smask; smask = (smask - 1) & mask)
				dp[mask] |= f[i][smask] & dp[mask ^ smask];
	}

	int ans = 0;
	for (int mask = 0; mask < (1 << k); mask++)
		ans = max(ans, int(dp[mask]) * __builtin_popcount(mask));
	cout << k - ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}