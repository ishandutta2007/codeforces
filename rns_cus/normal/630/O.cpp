#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define M 1000100
#define X first
#define Y second

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
	inline void input() { x = y = 0, scanf("%lf %lf\n", &x, &y); }
	inline void print() { printf("%.12lf %.12lf\n", x, y); }
} O, p[8], v;

double a, b, c, d;

inline pnt rot(pnt p) { return pnt(-p.y, p.x); }

inline double dist(pnt a) { return sqrt(a & a); }

int main() {
//	freopen("o.in", "r", stdin);
	scanf("%lf %lf %lf %lf", &O.x, &O.y, &v.x, &v.y);
	double L = dist(v);
	v.x /= L, v.y /= L;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	p[0] = O + (v * b);
	p[1] = O + (rot(v) * a / 2);
	p[2] = O + (rot(v) * c / 2);
	p[3] = p[2] + (rot(rot(v)) * d);
	p[4] = p[3] + (rot(rot(rot(v))) * c);
	p[5] = O + (rot(rot(rot(v))) * c / 2);
	p[6] = O + (rot(rot(rot(v))) * a / 2);
	for (int i = 0; i < 7; i ++) p[i].print();
	return 0;
}