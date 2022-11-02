#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int Inf = 0x3f3f3f3f;

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
	double dot(Point p) {
		return x * p.x + y * p.y;
	}
	double length() {
		return sqrt(x * x + y * y);
	}
}p[4], q[4];

double xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
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

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	while(n --)
	{
		for(int i = 0; i < 4; i ++)
			cin >> p[i].x >> p[i].y >> q[i].x >> q[i].y;
		int ans = Inf;
		for(int k = 0; k < (1 << 8); k ++)
		{
			int acc = 0;
			vector <Point> v;
			for(int i = 0; i < 4; i ++)
			{
				acc += ((k >> (i * 2)) & 3);
				v.push_back(q[i] + (p[i] - q[i]).rotate(Pi / 2 * ((k >> (i * 2)) & 3)));
			}
			v = Convex_hull :: convex_hull(v);
			if(v.size() == 4 &&
				sgn((v[0] - v[1]).length(), (v[1] - v[2]).length()) == 0 &&
				sgn((v[1] - v[0]).dot(v[2] - v[1])) == 0 &&
				sgn((v[2] - v[1]).dot(v[3] - v[2])) == 0 &&
				sgn((v[3] - v[2]).dot(v[0] - v[3])) == 0 &&
				sgn((v[0] - v[3]).dot(v[1] - v[0])) == 0)
				ans = min(ans, acc);
		}
		cout << (ans == Inf ? -1 : ans) << '\n';
	}
	return 0;
}