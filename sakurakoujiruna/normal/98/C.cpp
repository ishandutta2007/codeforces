#include <bits/stdc++.h>
using namespace std;

using db = double;
const db pi = 4 * atan(1);

const db eps = 1e-9;
int sgn(db a, db b = 0) {
	a -= b;
	return (a > eps) - (a < -eps);
}

struct poi {
	db x, y;
	poi operator -(poi p) {
		return {x - p.x, y - p.y};
	}
	db cross(poi p) {
		return x * p.y - y * p.x;
	}
	db len() {
		return sqrt(x * x + y * y);
	}
};

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);

	db a, b, l; cin >> a >> b >> l;

	if(l <= min(a, b)) {
		cout << l << '\n';
		return 0;
	} else if(l <= max(a, b)) {
		cout << min(a, b) << '\n';
		return 0;
	}

	auto solve = [&](db ang) {
		poi p = {l * cos(ang), 0};
		poi q = {0, l * sin(ang)};
		return (poi{a, b} - p).cross(q - p) / (q - p).len();
	};

	db left = 0, right = pi / 2;
	for(int _ = 0; _ < 100; _ ++) {
		db mid1 = (left * 2 + right) / 3;
		db mid2 = (left + right * 2) / 3;
		db f1 = solve(mid1), f2 = solve(mid2);
		if(f1 < f2) right = mid2;
		else left = mid1;
	}
	db f = solve(left);
	if(sgn(f) <= 0)
		cout << "My poor head =(\n";
	else
		cout << min(f, l) << '\n';
	return 0;
}