#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

#define double long double
const int N = 100011;
const double Pi = 4 * atan(1);
const double Eps = 1e-16;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}
double a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = atan2(y, x);
		if(sgn(a[i]) == -1)
			a[i] += 2 * Pi;
	}
	sort(a, a + n);
	double ans = 2 * Pi;
	for(int i = 0; i < n - 1; i ++)
		ans = min(ans, 2 * Pi - (a[i + 1] - a[i]));
	ans = min(ans, 2 * Pi - (a[0] + 2 * Pi - a[n - 1]));
	cout << setprecision(8) << ans / 2 / Pi * 360 << '\n';
	return 0;
}