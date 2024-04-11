#include <iostream>
#include <cmath>
using namespace std;

const double Eps = 1e-8;
int sgn(double a, double b = 0.0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

int main()
{
	ios :: sync_with_stdio(false);
	double r, h;
	cin >> r >> h;

	int ans1;
	if(sgn(r + h, (sqrt(3) / 2 + 1) * r) >= 0)
		ans1 = 3 + (int)floor((r + h - ((sqrt(3) / 2 + 1) * r)) / r + Eps) * 2;
	else
		ans1 = 1;

	int ans2;
	if(sgn(h, r / 2) >= 0)
		ans2 = 2 + (int)floor((h - r / 2) / r + Eps) * 2;
	else
		ans2 = 0;

	cout << max(ans1, ans2) << '\n';
	return 0;
}