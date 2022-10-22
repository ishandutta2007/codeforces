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

const ll ROOT = 3;
const ll MOD = 998244353;
const ll MAXN = (1 << 20);

ll rev[MAXN], A[MAXN], n, k;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
} 

inline void NTT(ll* A, int n, bool inv) {
	int lg = __builtin_ctz(n);
	for (int i = 1; i < n; i++) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if (rev[i] < i) swap(A[i], A[rev[i]]);
	}

	for (int len = 1; len < n; len <<= 1) {
		ll wn = poww(ROOT, MOD / 2 / len);
		if (inv) wn = poww(wn, MOD - 2);

		for (int i = 0; i < n; i += 2 * len) {
			ll w = 1;
			for (int j = i; j < i + len; j++) {
				ll x = A[j], y = w * A[j + len];
				A[j] = (x + y) % MOD;
				A[j + len] = (x - y + MOD) % MOD;
				w = w * wn % MOD;
			}
		}
	}

	if (inv) {
		ll n_inv = poww(n, MOD - 2);
		for (int i = 0; i < n; i++)
			A[i] = A[i] * n_inv % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		A[x]++;
	}

	NTT(A, MAXN, false);
	for (int i = 0; i < MAXN; i++) A[i] = poww(A[i], n / 2);
	NTT(A, MAXN, true);

	ll ans = 0;
	for (int i = 0; i < MAXN; i++)
		ans += A[i] * A[i] % MOD;
	cout << ans % MOD << endl;
	return 0;
}