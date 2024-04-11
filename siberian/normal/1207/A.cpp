#include <bits/stdc++.h>

using namespace std;

void solve() {
	int b, p, f, h, c;
	cin >> b >> p >> f >> h >> c;
	if (h < c) {
		swap(h, c);
		swap(p, f);
	}
	int ans = 0;
	int cnt_h = min(b / 2, p);
	ans += cnt_h * h;
	b -= cnt_h * 2;
	p -= cnt_h;

	int cnt_c = min(b / 2, f);
	ans += cnt_c * c;
	cout << ans << "\n";
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}