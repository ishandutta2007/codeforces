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
#define debug(x)                    cerr << #x << ": " <<x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll cnt[MAXN], n, ps[MAXN], m, k, fact[MAXN], inv[MAXN];

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int solve() {
	for (int i = 0; i < n + 10; i++) cnt[i] = ps[i] = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + cnt[i];
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll t = ps[min(n, i + k)] - ps[i - 1];
		ll tw = t - cnt[i];
		ans += C(m, t) - C(m, tw);
		if (ans < 0) ans += MOD;
		else if (ans >= MOD) ans -= MOD;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2, MOD);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}