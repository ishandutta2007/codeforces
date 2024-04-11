#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

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
	Point operator /(const double &d) const
	{
		return Point(x / d, y / d);
	}

	bool operator ==(const Point &p) const
	{
		return sgn(x, p.x) == 0 && sgn(y, p.y) == 0;
	}

	double dot(const Point &p) const
	{
		return x * p.x + y * p.y;
	}
	double cross(const Point &p) const
	{
		return x * p.y - y * p.x;
	}

	double arg() const
	{
		double ret = atan2(y, x);
		if(sgn(ret) < 0)
			ret += 2 * Pi;
		return ret;
	}
	Point rotate(const double &arg) const
	{
		double tx = x * cos(arg) - y * sin(arg);
		double ty = y * cos(arg) + x * sin(arg);
		return Point(tx, ty);
	}

	double length2() const
	{
		return x * x + y * y;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}

	double distance_to_line(const Point &p1, const Point &p2)
	{
		return fabs((p1 - *this).cross(p2 - *this)) / (p1 - p2).length();
	}
	double distance_to_segment(const Point &p1, const Point &p2)
	{
		if(sgn((p2 - p1).dot(*this - p1)) == -1)
			return (*this - p1).length();
		if(sgn((p1 - p2).dot(*this - p2)) == -1)
			return (*this - p2).length();
		return (*this).distance_to_line(p1, p2);
	}

	Point foot_to_line(const Point &p1, const Point &p2)
	{
		double shift = (p2 - p1).dot(*this - p1);
		shift /= (p2 - p1).length2();
		return p1 + (p2 - p1) * shift;
	}

	bool on_segment(const Point &p1, const Point &p2)
	{
		if(!(sgn(min(p1.x, p2.x), x) <= 0 && sgn(x, max(p1.x, p2.x)) <= 0) &&
			(sgn(min(p1.y, p2.y), y) <= 0 && sgn(y, max(p1.y, p2.y)) <= 0))
			return false;
		if(sgn((*this - p1).cross(p2 - p1)) == 0)
			return true;
		return false;
	}
};

const int N = 101111;
Point p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	Point s;
	cin >> s.x >> s.y;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	p[n] = p[0];
	double min_d = 1e9;
	double max_d = 0;
	for(int i = 0; i < n; i ++)
	{
		double t = s.distance_to_segment(p[i], p[i + 1]);
		min_d = min(min_d, t);
		max_d = max(max_d, t);
		max_d = max(max_d, (p[i] - s).length());
	}
	cout << setprecision(12) << max_d * max_d * Pi - min_d * min_d * Pi << '\n';
	return 0;
}