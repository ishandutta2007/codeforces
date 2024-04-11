#include <bits/stdc++.h>

using namespace std;
using db = long double;
const db eps = 1e-5;
const db pi = acos(-1);

db sqr(db x) { return x * x; }

struct vec {
	db x{}, y{};

	vec operator+(vec &o) const { return {x + o.x, y + o.y}; }

	vec operator-(vec &o) const { return {x - o.x, y - o.y}; }

	vec operator*(db m) const { return {x * m, y * m}; }

	vec operator/(db m) const { return {x / m, y / m}; }

	db operator*(vec &o) const { return x * o.x + y * o.y; }

	void read() { scanf("%Lf%Lf", &x, &y); }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	vec a, b, c;
	a.read(), b.read(), c.read();
	vec ab = a - b, bc = b - c;
	vec mab = (a + b) / 2.0, mbc = (b + c) / 2.0;
	db a1 = ab.x, b1 = ab.y, c1 = -a1 * mab.x - b1 * mab.y;
	db a2 = bc.x, b2 = bc.y, c2 = -a2 * mbc.x - b2 * mbc.y;
	db ox = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1), oy = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
	vec o = {ox, oy}, oa = o - a, ob = o - b, oc = o - c;
	db r2 = sqr(oa.x) + sqr(oa.y);
	db aob = acos(oa * ob / r2), boc = acos(ob * oc / r2), coa = acos(oc * oa / r2);
	for (int i = 3; i < 105; ++i) {
		db t = 2 * pi / i;
		db p1 = aob / t, p2 = boc / t, p3 = coa / t;
		int pp1 = round(p1), pp2 = round(p2), pp3 = round(p3);
		if (abs(p1 - pp1) < eps && abs(p2 - pp2) < eps && abs(p3 - pp3) < eps) {
			db s = i * sin(t) * r2 / 2;
			printf("%.15Lf\n", s);
			return 0;
		}
	}
	return -1;
}