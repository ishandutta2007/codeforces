#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-8, pi = acos(-1);

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
	void FastInput() {
		int a, b;
		scanf("%d %d", &a, &b);
		x = 1.0 * a;
		y = 1.0 * b;
	}
	inline void print() { printf("%lf %lf\n", x, y); }
	inline bool operator < (const pnt &a) const {
		if (fabs(x - a.x) > ep) return x < a.x;
		return y < a.y;
	}
	inline bool operator == (const pnt &a) const {
		return fabs(x - a.x) < ep && fabs(y - a.y) < ep;
	}
	inline pnt Rotate(const double &angle) {
		pnt R = pnt(sin(angle), cos(angle)), C = *this;
		return pnt(C ^ R, C & R);
	}
	inline double dist() { return sqrt(x * x + y * y); }
	inline pnt norm() { return (*this) / dist(); }
} A, B, C;

double area(pnt A, pnt B, pnt C) {
	return (A ^ B) + (B ^ C) + (C ^ A);
}

int main() {
//	freopen("a.in", "r", stdin);
	A.input(), B.input(), C.input();
	double s = area(A, B, C);
    if (abs(s) < ep) puts("TOWARDS");
    else if (s < -ep) puts("RIGHT");
    else puts("LEFT");
    return 0;
}