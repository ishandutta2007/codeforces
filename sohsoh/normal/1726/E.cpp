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
const ll MOD = 998244353;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll f[MAXN], fact[MAXN], inv[MAXN];

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	f[0] = fact[0] = inv[0] = fact[1] = inv[1] = f[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		f[i] = (f[i - 1] + (i - 1) * f[i - 2]) % MOD;
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		ll ans = 0;
		for (int i = 0; i <= n / 4; i++) {
			ans = (ans + C(2 * i, n - 2 * i) * fact[2 * i] % MOD * inv[i] % MOD * f[n - 4 * i] % MOD) % MOD;
		}

		cout << ans << endl;
	}
	return 0;
}