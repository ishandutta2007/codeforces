#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

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

	double dot(const Point &p) const
	{
		return x * p.x + y * p.y;
	}
	double cross(const Point &p) const
	{
		return x * p.y - y * p.x;
	}


	double length2() const
	{
		return x * x + y * y;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	Point s, t;
	cin >> s.x >> s.y;
	cin >> t.x >> t.y;
	double v_max, tc;
	cin >> v_max >> tc;
	Point v, w;
	cin >> v.x >> v.y;
	cin >> w.x >> w.y;
	double left = 0;
	double right = 123456789.0;
	for(int tt = 0; tt < 200; tt ++)
	{
		double mid = (left + right) / 2;
		Point travel = t - s;
		if(mid < tc)
			travel = travel - v * mid;
		else
			travel = travel - v * tc - w * (mid - tc);

		if((travel / mid).length() < v_max)
			right = mid;
		else
			left = mid;
		//cout << mid << '\n';
		//cout << (travel / mid).length() << '\n';
	}

	cout << setprecision(12) << left << '\n';
	return 0;
}