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
 
const ll MAXM = 1e3 + 10;
const ll MAXN = 50 + 3;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fact[MAXM], inv[MAXM];
int dp[MAXN][MAXM][MAXM]; // n, sum, last

void mkey(int& a) {
	if (a >= MOD) a -= MOD;
}

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
}

void fill_ps(ll ind) {
	for (int i = 0; i < MAXM; i++) {
		for (int j = 1; j < MAXM; j++) mkey(dp[ind][i][j] += dp[ind][i][j - 1]);
	}
}

ll nCr(ll r, ll n) {
	if (r > n || r < 0) return 0;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int j = 0; j < MAXM; j++) dp[1][j][j] = 1;
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXM; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD);
	
	fill_ps(1);
	for (int i = 2; i < MAXN; i++) {
		for (int j = 1; j < MAXM; j++) for (int k = 1; k <= j; k++) dp[i][j][k] = dp[i - 1][j - k][k - 1];
		fill_ps(i);
	}


	ll q;
	cin >> q;
	while (q--) {
		ll k, n;
		cin >> n >> k;
		if (k > 50) {
			cout << 0 << endl;
			continue;
		}


		ll ans = 0;
		for (int s = 0; s <= n; s++) {
			ll tans = dp[k][s][MAXM - 1] * fact[k] % MOD;
			tans *= nCr(k, n - s);
			mkey(ans += tans % MOD);
		}

		cout << ans << endl;
	}
	return 0;
}