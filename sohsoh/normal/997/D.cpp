#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 4000 + 10;
const ll MAXK = 80;
const ll MOD = 998244353;

int n1, n2, dp[2][MAXK][MAXN], k, sz[MAXN], ans[MAXK], ans2[MAXK], C[MAXK][MAXK];
vector<int> adj[MAXN], adj2[MAXN], vert;
bool vis[MAXN], B[MAXN];

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
}

int sub_sz(int v, int p) {
	vert.push_back(v);
	sz[v] = 1;
	vis[v] = true;

	for (int u : adj[v])
		if (u != p && !B[u])
			sz[v] += sub_sz(u, v);
	return sz[v];
}

int centroid(int v, int p, int n) {
	for (int u : adj[v])
		if (u != p && !B[u] && sz[u] * 2 > n)
			return centroid(u, v, n);
	return v;
}

void solve(int v) {
	B[v = centroid(v, 0, sub_sz(v, 0))] = true;
	for (int u : vert)
		dp[0][0][u] = dp[1][0][u] = 0;
	dp[0][0][v] = dp[1][0][v] = 1;

	for (int i = 1; i <= k; i++) {
		for (int u : vert) {
			dp[0][i][u] = dp[1][i][u] = 0;

			for (int w : adj[u]) {
				if (vis[w]) {
					if (u != v) mkey(dp[0][i][u] += dp[0][i - 1][w]);
					mkey(dp[1][i][u] += dp[1][i - 1][w]);
				}
			}
		}
	}

	for (int u : vert) {
		if (u != v) {
			for (int i = 0; i <= k; i++) {
				for (int j = 0; j <= i; j++) {
					ans[i] = (ans[i] + 1ll * dp[0][j][u] * dp[1][i - j][u]) % MOD;
				}
			}
		}

		vis[u] = false;
	}

	for (int i = 0; i <= k; i++)
		mkey(ans[i] += dp[1][i][v]);

	vert.clear();

	for (int u : adj[v])
		if (!B[u])
			solve(u);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	C[0][0] = 1;
	for (int i = 1; i < MAXK; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			mkey(C[i][j] = C[i - 1][j - 1] + C[i - 1][j]);
	}

	cin >> n1 >> n2 >> k;
	for (int i = 1; i < n1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i < n2; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}

	solve(1);
	memset(B, false, sizeof B);
	swap(adj, adj2);
	swap(ans, ans2);
	solve(1);

	ll fans = 0;
	for (int i = 0; i <= k; i++)
		fans += C[k][i] * ans[i] % MOD * ans2[k - i] % MOD; 
	cout << fans % MOD << endl;
	return 0;
}