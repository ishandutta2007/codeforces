#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define double long double
const double Eps = 1e-15;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

const int N = 1011;
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
double a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	Point o;
	cin >> o.x >> o.y;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		double tmp = (p[i] - o).arg();
		if(sgn(tmp, Pi) >= 0)
			tmp -= Pi;
		a[i] = tmp;
	}
	sort(a, a + n);
	int ans = 1;
	for(int i = 1; i < n; i ++)
		if(sgn(a[i], a[i - 1]) != 0)
			ans ++;
	cout << ans << '\n';
	return 0;
}