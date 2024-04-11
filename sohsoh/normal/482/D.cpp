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

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll dp[MAXN][2], f[MAXN][2][2];
vector<int> adj[MAXN];
int n;

void dfs(int v) {
	dp[v][1] = 1;
	f[v][0][0] = f[v][1][0] = 1;

	for (int u : adj[v]) {
		dfs(u);	
		ll f0 = dp[v][0] + dp[v][0] * dp[u][0] + dp[v][1] * dp[u][1];
		ll f1 = dp[v][1] + dp[v][0] * dp[u][1] + dp[v][1] * dp[u][0];
		dp[v][0] = f0 % MOD;
		dp[v][1] = f1 % MOD;
	
		ll t00 = f[v][0][0] + f[v][0][1] * dp[u][0];
		ll t01 = f[v][0][1] + f[v][0][0] * dp[u][0];
		ll t10 = f[v][1][0] + f[v][1][1] * dp[u][1];
		ll t11 = f[v][1][1] + f[v][1][0] * dp[u][1];
		f[v][0][0] = t00 % MOD;
		f[v][0][1] = t01 % MOD;
		f[v][1][0] = t10 % MOD;
		f[v][1][1] = t11 % MOD;
	}

	dp[v][0] = (2 * dp[v][0] + 3 * MOD - f[v][1][1]) % MOD;
	dp[v][1] = (2 * dp[v][1] + 3 * MOD - f[v][0][0] - f[v][0][1]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	dfs(1);
	cout << (dp[1][0] + dp[1][1]) % MOD << endl;
	return 0;
}