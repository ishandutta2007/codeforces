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

const ll MAXN = 2e3 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll n, m, k, F[MAXN], inv[MAXN], fact[MAXN], T[MAXN][MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

inline ll C(int k, int n) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline ll P(int k, int n) {
	ll ans = 1;
	for (int i = n; i > n - k; i--) ans = ans * i % MOD;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);	

	T[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j <= i; j++) {
			T[i][j] = T[i - 1][j];
			if (j) T[i][j] += T[i - 1][j - 1];
			T[i][j] = T[i][j] * j % MOD;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		ll ans = 0;
		
		ll f = 1;
		for (int i = 1; i <= k; i++) {
			ll tans = T[k][i];
			f = f * (n - i + 1) % MOD;
			tans = tans * f % MOD * inv[i] % MOD;
			ll p_m = poww(m, MOD - 2) * ((m + 1) / 2) % MOD;
			p_m = poww(p_m, i);
			tans = tans * p_m % MOD;
			mkey(ans += tans);
		}

		cout << ans * poww(m, n) % MOD << endl;
	}
	return 0;
}