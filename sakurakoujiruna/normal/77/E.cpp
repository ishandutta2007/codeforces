#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct Point {
	ld x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
};

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	while(t --) {
		ld R, r, k;
		cin >> R >> r >> k;
		ld a = 2 * R;
		ld b = 2 * R * R / r;
		ld m = (a + b) / 2;
		ld y = (b - a) * k;
		ld d = Point{m, y}.len();
		ld r1 = 4 * R * R / (d + (m - a));
		ld r2 = 4 * R * R / (d - (m - a));
		cout << (r2 - r1) / 2 << '\n';
	}
	return 0;
}