#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define double long double

const double Pi = 4 * atan(1);

struct Point
{
	double x, y;
	Point(double a)
	{
		x = cos(a);
		y = sin(a);
	}
	Point(double x, double y) : x(x), y(y) { }
	Point operator -(const Point &rhs) const
	{
		return Point(x - rhs.x, y - rhs.y);
	}
	double length() { return sqrt(x * x + y * y); }
	double cross(const Point &rhs) const
	{
		return x * rhs.y - y * rhs.x;
	}
};

int main()
{
	int n;
	double r;
	cin >> n >> r;
	double sp = 2 * Pi / n * (n / 2) / 2;
	double sp2 = 2 * Pi / n * (n / 2 - 1) / 2;
	//cout << sp << ' ' << sp2 << '\n';
	double big = r * sin(sp);
	double small = r * cos(sp) * tan(sp2);
	//cout << big << ' ' << small << '\n';
	double rr = big - small;
	//double a1 = Pi / n;
	//double a2 = Pi / 2 - 2 * Pi / n;
	/*
	double p0 = Point(1, 0);
	double p1 = Point(2 * Pi / n * (n / 2));
	double p2 = Point(2 * Pi / n * (n / 2 + 1));
	p1 = p1 - p0;
	p2 = p2 - p0;
	double a2 = acos(p1.cross(p2) / p1.length() / p2.length());
	*/
	double aa = Pi - sp2 * 2;
	/*
	cout << aa << '\n';
	double ans = rr * rr * (aa) / 2;
	*/
	//cout << Pi * r * r << ' ' << ans * n << '\n';
	double t1 = r * r * sin(2 * Pi / n) / 2;
	double t2 = rr * rr * sin(aa) / 2;
	double s = r * r * Pi / n;
	double ans = s - t1 + t2;
	cout << setprecision(12) << Pi * r * r - ans * n << '\n';
	return 0;
}