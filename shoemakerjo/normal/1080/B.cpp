#include <bits/stdc++.h>

using namespace std;
#define maxn 1010
#define ll long long
int q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> q;

	ll l, r;
	while (q--) {
		cin >> l >> r;
		ll numpairs = (r-l+1)/2;
		ll tp = 1;
		if (l % 2 == 0) tp = -1;

		ll ans = numpairs*tp;
		if (numpairs*2 != (r-l+1)) {
			if (r % 2 == 0) ans += r;
			else ans += 0-r;
		}
		cout << ans << '\n';
	}
	cout.flush();
	// cout << ans << endl;
}