// \_()_/
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

const ll MAXN = 1e3 + 10;

ll n, m, w, dp[MAXN][MAXN], W[MAXN], B[MAXN], C;
vector<pll> A[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {
	vis[v] = true;
	A[C][0].X += W[v];
	A[C][0].Y += B[v];
	A[C].push_back({W[v], B[v]});

	for (int u : adj[v])
		if (!vis[u])
			dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) cin >> W[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			C++;
			A[C].push_back({0, 0});
			dfs(i);
		}
	}

	for (int i = 1; i <= C; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = dp[i - 1][j];
			for (pll e : A[i])
				if (j >= e.X)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - e.X] + e.Y);
		}
	}

	cout << dp[C][w] << endl;
	return 0;
}