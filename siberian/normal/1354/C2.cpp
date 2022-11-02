#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const ld PI = acos(-1);

void turn(ld & x, ld & y, ld alpha) {
	ld nx = x * cos(alpha) - y * sin(alpha);
	ld ny = x * sin(alpha) + y * cos(alpha);
	x = nx, y = ny;
}

pair<ld, ld> calc(int n, ld base, ld alpha) {
	ld x = 1, y = 0;
	turn(x, y, base);
	ld maxX = 0, minX = 0, maxY = 0, minY = 0;
	n *= 2;
	ld nowX = 0, nowY = 0;
	while (n--) {
		nowX += x, nowY += y;
		turn(x, y, alpha);
		chkmax(maxX, nowX);
		chkmin(minX, nowX);
		chkmax(maxY, nowY);
		chkmin(minY, nowY);
	}
	return {abs(maxX - minX), abs(maxY - minY)};
}

void solve() {
	int n;
	cin >> n;
	ld ans = 1e9;
	ld alpha = (ld)360.0 / (n * 2);
	alpha = alpha / 180 * PI;
	alpha = abs(alpha);

	ld l = 0, r = alpha;
	for (int i = 0; i < 60; i++) {
		ld mid = (l + r) / 2;
		auto have = calc(n, mid, alpha);
		chkmin(ans, max(have.first, have.second));
		if (have.first < have.second) {
			l = mid;
		} else {
			r = mid;
		}
	}

	auto have = calc(n, r, alpha);
	chkmin(ans, max(have.first, have.second));

	cout.precision(20);
	cout.setf(ios::fixed);
	cout << abs(ans) << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}