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

const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

int n;
pair<bool, ll> A[MAXN];
ll ans = 0, dp[MAXN][MAXN], dp2[MAXN][MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == '-') A[i] = {0, 0};
		else {
			ll x;
			cin >> x;
			A[i] = {1, x};
		}
	}

	for (int ind = 1; ind <= n; ind++) {
		if (!A[ind].X) continue;
		ll x = A[ind].Y;
		
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < MAXN - 1; j++) {
				dp[i][j] = 0;
				if (i > ind && j == 0) continue;

				if (i <= ind) {
					if (i != ind) dp[i][j] = dp[i - 1][j];
					if (A[i].X) {
						if (A[i].Y > x) mkey(dp[i][j] += dp[i - 1][j]);
						else if (j) mkey(dp[i][j] += dp[i - 1][j - 1]);
					} else {
						mkey(dp[i][j] += dp[i - 1][j + 1]);
						if (j == 0) mkey(dp[i][j] += dp[i - 1][j]);
					}
				} else {
					dp[i][j] = dp[i - 1][j];
					if (A[i].X) {
						if (A[i].Y >= x) mkey(dp[i][j] += dp[i - 1][j]);
						else if (j) mkey(dp[i][j] += dp[i - 1][j - 1]);
					} else mkey(dp[i][j] += dp[i - 1][j + 1]);
				}
			}
		}
		
		for (int i = 1; i < MAXN; i++) mkey(ans += dp[n][i] * x % MOD);
	}

	cout << ans << endl;
	return 0;
}