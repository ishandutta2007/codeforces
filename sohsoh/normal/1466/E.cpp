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
#define int	                    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1ll : (b & 1ll ? a * poww(a * a % md, b / 2ll, md) % md : poww(a * a % md, b / 2ll, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 62;

ll BT[LOG], n, A[MAXN], pw[LOG];

inline int solve() {
	memset(BT, 0, sizeof BT);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		A[i] = x;
		int j = 0;
		while (x > 0) {
			if (x & 1ll) BT[j]++;
			x >>= 1ll;
			j++;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll B = A[i];
		ll SBC = 0;
		for (ll j = 0; j < LOG; j++) {
			if (B & (1ll << j)) {
				SBC += pw[j] % MOD * BT[j] % MOD; 
				SBC %= MOD;
			}
		}

		for (ll j = 0; j < LOG; j++) {
			if (B & (1ll << j)) {
				ans += n * pw[j] % MOD * SBC % MOD;
			} else {
				ans += BT[j] * pw[j] % MOD * SBC % MOD;
			}
			ans %= MOD;
		}
	}

	cout << ans % MOD << endl;
	
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < LOG; i++) pw[i] = pw[i - 1] * 2ll % MOD;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}