#include <iostream>
#include <cmath>
using namespace std;

typedef long double doublel;
#define double doublel

const double Eps = 1e-8;
const double Pi = 4 * atan(1);

int sgn(double a, double b = 0.0)
{
	a -= b;
	if(a > Eps)
		return 1;
	if(a < -Eps)
		return -1;
	return 0;
}

struct Point
{
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	Point operator -(const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
	Point operator +(const Point &p) const
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator *(const double &d) const
	{
		return Point(x * d, y * d);
	}

	double cross(const Point &p) const
	{
		return x * p.y - y * p.x;
	}

	Point rotate(const double &arg) const
	{
		double tx = x * cos(arg) - y * sin(arg);
		double ty = y * cos(arg) + x * sin(arg);
		return Point(tx, ty);
	}

}p[8];

int main()
{
	ios :: sync_with_stdio(false);

	p[0] = Point(0, 0);
	double acc = 0;
	for(int i = 0; i < 6; i ++)
	{
		acc += Pi / 3;
		int x;
		cin >> x;
		p[i + 1] = p[i] + Point(x, 0).rotate(acc);
	}

	double ans = 0;
	for(int i = 0; i < 6; i ++)
		ans += p[i].cross(p[i + 1]) / 2;

	ans = ans * 4 / sqrt(3);

	cout << (int)(fabs(ans) + 0.5) << '\n';

	return 0;
}