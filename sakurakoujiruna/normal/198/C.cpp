#include <bits/stdc++.h>
using namespace std;

const double Eps = 1e-12;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator *(double d) {
		return {x * d, y * d};
	}
	Point rotate(double arg) {
		double tx = x * cos(arg) - y * sin(arg);
		double ty = y * cos(arg) + x * sin(arg);
		return Point{tx, ty};
	}
	double dot(Point p) {
		return x * p.x + y * p.y;
	}
	double len2() {
		return dot(*this);
	}
	double len() {
		return sqrt(len2());
	}
	double arg() {
		double ret = atan2(y, x);
		if(sgn(ret) < 0)
			ret += 2 * Pi;
		return ret;
	}
	Point foot(Point p, Point q) {
		double sh = (q - p).dot(*this - p);
		if(sgn((q - p).len2()) == 0)
			return p;
		sh /= (q - p).len2();
		return p + (q - p) * sh;
	}
	vector <Point> tangent(Point o, double r) {
		vector <Point> ret;
		double d = (o - *this).len();
		if(sgn(d, r) <= 0)
			return ret;
		double a = asin(r / d);
		Point v = (o - *this) * (sqrt(d * d - r * r) / d);
		ret.push_back(*this + v.rotate(-a));
		ret.push_back(*this + v.rotate(a));
		return ret;
	}
};

double solve(Point p, Point q, double r)
{
	Point f = Point{0, 0}.foot(p, q);
	if(f.len() > r || (p - f).dot(q - f) > 0)
		return (p - q).len();
	auto v1 = p.tangent({0, 0}, r);
	auto v2 = q.tangent({0, 0}, r);
	double ret = 1e10;
	for(auto pp : v1)
		for(auto qq : v2)
		{
			double tmp = (pp - p).len() + (qq - q).len();
			double app = pp.arg();
			double aqq = qq.arg();
			double sub = app - aqq;
			if(sgn(sub) < 0)
				sub += 2 * Pi;
			sub = min(sub, 2 * Pi - sub);
			ret = min(ret, tmp + sub * r);
		}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	double xd, yd, vd;
	cin >> xd >> yd >> vd;
	double rd = Point{xd, yd}.len();
	double wd = vd / rd;

	Point p;
	double v, r;
	cin >> p.x >> p.y >> v >> r;

	double left = 0, right = 1e6;
	for(int _ = 0; _ < 50; _ ++)
	{
		double mid = (left + right) / 2;
		double ad = Point{xd, yd}.arg() + mid * wd;
		Point d = Point{rd * cos(ad), rd * sin(ad)};
		if(solve(p, d, r) / v < mid)
			right = mid;
		else
			left = mid;
	}
	cout << setprecision(8) << left << '\n';
	return 0;
}