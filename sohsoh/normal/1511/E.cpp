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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

int n, m;
vector<vector<ll>> dp[2], grid, ps;
ll t_pow[MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		dp[0].push_back({});
		dp[1].push_back({});
		ps.push_back({});
		grid.push_back({});
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'o') grid[i].push_back(1), ps[i].push_back(1);
			else grid[i].push_back(0), ps[i].push_back(0);
			dp[0][i].push_back(0);
			dp[1][i].push_back(0);
			if (i) ps[i][j] += ps[i - 1][j];
			if (j) ps[i][j] += ps[i][j - 1];
			if (i && j) ps[i][j] -= ps[i - 1][j - 1];
		}
	}

	t_pow[0] = 1;
	for (int i = 1; i < MAXN; i++) t_pow[i] = t_pow[i - 1] * 2 % MOD;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) continue;
			dp[0][i][j] = dp[1][i][j] = t_pow[ps[i][j] - 1];
			if (j) mkey(dp[0][i][j] -= dp[0][i][j - 1] * t_pow[ps[i][j] - ps[i][j - 1] - 1] % MOD);
			if (i) mkey(dp[1][i][j] -= dp[1][i - 1][j] * t_pow[ps[i][j] - ps[i - 1][j] - 1] % MOD);
		}
	}

	ll ans = 0, tot = ps[n - 1][m - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) continue;
			if (j) mkey(ans += dp[0][i][j - 1] * t_pow[tot - ps[i][j - 1] - 1] % MOD);
			if (i) mkey(ans += dp[1][i - 1][j] * t_pow[tot - ps[i - 1][j] - 1] % MOD);
		}
	}

	cout << ans << endl;
	return 0;
}