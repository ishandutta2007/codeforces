#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-9;

void solve() {
	cout.precision(14);
	cout << fixed;
	ld x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ld d = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d > r1 + r2 - EPS) {
		cout << "0\n";
		return;
	}
	if (r1 + d - EPS < r2) {
		cout << atan2l(0, -1) * r1 * r1 << "\n";
		return;
	}
	if (r2 + d - EPS < r1) {
		cout << atan2l(0, -1) * r2 * r2 << "\n";
		return;
	}
	ld a = 2 * acosl((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
	ld b = 2 * acosl((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
	cout << 0.5 * (r1 * r1 * (a - sinl(a)) + r2 * r2 * (b - sinl(b))) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 2;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}