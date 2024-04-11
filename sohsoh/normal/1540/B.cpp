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

const ll MAXN = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

int n, sub_g[MAXN];
vector<int> adj[MAXN], V;
ll dp[MAXN][MAXN], inv[MAXN], ans = 0;

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

void D(int v, int p) {
	sub_g[v] = 1;
	for (int u : adj[v])
		if (u != p)
			D(u, v), sub_g[v] += sub_g[u];
}

void dfs(int v, int p, int s) {
	V.push_back(v);
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, s);
	}


	if (s < v) {
		mkey(ans += sub_g[v]);
		for (int i = 0; i < V.size() - 1; i++) {
			mkey(ans += dp[V.size()][V.size() - i] * (sub_g[V[i]] - sub_g[V[i + 1]]) % MOD);
		}	
	}
	
	V.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	dp[1][1] = 1;
	for (int i = 1; i < MAXN; i++) inv[i] = poww(i, MOD - 2);
	
	for (int R = 2; R <= n + 2; R++) {
		for (int ind = 1; ind <= R; ind++) {
			if (ind == 1) {
				dp[R][ind] = 1;	
				continue;
			}

			if (ind == R) {
				dp[R][ind] = 0;
				continue;
			}

			dp[R][ind] = (inv[2] * dp[R - 1][ind - 1] + inv[2] * dp[R - 1][ind]) % MOD;
		}
	}
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int v = 1; v <= n; v++)
		D(v, 0), dfs(v, 0, v);
	cout << ans * inv[n] % MOD << endl;
	return 0;
}