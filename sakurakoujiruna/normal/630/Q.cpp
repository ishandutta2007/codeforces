#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double Pi = 4 * atan(1);

int main()
{
	double ans = 0;
	for(int n = 3; n <= 5; n ++)
	{
		double l;
		cin >> l;
		double r = l / 2 / sin(Pi / n);
		double th = sqrt(r * r - l * l / 4);
		//cout << th << '\n';
		double s = n * th * l / 2;
		//cout << s << '\n';
		double h = sqrt(l * l - r * r);
		ans += h * s / 3;
	}
	cout << setprecision(12) << ans << '\n';
	return 0;
}