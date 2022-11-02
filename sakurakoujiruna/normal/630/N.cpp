#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define double long double

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double delta;
	if(b * b - 4 * a * c > 0)
		delta = sqrtl(b * b - 4 * a * c);
	else
		delta = 0;
	if(a < 0)
		delta = -delta;
	double ans1 = (-b + delta) / 2 / a;
	double ans0 = (-b - delta) / 2 / a;
	cout << setprecision(12) << ans1 << '\n' << ans0 << '\n';
	return 0;
}