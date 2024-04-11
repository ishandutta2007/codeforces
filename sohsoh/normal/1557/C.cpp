// Sohsoh84 :)))
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
const ll MOD = 1e9 + 7;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

ll fact[MAXN], inv[MAXN], n, k, dp[MAXN];

ll C(ll k, ll n) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline void solve() {
	cin >> n >> k;
	ll e = 0;
	for (int i = 0; i < n; i += 2) e = (e + C(i, n)) % MOD;

	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		if (n % 2) dp[i] = dp[i - 1];
		else dp[i] = poww(poww(2, i - 1), n);
		dp[i] = (dp[i] + e * dp[i - 1]) % MOD;
	}

	cout << dp[k] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);

	int t;	
	cin >> t;
	while (t--) solve();
	return 0;
}