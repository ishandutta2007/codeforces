#include <iostream>
#include <map>
#include <cmath>
using namespace std;

typedef long long intl;

#define double long double
const double Eps = 1e-15;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

const int N = 2011;
struct Point
{
	double x, y;
	Point operator -(Point p) {
		return Point{x - p.x, y - p.y};
	}
	double arg()
	{
		double ret = atan2(y, x);
		if(ret < 0)
			ret += 2 * Pi;
		return ret;
	}
}p[N];

class Cmp
{
public:
	bool operator ()(double a, double b) const {
		return sgn(a, b) == -1;
	}
};

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;

	intl ans = 0;
	for(int i = 0; i < n; i ++)
	{
		map <double, int, Cmp> mp;
		for(int j = 0; j < n; j ++)
			if(i != j)
			{
				double tmp = (p[j] - p[i]).arg();
				if(sgn(tmp, Pi) >= 0)
					tmp -= Pi;
				mp[tmp] ++;
			}
		for(auto p : mp)
			ans += p.second * (n - 1 - p.second);
	}
	cout << ans / 6 << '\n';
	return 0;
}