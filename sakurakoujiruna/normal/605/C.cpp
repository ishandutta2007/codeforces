#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

const double Eps = 1e-8;
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
	bool operator ==(const Point &p) const
	{
		return sgn(x, p.x) == 0 && sgn(y, p.y) == 0;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}
	double cross(const Point &p)
	{
		return x * p.y - y * p.x;
	}
};
double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}
Point line_intersection(const Point &p1, const Point &p2, const Point &q1, const Point &q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double ret_x = (q1.x * v + q2.x * u) / (v + u);
	double ret_y = (q1.y * v + q2.y * u) / (v + u);
	return Point(ret_x, ret_y);
}

namespace Convex_hull
{
	bool cmp(const Point &p1, const Point &p2)
	{
		if(sgn(p1.x, p2.x) == 0)
			return p1.y < p2.y;
		return p1.x < p2.x;
	}
	vector <Point> convex_hull(vector <Point> vec)
	{
		vector <Point> ret;
		sort(vec.begin(), vec.end(), cmp);
		int down_top = 0;
		for(int i = 0; i < vec.size(); i ++)
		{
			while(down_top > 1 && sgn(xmul(ret[down_top - 2], vec[i], ret[down_top - 1])) >= 0)
			{
				ret.pop_back();
				down_top --;
			}
			ret.push_back(vec[i]);
			down_top ++;
		}
		int up_top = down_top;
		for(int i = (int)vec.size() - 2; i >= 0; i --)
		{
			while(up_top > down_top && sgn(xmul(ret[up_top - 2], vec[i], ret[up_top - 1])) >= 0)
			{
				ret.pop_back();
				up_top --;
			}
			if(i != 0)
			{
				ret.push_back(vec[i]);
				up_top ++;
			}
		}
		return ret;
	}
}

bool on_segment(Point p, Point q1, Point q2)
{
	double q12 = (q1 - q2).length();
	double pq1 = (q1 - p).length();
	double pq2 = (q2 - p).length();
	return sgn(q12, pq1 + pq2) == 0;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, p, q;
	cin >> n >> p >> q;
	vector <Point> v;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(Point(x, 0));
		v.push_back(Point(0, y));
		v.push_back(Point(x, y));
	}
	v = Convex_hull :: convex_hull(v);
	n = v.size();
	v.push_back(v[0]);
	double ans = 0;
	for(int i = 0; i < n; i ++)
		if(!(v[i] == Point(0, 0)) && !(v[i + 1] == Point(0, 0)))
		{
			Point t = line_intersection(v[i], v[i + 1], Point(0, 0), Point(p, q));
			if(on_segment(t, v[i], v[i + 1]))
				ans = Point(p, q).length() / t.length();
		}
	cout << setprecision(15) << ans << '\n';
	return 0;
}