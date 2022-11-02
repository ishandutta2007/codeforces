#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define M 1000100

using namespace std;

const double ep = 1e-12, pie = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const double &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const double &a) const { return pnt(x / a, y / a); }
	inline double operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline double operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%lf %lf", &x, &y); }
} A, B, C, O[3], p[3];

int gas[3];
double t1, t2, R[3], a, b, c;

double dist(pnt A) {
	return sqrt(A.x * A.x + A.y * A.y);
}

inline pnt rot(pnt p) { return pnt(-p.y, p.x); }

int intersect_circles(pnt c, double r, pnt cc, double rr, pnt p[]) {
	double d = dist(c - cc);
	if (r + rr < d - ep || r + d < rr - ep || rr + d < r - ep) return 0;
	double x = (r * r - rr * rr + d * d) / (d * 2);
	pnt cp = (c * (d - x) + cc * x) / d;
	if (fabs(r + rr - d) < ep || fabs(r + d - rr) < ep || fabs(rr + d - r) < ep) {
		p[0] = cp; return 1;
	}
	double h = sqrt(r * r - x * x);
	pnt dv = rot(cc - c) * h / d ;
	p[0] = cp - dv;
	p[1] = cp + dv;
	return 2;
}

bool include_cyc_pnt(pnt O, double R, pnt A) {
	return dist(A - O) < R + ep;
}

bool include(pnt A, double R, pnt B, double r) {
	return dist(A - B) + r < R + ep;
}

bool good(pnt A, double R, pnt B, double r) {
	if (include(A, R, B, r) || include(B, r, A, R)) return 1;
	return intersect_circles(A, R, B, r, p);
}

bool common(pnt A, double r1, pnt B, double r2, pnt C, double r3) {
	O[0] = A, O[1] = B, O[2] = C;
	R[0] = r1, R[1] = r2, R[2] = r3;
	for (int i = 0; i < 3; i ++) {
		int j = (i + 1) % 3, k = (i + 2) % 3;
		if (include(O[j], R[j], O[k], R[k])) {
			if (good(O[i], R[i], O[k], R[k])) return 1;
			continue;
		}
		if (include(O[k], R[k], O[j], R[j])) {
			if (good(O[i], R[i], O[j], R[j])) return 1;
			continue;
		}
		int d = intersect_circles(O[j], R[j], O[k], R[k], p);
		if (!d) continue;
		for (int r = 0; r < d; r ++) if (include_cyc_pnt(O[i], R[i], p[r])) return 1;
	}
	return 0;
}

bool ok(double R) {
	if (R > b) {
		double r = R - b, d = max(0., a - r);
		if (R + d < c + t2 + ep && R + d < b + a + t1 + ep) return 1;
	}
	double r1 = c + t2 - R, r2 = b + t1 - R;
	return common(A, R, B, r1, C, r2);
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%lf %lf", &t1, &t2);
	A.input();
	B.input();
	C.input();

	a = dist(B - C), b = dist(C - A), c = dist(A - B);

	double st = 0, en = min(c + t2, b + a + t1);
	while (en - st > ep) {
		double mid = (st + en) / 2;
		if (ok(mid)) st = mid;
		else en = mid;
	}
	printf("%lf\n", st);
	return 0;
}