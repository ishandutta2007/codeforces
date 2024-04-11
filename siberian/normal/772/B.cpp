#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct point{
	ld x, y;
	point() {}
	point(ld _x, ld _y) {
		x = _x, y = _y;
	}
};

point operator-(const point & a, const point & b) {
	return point(a.x - b.x, a.y - b.y);
}

ld dist(point a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

ld dist(point a, point b) {
	return dist(a - b);
}

struct line{
	ld a, b, c;
	line() {}
	line(point x, point y) {
		a = y.y - x.y;
		b = x.x - y.x;
		c = x.y * y.x - x.x * y.y;
	}
};

ld dist(point a, line l) {
	return abs(l.a * a.x + l.b * a.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

void solve() {
	int n;
	cin >> n;
	vector<point> p(n);
	for (auto &i : p)
		cin >> i.x >> i.y;
	ld ans = 1e18;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			chkmin(ans, dist(p[i], p[j]));
		}
	}
	for (int i = 0; i < n; i++) {
		int j = (i + 2) % n;
		line l(p[i], p[j]);
		for (int x = 0; x < n; x++) {
			if (x == i || x == j) continue;
			chkmin(ans, dist(p[x], l) / 2);
		}
	}
	cout.precision(20);
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}