#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>

using namespace std;
typedef long long ll;
typedef long double ld;
const double PI = acos (-1.0);

int main()
{
	cout << fixed << setprecision (7);	
	
	double w, h, a;
	cin >> w >> h >> a;
	if (a > 90) a = 180 - a;
	if (a < 0.5)
	{
		cout << h * w << "\n";
		return 0;
	}
	a = (a * PI / 180);
	
	if (w < h) swap (w, h);
	
	if ((a + 0.0) > 2 * atan ((h + 0.0) / (w + 0.0)) - 1e-8)
	{
		cout << h * h / sin (a) << "\n";
	}
	else
	{
		double x = w / 2.0 - h / 2 * tan (a / 2);
		double ans = x * x * tan (a);
		x = h / 2.0 - w / 2 * tan (a / 2);
		ans += x * x * tan (a);
		/*double nang = a + atan (h / w);
		double d = sqrt (w * w + h * h) / 2.0;
		
		double nh = (d * sin(nang) - h / 2.0);
		double ans = nh * nh * tan (a) + nh * nh / tan (a);
		nang = a - atan (h / w);
		nh = (d * cos (nang) - w / 2.0);
		ans += nh * nh * tan (a) + nh * nh / tan (a);*/
		
		//cout << ans << "\n";
		cout << h * w - ans << "\n";
	}
	return 0;
}