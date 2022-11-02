#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	int c1, c2, x, y;
	cin >> c1 >> c2 >> x >> y;
	if(x == y) {
		ll l = 1, r = 1e14;
		while(l + 1 < r) {
			ll m = (l + r) / 2;
			if((m - 1) - (m - 1) / x >= c1 + c2)
				r = m;
			else
				l = m;
		}
		cout << l << '\n';
	} else {
		ll l = 1, r = 1e14;
		while(l + 1 < r) {
			ll m = (l + r) / 2;
			ll cxy = (m - 1) - (m - 1) / x - (m - 1) / y + (m - 1) / x / y;
			ll cx = (m - 1) / y - (m - 1) / x / y;
			ll cy = (m - 1) / x - (m - 1) / x / y;
			cx = min(cx, ll(c1));
			cy = min(cy, ll(c2));
			if(cx + cy + cxy >= c1 + c2)
				r = m;
			else
				l = m;
		}
		cout << l << '\n';
	}
	return 0;
}