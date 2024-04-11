#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(0);
	int q; cin >> q;
	while(q --) {
		ll n; cin >> n;
		ll l = 0, r = n;
		while(l + 1 < r) {
			ll m = (l + r) / 2;
			if(m < (n - m) * (n - m - 1) / 2)
				l = m;
			else
				r = m;
		}
		ll ans = 2 * l;
		if(l != n - 1)
			ans = max(ans, l + 1 + (n - l - 1) * (n - l - 2) / 2);
		cout << ans << '\n';
	}
}