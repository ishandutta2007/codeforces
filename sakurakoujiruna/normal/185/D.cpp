#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll qpow(ll a, ll b, ll p) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % p;
		a = a * a % p;
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(0);
	int t; cin >> t;
	while(t --) {
		ll k, l, r, p;
		cin >> k >> l >> r >> p;

		auto f = [&](ll i) {
			return qpow(k, qpow(2, i, p - 1) + p - 1, p);
		};

		if(p == 2) {
			if(k & 1) cout << 0 << '\n';
			else cout << 1 << '\n';
		} else if(k == 1)
			cout << 2 << '\n';
		else {
			if(f(l) == 1) {
				ll ans = 2;
				if(k & 1 ^ 1)
					ans = ans * qpow(2, r - l, p) % p;
				cout << ans << '\n';
			} else {
				ll ans = (f(r + 1) - 1 + p) * qpow((f(l) - 1 + p) % p, p - 2, p) % p;
				if(k & 1)
					ans = ans * qpow(qpow(2, r - l, p), p - 2, p) % p;
				cout << ans << '\n';
			}
		}
	}
}