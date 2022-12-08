#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x1, y1, z1, x2, y2, z2;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	int ans = 0;
	int t;
	t = min(z1, y2);
	ans += 2 * t;
	z1 -= t;
	y2 -= t;
	ans -= 2 * max(0, z2 - z1 - x1);
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}