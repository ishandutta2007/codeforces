#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 11;
using ll = long long;
const ll Mod = ll(1e9) + 7;

int p[N], q[N];
ll fac[N], inv[N];
ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b > 0; b /= 2) {
		if(b & 1)
			r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

ll comb(int n, int m) {
	return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int main() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i] * inv[i - 1] % Mod;
	}
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> q[i];
	for(int i = 1; i <= n; i ++)
		if(q[i])
			p[q[i]] = i;
	/*
	for(int i = 1; i <= n; i ++)
		cout << i << ' ' << p[i] << '\n';
		*/

	if(count(p + 1, p + n + 1, 0) == n)
		cout << qpow(2, n - 1) << '\n';
	else {
		int last = -1;
		for(int i = 1; i <= n; i ++) if(p[i]) {
			last = p[i];
			break;
		}
		int l = 1, r = n;
		ll ans = 1;
		for(int i = n; i >= 1; i --) if(p[i]) {
			if(p[i] != last) {
				int nxt_l, nxt_r;
				if(p[i] < last) {
					nxt_l = p[i];
					nxt_r = p[i] + i - 1;
				} else {
					nxt_r = p[i];
					nxt_l = p[i] - i + 1;
				}
				if(nxt_l < l || nxt_r > r)
					ans = 0;
				else {
					ans *= comb(r - l + 1 - (nxt_r - nxt_l + 1), nxt_l - l);
					ans %= Mod;
				}
				l = nxt_l; r = nxt_r;
				if(l == p[i]) l ++;
				else r --;
			} else {
				ll tmp = ans; ans = 0;
				auto solve = [&](int nxt_l, int nxt_r) {
					if(nxt_l >= l && nxt_r <= r)
						ans += tmp * comb(r - l + 1 - (nxt_r - nxt_l + 1), nxt_l - l);
				};
				solve(p[i] - i + 1, p[i]);
				if(i != 1)
					solve(p[i], p[i] + i - 1);
				ans %= Mod;
				if(i > 2)
					ans *= qpow(2, i - 2);
				ans %= Mod;
			}
		}
		cout << ans % Mod << '\n';
	}
	return 0;
}