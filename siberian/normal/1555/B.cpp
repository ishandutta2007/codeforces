#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void solve() {
	int W, H;
	cin >> W >> H;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int w, h;
	cin >> w >> h;
	int ans = INT_MAX;
	if (W >= x2 - x1 + w) {
		chkmin(ans, max(0, w - x1));
		chkmin(ans, max(0, x2 - (W - w)));
	}
	if (H >= y2 - y1 + h) {
		chkmin(ans, max(0, h - y1));
		chkmin(ans, max(0, y2 - (H - h)));
	}
	if (ans == INT_MAX) ans = -1;
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}