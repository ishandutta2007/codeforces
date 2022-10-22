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
 
const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

ll dp[MAXN][MAXN][2][2] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	dp[1][1][1][1] = dp[1][1][0][0] = dp[1][2][1][0] = dp[1][2][0][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < MAXN; j++) {
			mkey(dp[i][j][0][0] += dp[i - 1][j][0][1]);
			mkey(dp[i][j][0][0] += dp[i - 1][j][1][0]);
			mkey(dp[i][j][0][0] += dp[i - 1][j][0][0]);
			mkey(dp[i][j][0][0] += dp[i - 1][j - 1][1][1]);
			mkey(dp[i][j][1][1] += dp[i - 1][j][1][0]);
			mkey(dp[i][j][1][1] += dp[i - 1][j][0][1]);
			mkey(dp[i][j][1][1] += dp[i - 1][j][1][1]);
			mkey(dp[i][j][1][1] += dp[i - 1][j - 1][0][0]);
			mkey(dp[i][j][1][0] += dp[i - 1][j][1][0]);
			mkey(dp[i][j][1][0] += dp[i - 1][j - 1][1][1]);
			mkey(dp[i][j][1][0] += dp[i - 1][j - 1][0][0]);
			mkey(dp[i][j][0][1] += dp[i - 1][j][0][1]);
			mkey(dp[i][j][0][1] += dp[i - 1][j - 1][1][1]);
			mkey(dp[i][j][0][1] += dp[i - 1][j - 1][0][0]);

			if (j > 1) mkey(dp[i][j][1][0] += dp[i - 1][j - 2][0][1]);
			if (j > 1) mkey(dp[i][j][0][1] += dp[i - 1][j - 2][1][0]);
		}
	}

	cout << (dp[n][k][0][0] + dp[n][k][0][1] + dp[n][k][1][0] + dp[n][k][1][1]) % MOD << endl;
	return 0;
}