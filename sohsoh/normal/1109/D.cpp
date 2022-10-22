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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fact[MAXN], inv[MAXN], n, m, a, b;

ll C(ll k, ll n) {
	if (k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

ll cayley(ll n, ll k) {
	if (k == n) return 1;
	return k * poww(n, n - k - 1, MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD) % MOD;
	cin >> n >> m >> a >> b;
	ll ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		ll vert = C(i - 1, n - 2) * fact[i - 1] % MOD;
		ll edges = C(i - 1, m - 1);
		ll tans = vert * edges % MOD;
		tans %= MOD;
		tans *= cayley(n, i + 1);
		tans %= MOD;
		tans *= poww(m, n - 1 - i, MOD);
		tans %= MOD;
		ans += tans;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}