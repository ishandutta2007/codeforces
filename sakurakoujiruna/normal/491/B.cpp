#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	ll s[4]; fill(s, s + 4, 1e18);
	int c; cin >> c;
	while(c --) {
		ll x, y; cin >> x >> y;
		s[0] = min(s[0], x + y);
		s[1] = min(s[1], x - y);
		s[2] = min(s[2], -x + y);
		s[3] = min(s[3], -x - y);
	}
	ll ans = 1e18; int aid = -1;
	int h; cin >> h;
	for(int i = 1; i <= h; i ++) {
		ll x, y; cin >> x >> y;
		ll t = max({x + y - s[0], x - y - s[1],
			-x + y - s[2], -x - y - s[3]});
		if(t < ans) {
			ans = t;
			aid = i;
		}
	}
	cout << ans << '\n' << aid << '\n';
	return 0;
}