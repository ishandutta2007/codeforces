#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e5 + 10;
const ll MOD = 998244353;

ll A[MAXN], n, pw[MAXN], fact[MAXN], inv[MAXN];

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
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

inline ll f(ll a, ll b) {
	ll ans = 0;
	for (int i = 0; i <= a; i++)
		ans += C(i, a) * C(i, b) % MOD;
	return ans % MOD;
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	if (n == 1) return cout << 1 << endl, 0; // check
	if (*max_element(A + 1, A + n + 1) == 0) return cout << pw[n - 1] << endl, 0;


	A[0] = A[n + 1] = 1;
	ll ans = 0, pl = 0, pr = n + 1, sl = 0, sr = 0;

	int cpl = 0, cpr = 0;
	while (!A[pl + 1]) pl++, cpl++;
	while (!A[pr - 1]) pr--, cpr++;

	ans = f(cpl, cpr);

	while (pl < pr) {
		sl += A[++pl];
		while (sl != sr) {
			if (sl < sr) sl += A[++pl];
			else sr += A[--pr];
		}
		
		if (pl >= pr) break;
		
		int tpl = pl + 1, tpr = pr - 1;
		while (!A[tpl]) tpl++;
		while (!A[tpr]) tpr--;

		if (tpl <= tpr) ans = ans * f(tpl - pl, pr - tpr) % MOD;
		else ans = ans * pw[pr - pl] % MOD;

		pl = tpl - 1;
		pr = tpr + 1;
	}

	cout << ans << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}

	pw[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pw[i] = pw[i - 1] * 2 % MOD;

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}