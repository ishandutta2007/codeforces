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

const ll MAXN = 600 + 10;
ll MOD, n, m, fact[MAXN];

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll inv(ll a) {
	return poww(a, MOD - 2);
}

inline ll F(ll m, ll n) {
	if (m == 0) return 1;
	if (m < 0 || m > n) return 0;
	return poww(n + 1, m) * poww(2, m) % MOD * (n - m + 1) % MOD * inv(n + 1) % MOD;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> m >> MOD;
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD;

	
	// m == n
	// m == n - 1

	ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		for (ll j = 0; j < i; j++) {
			ans += j * (j + 1) % MOD  % MOD * C(j, i - 1) % MOD 
				* poww(2, m - i) % MOD * poww(n + 1, m - i) % MOD
				* F(j, j) % MOD * F(i - j - 1, n - j - 1) % MOD;
		}
	}

	cout << ans % MOD * (n - m + 1) % MOD << endl;
	return 0;
}