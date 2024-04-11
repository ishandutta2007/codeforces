#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;
#define double ld

const double Eps = 1e-8;
int sgn(double a, double b = 0)
{
	a -= b;
	if(a > Eps)
		return 1;
	if(a < -Eps)
		return -1;
	return 0;
}

const int N = 1011;
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

	double cross(const Point &p) const
	{
		return x * p.y - y * p.x;
	}
	double length() const
	{
		return sqrt(x * x + y * y);
	}
}p[N];

double xmul(const Point &a, const Point &b, const Point &c)
{
	return (b - a).cross(c - a);
}
bool check_seg_inter(const Point &p1, const Point &p2, const Point &q1, const Point &q2)
{
	if(sgn(max(q1.x, q2.x), min(p1.x, p2.x)) == -1 || sgn(max(q1.y, q2.y), min(p1.y, p2.y)) == -1)
		return false;
	if(sgn(max(p1.x, p2.x), min(q1.x, q2.x)) == -1 || sgn(max(p1.y, p2.y), min(q1.y, q2.y)) == -1)
		return false;
	if(sgn((p2 - p1).cross(q1 - p1)) * sgn((p2 - p1).cross(q2 - p1)) > 0)
		return false;
	if(sgn((q2 - q1).cross(p1 - q1)) * sgn((q2 - q1).cross(p2 - q1)) > 0)
		return false;
	return true;
}
Point line_inter(const Point &p1, const Point &p2, const Point &q1, const Point &q2)
{
	double u = xmul(p1, p2, q1);
	double v = xmul(p2, p1, q2);
	double ret_x = (q1.x * v + q2.x * u) / (v + u);
	double ret_y = (q1.y * v + q2.y * u) / (v + u);
	return Point(ret_x, ret_y);
}

class PointCmp
{
public:
	bool operator ()(const Point &lhs, const Point &rhs) const
	{
		if(sgn(lhs.x, rhs.x) == 0)
			return sgn(lhs.y, rhs.y) == -1;
		return sgn(lhs.x, rhs.x) == -1;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	p[n] = p[0];

	while(m --)
	{
		map <Point, int, PointCmp> mp;
		Point a, b;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		for(int i = 0; i < n; i ++)
			if(check_seg_inter(p[i], p[i + 1], a - (b - a) * 1e8, a + (b - a) * 1e8))
			{
				if(sgn((b - a).cross(p[i + 1] - p[i])) == 0)
				{
					mp[p[i]] += 20;
					mp[p[i + 1]] += 20;
				}
				else
				{
					Point inter = line_inter(p[i], p[i + 1], a, b);
					if(inter == p[i] || inter == p[i + 1])
					{
						Point dir;
						if(inter == p[i])
							dir = p[i + 1] - p[i];
						else
							dir = p[i] - p[i + 1];
						int tmp = sgn((b - a).cross(dir));
						mp[inter] += tmp;
					}
					else
						mp[inter] = 0;
				}
			}

		double ans = 0;
		Point last_p;
		bool count = false;
		bool on_line = false;
		int last_c = 0;
		for(auto it = mp.begin(); it != mp.end(); it ++)
		{
			//cout << (it -> first).x << ' ' << (it -> first).y << ' ' << (it -> second) << '\n';
			if(it -> second > 2)
				if(it -> second == 40)
					ans += ((it -> first) - last_p).length();
				else
				{
					it -> second -= 20;
					last_c += it -> second;
					if(on_line)
					{
						on_line = false;
						ans += ((it -> first) - last_p).length();
						if(last_c == 0)
							count = !count;
						last_c = 0;
					}
					else
					{
						on_line = true;
						if(count)
							ans += ((it -> first) - last_p).length();
					}
				}
			else
			{
				if(count)
					ans += ((it -> first) - last_p).length();
				if(it -> second == 0)
					count = !count;
			}
			last_p = it -> first;
		}
		cout << setprecision(8) << ans << '\n';
	}
	return 0;
}