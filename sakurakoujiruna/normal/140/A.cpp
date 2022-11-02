#include <iostream>
#include <cmath>
using namespace std;

const double Eps = 1e-8;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
const double Pi = 4 * atan(1);

int main()
{
	ios :: sync_with_stdio(false);
	int n, R, r;
	cin >> n >> R >> r;
	double lim;
	if(n == 1)
		lim = R;
	else
	{
		double s = Pi / n;
		lim = R * sin(s) / (1 + sin(s));
	}
	cout << (sgn(lim, r) >= 0 ? "YES" : "NO") << '\n';
	return 0;
}