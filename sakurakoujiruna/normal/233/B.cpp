#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s(ll n) {
	if(n == 0) return 0;
	return n % 10 + s(n / 10);
}

int main() {
	ios :: sync_with_stdio(false);
	ll n; cin >> n;
	ll ans = -1;
	for(int t = 1; t <= 200; t ++) {
		ll l = 1, r = (ll)1e9;
		while(l + 1 < r) {
			ll m = (l + r) / 2;
			if(m * m + t * m - n <= 0) l = m;
			else r = m;
		}
		if(l * l + s(l) * l - n == 0) {
			if(ans == -1) ans = l;
			else if(l < ans) ans = l;
		}
	}
	cout << ans << '\n';
	return 0;
}