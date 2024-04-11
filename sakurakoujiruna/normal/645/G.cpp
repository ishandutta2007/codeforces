#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 100011;
const double Eps = 1e-18;
const double Pi = 4 * atan(1);

int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
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
}p[N];

/*
vector <Point> circle_intersection(const Point &c1, const double &r1, const Point &c2, const double &r2)
{
	vector <Point> ret;
	double x = (c1 - c2).length2();
	double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
	double d = r1 * r1 / x - y * y;
	if(sgn(d) == -1)
		return ret;
	d = max(d, 0.0);
	Point p1 = c1 + (c2 - c1) * y;
	Point p2 = ((c2 - c1) * sqrt(d)).rotate(Pi / 2);
	ret.push_back(p1 - p2);
	ret.push_back(p1 + p2);
	return ret;
}
*/


vector <double> cir_cir(const Point &O0, const double &r0, const Point &O1, const double &r1)
{
	Point u = O1 - O0;
	double ang = u.arg();
	double tmp0 = u.dot(u);
	double tmp1 = (tmp0 + r0 * r0 - r1 * r1) / (2 * sqrt(tmp0) * r0);
	if (tmp1 >= 1 || tmp1 <= -1) return vector<double>();
	tmp1 = acos(tmp1);
	assert(sgn(tmp1) >= 0);
	vector <double> ret;
	ret.push_back(ang - tmp1);
	ret.push_back(ang + tmp1);
	return ret;
}

double norm(double a)
{
	while(sgn(a, 0) < 0)
		a += 2 * Pi;
	while(sgn(a, 2 * Pi) >= 0)
		a -= 2 * Pi;
	return a;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, a;
	cin >> n >> a;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;

	double left = 0, right = 2 * a;
	for(int _ = 0; _ < 60; _ ++)
	{
		double mid = (left + right) / 2;
		vector <pair <double, double> > all;
		for(int i = 0; i < n; i ++)
		{
			//Point o = (Point(-a, 0) + p[i]) / 2;
			//double r = (Point(-a, 0) - p[i]).length() / 2;
			//vector <Point> inter = circle_intersection(o, r, Point(0, 0), mid / 2);
			//vector <double> arg = cir_cir(Point(0, 0), mid / 2, o, r);
			vector <double> arg = cir_cir(Point(a, 0), mid, p[i], (p[i] - Point(-a, 0)).length());
			/*
			for(auto &p : inter)
				arg.push_back(p.arg());
			*/
			for(auto &a : arg)
				a = norm(a);
			if(arg.size() > 0)
			{
				if(arg[0] > arg[1])
					swap(arg[0], arg[1]);
				all.push_back({arg[0], arg[1]});
			}
		}
		sort(all.begin(), all.end());
		bool flag = false;
		set <double> st;
		for(auto &p : all)
		{
			auto it = st.lower_bound(p.first);
			if(it != st.end() && *it < p.second)
				flag = true;
			st.insert(p.second);
		}
		if(flag)
			right = mid;
		else
			left = mid;
	}
	cout << setprecision(12) << left << '\n';
	return 0;
}