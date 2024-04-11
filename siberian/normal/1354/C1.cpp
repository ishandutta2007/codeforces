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

void solve() {
	int n;
	cin >> n;
	ld ans = 0;
	ld x = 1, y = 0;
	ld alpha = (ld)360.0 / (n * 2);
	alpha = alpha / 180 * PI;
	alpha = abs(alpha);
	while (n--) {
		turn(x, y, alpha);
		ans += y;
	}
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