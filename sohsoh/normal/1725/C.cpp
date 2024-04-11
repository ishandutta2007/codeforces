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

int n, m, t, r;
ll ps[MAXN], fact[MAXN], inv[MAXN];

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		ps[i] = ps[i - 1] + x;
	}

	for (int i = 0; i < n; i++)
		if (ps[n] % 2 == 0 && *lower_bound(ps, ps + n, (ps[i] + ps[n] / 2) % ps[n]) == (ps[i] + ps[n] / 2) % ps[n])
			t++;

	r = n - t;	
	t /= 2;

	ll ans = 0;
	for (int k = 0; k <= t; k++) {
		(ans += C(k, m) * C(k, t) % MOD * fact[k] % MOD * poww(m - k, r) % MOD *
		 	poww(1ll * (m - k) * (m - k - 1) % MOD, t - k)) %= MOD;
	}

	cout << ans << endl;
	return 0;
}