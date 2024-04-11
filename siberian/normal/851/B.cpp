#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

struct pt{
	int x, y;
	pt() {}
	pt(int a, int b) {
		x = a, y = b;
	}
};

int dist(pt a, pt b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct line{
	int a, b, c;
	line() {}
	line(pt x, pt y) {
		a = y.y - x.y;
		b = x.x - y.x;
		c = x.y * y.x - x.x * y.y;
	}
};

/*
bool check_cross(line l, line m) {
	ld d = l.b * m.a - l.a * m.b;
	return sign(d) != 0;
}

*/

bool check(line l, line m) {
	int d = l.b * m.a - l.a * m.b;
	return d != 0;
}

void solve() {
	pt a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	line l = line(a, b), m = line(b, c);
	if (check(l, m) && dist(a, b) == dist(b, c)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
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