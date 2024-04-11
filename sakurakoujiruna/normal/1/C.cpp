#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define double long double
const double Eps = 1e-6;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return Point{x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return Point{x + p.x, y + p.y};
	}
	Point operator /(double d) {
		return Point{x / d, y / d};
	}
	Point rotate(double arg) {
		double tx = x * cos(arg) - y * sin(arg);
		double ty = y * cos(arg) + x * sin(arg);
		return Point{tx, ty};
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	double arg() {
		double ret = atan2(y, x);
		if(ret < 0)
			ret += 2 * Pi;
		return ret;
	}
	double length() {
		return sqrt(x * x + y * y);
	}
};

double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

Point line_inter(Point p1, Point p2, Point q1, Point q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double ret_x = (q1.x * v + q2.x * u) / (v + u);
	double ret_y = (q1.y * v + q2.y * u) / (v + u);
	return Point{ret_x, ret_y};
}

int main()
{
	ios :: sync_with_stdio(false);
	Point a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	Point p1 = (a + b) / 2;
	Point p2 = p1 + (b - a).rotate(Pi / 2);
	Point q1 = (b + c) / 2;
	Point q2 = q1 + (c - b).rotate(Pi / 2);

	Point o = line_inter(p1, p2, q1, q2);
	double r = (a - o).length();

	double arg1 = (a - o).arg() - (b - o).arg();
	double arg2 = (a - o).arg() - (c - o).arg();
	for(int n = 3; n <= 100; n ++)
	{
		double e = 2 * Pi / n;
		if(sgn(arg1, e * round(arg1 / e)) == 0 &&
			sgn(arg2, e * round(arg2 / e)) == 0)
		{
			cout << fixed << setprecision(12) << n * r * r * sin(e) / 2 << '\n';
			break;
		}
	}
	return 0;
}