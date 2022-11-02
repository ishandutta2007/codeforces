#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2011;
const double Eps = 1e-12;
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
	double dot(const Point &rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}
	double arg() const
	{
		double ret = atan2(y, x);
		if(sgn(ret) < 0)
			ret += 2 * Pi;
		return ret;
	}
	double length2() const
	{
		return x * x + y * y;
	}

	Point foot_to_line(const Point &p1, const Point &p2)
	{
		double shift = (p2 - p1).dot(*this - p1);
		shift /= (p2 - p1).length2();
		return p1 + (p2 - p1) * shift;
	}
}p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c == 0)
		{
			cnt ++;
			if(cnt == 1)
				p[i] = Point(0, 0);
			else
			{
				n --;
				i --;
			}
		}
		else if(a != 0 && b != 0)
			p[i] = Point(0, 0).foot_to_line(Point((double)c / a, 0), Point(0, (double)c / b));
		else if(a == 0)
			p[i] = Point(0, (double)c / b);
		else
			p[i] = Point((double)c / a, 0);
	}
	long long ans = 0;
	for(int i = 0; i < n; i ++)
	{
		vector <double> vec;
		for(int j = 0; j < n; j ++)
			if(i != j)
			{
				double d = (p[i] - p[j]).arg();
				if(sgn(d, Pi) == -1)
					vec.push_back(d);
				else
					vec.push_back(d - Pi);
			}
		sort(vec.begin(), vec.end());
		int acc = 0;
		vec.push_back(-1);
		for(int j = 0; j < vec.size(); j ++)
			if(j != 0 && sgn(vec[j - 1], vec[j]) != 0)
			{
				ans += acc * (acc - 1) / 2;
				acc = 1;
			}
			else
				acc ++;
	}
	ans /= 3;
	if(cnt == 2)
		ans += n - 1;
	cout << ans << '\n';
	return 0;
}