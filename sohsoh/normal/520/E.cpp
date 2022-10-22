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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll fact[MAXN], inv[MAXN], ps[MAXN], n, k;
string s;

ll C(ll r, ll n) {
	if (r > n || r < 0) return 0;
       	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD);
	cin >> n >> k >> s;

	for (int i = 0; i < n - 1; i++) ps[i] = ps[i - 1] + poww(10, i, MOD) * C(k - 1, n - 2 - i) % MOD;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n) ans += ps[n - 2 - i] * (s[i] - '0') % MOD;
		ans += poww(10, n - i - 1, MOD) * C(k, i) % MOD * (s[i] - '0') % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}