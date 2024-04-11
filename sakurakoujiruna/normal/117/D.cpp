#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod, u, v;

ll calc(ll n, ll a0, ll tol, ll lim) {
	if(a0 > lim) return 0;
	n = min(n, (lim - a0) / tol + 1);
	ll a = n, b = n - 1;
	if(a % 2 == 0) a /= 2;
	else b /= 2;
	n %= mod; a %= mod; b %= mod; a0 %= mod; tol %= mod;
	return (a0 * n % mod + a * b % mod * tol % mod) % mod;
}

ll solve(ll ql, ll qr, ll sl, ll sr, ll a0, ll tol) {
	if(ql == sl && qr == sr) {
		return (calc(qr - ql + 1, a0, tol, v) -
			calc(qr - ql + 1, a0, tol, u - 1)) % mod;
	}
	ll mid = (sl + sr) / 2;
	if(qr <= mid) return solve(ql, qr, sl, mid, a0, tol * 2);
	else if(ql >= mid + 1) return solve(ql, qr, mid + 1, sr, a0 + tol, tol * 2);
	return (solve(ql, mid, sl, mid, a0, tol * 2) + 
		solve(mid + 1, qr, mid + 1, sr, a0 + tol, tol * 2)) % mod;
}

int main() {
	ios :: sync_with_stdio(false);
	ll n; int m; cin >> n >> m >> mod;
	while(m --) {
		ll l, r; cin >> l >> r >> u >> v;
		cout << (solve(l, r, 1, n, 1, 1) + mod) % mod << '\n';
	}
	return 0;
}