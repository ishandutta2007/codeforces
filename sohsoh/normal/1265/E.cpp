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
const ll MOD = 998244353; // 1e9 + 9;

ll pref[MAXN], n, P[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	pref[0] = 1;
	
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		P[i] = P[i] * poww(100, MOD - 2, MOD) % MOD;
		pref[i] = pref[i - 1] * P[i] % MOD;
		if (i != n) ans += pref[i];
		ans %= MOD;
	}

	ans = poww(pref[n], MOD - 2, MOD) * ans % MOD;
	cout << ans << endl;
	return 0;
}