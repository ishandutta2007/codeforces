// Sohsoh84 :)))))
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

const ll MAXN = 100 + 3;
const ll MOD = 1e9 + 7;

int n, sub_g[MAXN];
vector<int> adj[MAXN];
ll dp[MAXN][MAXN][MAXN], tmp_dp[MAXN][MAXN], C[MAXN][MAXN], ans[MAXN], inv; // node, cmp size, edges

inline void mkey(ll& a) {	
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
}

void dfs(int v, int p) {
	sub_g[v] = 1;
	dp[v][1][0] = 1;

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		
		int s1 = sub_g[v], s2 = sub_g[u];
		for (int i = 0; i < MAXN; i++)
			memset(tmp_dp[i], 0, sizeof tmp_dp[i]);

		for (int i1 = 0; i1 <= s1; i1++) {
			for (int j1 = 0; j1 <= s1; j1++) {
				for (int i2 = 0; i2 <= s2; i2++) {
					for (int j2 = 0; j2 <= s2; j2++) {
						mkey(tmp_dp[i1][j1 + j2] += dp[v][i1][j1] * dp[u][i2][j2] % MOD 
							* n % MOD * i2 % MOD);	
						mkey(tmp_dp[i1 + i2][j1 + j2 + 1] += dp[v][i1][j1] * dp[u][i2][j2] % MOD);
					}
				}
			}
		}

		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
				dp[v][i][j] = tmp_dp[i][j];

		sub_g[v] += sub_g[u];
	}
}

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	C[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		C[0][i] = 1;
		for (int j = 1; j < MAXN; j++) 
			mkey(C[j][i] = C[j][i - 1] + C[j - 1][i - 1]);
	}

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, 0);
	
	ans[n - 1] = 1;
	inv = poww(n, MOD - 2);
	for (int i = n - 2; i >= 0; i--) {	
		for (int j = 1; j < n; j++)
			mkey(ans[i] += dp[1][j][i] * j % MOD * inv % MOD);
		for (int j = i + 1; j < n; j++)
			mkey(ans[i] -= ans[j] * C[i][j] % MOD);
	}

	for (int i = 0; i < n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}