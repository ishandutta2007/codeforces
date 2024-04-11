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
const ll MOD = 998244353; // 1e9 + 9;

ll D[MAXN], pref[MAXN] = {0};

void mkey(ll& a) {
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	D[0] = 0;
	for (int i = 1; i <= n; i++) cin >> D[i];
	sort(D + 1, D + n + 1);
	for (int i = 1; i <= n; i++) mkey(pref[i] = pref[i - 1] + D[i]);

	while (m--) {
		ll a, b;
		cin >> a >> b;
		ll L = 0, R = n;
		while (L < R) {
			ll mid = (L + R + 1) / 2;
			if (D[mid] < b) L = mid;
			else R = mid - 1;
		}

		ll k = n - L, ans = 0;
		if (a > k) {
			cout << 0 << endl;
			continue;
		}

		ll C = (k - a) * poww(k, MOD - 2, MOD) % MOD;
		ans += C * ((pref[n] - pref[L] + MOD) % MOD);
		ans %= MOD;
		C = (k + 1 - a) * poww(k + 1, MOD - 2, MOD) % MOD;
		ans += C * pref[L] % MOD;
	       	ans %= MOD;	
		cout << ans << endl;
	}

	// Salam
	return 0;
}