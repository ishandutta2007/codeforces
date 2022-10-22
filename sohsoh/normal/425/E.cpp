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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k;
ll dp[MAXN][MAXN], tpow[MAXN * MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < MAXN; i++) dp[i][0] = 1;
       	tpow[0] = 1;
	for (int i = 1; i < MAXN * MAXN; i++) tpow[i] = (tpow[i - 1] << 1) % MOD;	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int e = 1; e <= i; e++) {
				ll t = (tpow[e * (i - e + 1)] - tpow[e * (i - e)] + MOD) % MOD;
				dp[i][j] += t * (dp[i - e][j - 1]) % MOD;
			}	

			dp[i][j] %= MOD;
		}
	}

	cout << dp[n][k] << endl;
	return 0;
}