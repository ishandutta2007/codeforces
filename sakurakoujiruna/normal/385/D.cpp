#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define double long double
const double Eps = 1e-8;
const double Pi = 4 * atan(1);
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

struct Point
{
	double x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double length() {
		return sqrt(x * x + y * y);
	}
	double arg() {
		double ret = atan2(y, x);
		if(sgn(ret) < 0)
			ret += 2 * Pi;
		return ret;
	}
};

const int N = 20;
double x[N], y[N], a[N];
double dp[1 << N];

double solve(int n, double p)
{
	double b = (Point{x[n], y[n]} - Point{p, 0}).arg();
	if(sgn(a[n] + b, Pi) >= 0)
		return 1e5;
	double c = Pi - a[n] - b;
	double lc = (Point{x[n], y[n]} - Point{p, 0}).length();
	double la = lc / sin(c) * sin(a[n]);
	return min(la + p, (double)1e5);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	double l, r;
	cin >> n >> l >> r;
	for(int i = 0; i < n; i ++)
	{
		cin >> x[i] >> y[i] >> a[i];
		a[i] = a[i] / 180 * Pi;
	}
	for(int k = 0; k < (1 << n); k ++)
	{
		dp[k] = l;
		for(int i = 0; i < n; i ++)
			if((k >> i) & 1)
				dp[k] = max(dp[k], solve(i, dp[k ^ (1 << i)]));
	}
	dp[(1 << n) - 1] = min(dp[(1 << n) - 1], r);
	cout << setprecision(8) << dp[(1 << n) - 1] - l << '\n';
	return 0;
}