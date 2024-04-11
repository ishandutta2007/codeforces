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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll inv2 = 500000004;

inline ll Floor(ll n, ll k) {
	if (k == 0) return 0;
	if (k == n) return 1;
	return n / k;
}

inline ll Sum(ll L, ll R) {
	if (R < L) return 0;
	R = R % MOD;
	L = L % MOD;
	return (R * (R + 1) % MOD * inv2 % MOD - L * (L - 1) % MOD * inv2 % MOD + 2 * MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll ans = n % MOD * (m % MOD) % MOD;
	ll sq = sqrt(n);
	for (ll i = 1; n / i > sq && i <= m; i++) ans -= i * Floor(n, i) % MOD, ans += MOD, ans %= MOD;
	for (ll i = sq; i >= 1; i--) {
		ll R = n / i, L = 0;
		if (L > m) continue;
		R = min(R, m);
		L = n / (i + 1) + 1;
		ans -= Sum(L, R) % MOD * i % MOD;
	       	ans += MOD, ans %= MOD;	
	}

	cout << ans << endl;
	return 0;
}