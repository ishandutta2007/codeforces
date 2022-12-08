#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	ll p, q;
	cin >> t;
	while (t--) {
		cin >> p >> q;
		if (p%q != 0LL) {
			cout << p << endl;
			continue;
		}
		ll res = 1LL;
		for (ll x = 2LL; x * x <= q; x+= 1LL) {
			ll nprod = 1LL;
			while (q % x == 0LL) {
				nprod *= x; 
				q /= x;
			}
			if (nprod == 1LL) continue;
			ll cp = p;
			while (cp % nprod == 0LL) {
				cp /= x;
			}
			res = max(res, cp);
		}
		if (q > 1) {
			while (p % q == 0LL) {
				p /= q;
			}
			res = max(res, p);
		}
		cout << res << endl;
	}
}