#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const long double Eps = 1e-6;
int sgn(long double a, long double b = 0.0)
{
	a -= b;
	if(a > Eps)
		return 1;
	if(a < -Eps)
		return -1;
	return 0;
}
const long double Pi = 4 * atan(1);

struct Point
{
	long double x, y;
	Point() { }
	Point(long double x, long double y) : x(x), y(y) { }
	Point operator -(const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
	Point operator +(const Point &p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator *(const long double &d) const
	{
		return Point(x * d, y * d);
	}
	Point operator /(const long double &d) const
	{
		return Point(x / d, y / d);
	}
	long double length() const
	{
		return sqrt(x * x + y * y);
	}
};

long double circle_intersection_area(const Point &c1, long double r1, const Point &c2, long double r2)
{
	long double d = (c1 - c2).length();
	if(sgn(r1 + r2, d) <= 0)
		return 0;
	if(sgn(d, fabsl(r1 - r2)) <= 0)
		return min(r1, r2) * min(r1, r2) * Pi;
	/*
	long double x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
	//cout << x << '\n';
	//cout << d << '\n';
	//cout << r1 << ' ' << r2 << '\n';
	long double t1 = acosl(x / r1);
	long double t2 = acosl((d - x) / r2);
	//cout << x / r1 << '\n';
	//cout << (d - x) / r2 << '\n';
	//cout << t1 << ' ' << t2 << '\n';
	//cout << r1 << ' ' << r2 << '\n';
	//return r1 * r1 * t1 + r2 * r2 * t2 - d * r1 * sin(t1);
	//cout << t1 << ' ' << t2 << '\n';
	//cout << x / r1 << '\n';
	//cout << r1 * t1 << '\n';
	//cout << d * sin(t1) << '\n';
	//cout << r1 * t1 - d * sinl(t1) << '\n';
	return r1 * (r1 * t1 - d * sinl(t1)) + r2 * r2 * t2;
	*/
	long double ret = 0;
	for(int t = 0; t < 2; t ++)
	{
		long double p = (r1 * r1 + d * d - r2 * r2) / (2 * r1 * d);
		long double da = acos(p) * 2;
		ret += r1 * r1 * (da - sin(da)) / 2;
		swap(r1, r2);
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	long double x1, y1, r1;
	long double x2, y2, r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	cout << setprecision(15) << circle_intersection_area(Point(x1, y1), r1, Point(x2, y2), r2) << '\n';
}