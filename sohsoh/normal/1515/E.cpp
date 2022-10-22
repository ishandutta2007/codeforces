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

const ll MAXN = 400 + 10;
const ll INF = 8e18;
ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], n, C[MAXN][MAXN], tpow[MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	dp[1][1] = 1;
	dp[2][2] = 2;

	tpow[0] = 1;
	C[0][0] = 1;
	for (int j = 1; j < MAXN; j++) {
		for (int i = 0; i <= j; i++) {
			C[i][j] = C[i][j - 1];
			if (i) mkey(C[i][j] += C[i - 1][j - 1]);
		}

		tpow[j] = tpow[j - 1] * 2 % MOD;
	}

	for (int i = 3; i <= n + 2; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 2][j - 1] * j % MOD;
			if (j == i) mkey(dp[i][j] += tpow[i - 1]);
			for (int k = i - 1; k > 2; k--) {
				if (j < i - k + 1) continue;
				mkey(dp[i][j] += dp[k - 2][j - (i - k + 1)] * C[i - k + 1][j] % MOD * tpow[i - k] % MOD);
			}
		}	
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) mkey(ans += dp[n][i]);
	cout << ans << endl;
	return 0;
}