#include <iostream>
#include <iomanip>
using namespace std;

const double Eps = 1e-8;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

double solve(double x, double a, double v, double t)
{
	if(sgn(v) == 0)
		return x;
	else if(sgn(v) > 0)
	{
		double b = (a - x) / v;
		if(sgn(t, b) <= 0)
			return x + t * v;
		return solve(a, a, -v, t - b);
	}
	else
	{
		double b = -x / v;
		if(sgn(t, b) <= 0)
			return x + t * v;
		return solve(0, a, -v, t - b);
	}
}

int main()
{
	double a, b, m;
	cin >> a >> b >> m;
	double x, y, z;
	cin >> x >> y >> z;

	double x0 = solve(a / 2, a, x, -m / y);
	double z0 = solve(0, b, z, -m / y);
	cout << setprecision(8) << x0 << ' ' << z0 << '\n';
	return 0;
}