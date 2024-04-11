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

const ll MAXN = 20 + 10;
const ll MOD = 1e9 + 7;

ll ans = 0, inv[MAXN], A[MAXN], n, s;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}	

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	k = min(k, n - k);

	ll ans = 1;
	for (int i = 0; i < k; i++) {
		ans = (n - i) % MOD * ans % MOD;
		ans = ans * inv[i + 1] % MOD;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) inv[i] = poww(i, MOD - 2);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> A[i];

	ll ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		ll f = s + n - 1;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				f -= A[i] + 1;
	
		int p = (__builtin_popcount(mask) % 2 == 0 ? 1 : -1);
		ans = (ans + p * C(n - 1, f) + MOD) % MOD;
	}

	cout << ans << endl;
	return 0;
}