#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const double Eps = 1e-12;
int sgn(double a, double b = 0.0)
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
	Point rotate(double a) {
		double nx = x * cos(a) - y * sin(a);
		double ny = y * cos(a) + x * sin(a);
		return {nx, ny};
	}
	double length() {
		return sqrt(x * x + y * y);
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	vector <Point> tangent(Point o, double r) {
		vector <Point> ret;
		double d = (o - *this).length();
		if(sgn(d, r) <= 0)
			return ret;
		double a = asin(r / d);
		Point v = (o - *this) * (sqrt(d * d - r * r) / d);
		ret.push_back(*this + v.rotate(-a));
		ret.push_back(*this + v.rotate(a));
		return ret;
	}
};

double xmul(Point a, Point b, Point c) {
	return (b - a).cross(c - a);
}

Point line_inter(Point p1, Point p2, Point q1, Point q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double rx = (q1.x * v + q2.x * u) / (v + u);
	double ry = (q1.y * v + q2.y * u) / (v + u);
	return {rx, ry};
}

int main()
{
	ios :: sync_with_stdio(false);
	double y1, y2, yw, xb, yb, r;
	cin >> y1 >> y2 >> yw;
	cin >> xb >> yb >> r;

	Point ball{xb, 2 * (yw - r) - yb};
	vector <Point> v2 = ball.tangent(Point{0, y2}, r);
	for(auto &p : v2)
		if(sgn(ball.x, p.x) == 0)
			p = {0, -1};
		else
			p = line_inter(ball, p, {0, 0}, {0, 1});

	double d1 = y1 + r;
	double d2 = min(v2[0].y, v2[1].y);

	if(sgn(d1, d2) > 0)
		cout << -1 << '\n';
	else
	{
		double d = (d1 + d2) / 2;
		double u1 = yw - r - d;
		double u2 = yw - r - yb;
		cout << setprecision(10) << xb * u1 / (u1 + u2) << '\n';
	}
	return 0;
}