#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const double EPS = 1e-9;

int main()
{
	double vp, vd, t, f, c;
	cin >> vp >> vd >> t >> f >> c;
	
	if (vp >= vd - EPS)
	{
		cout << "0\n";
		return 0;
	}
	
	double x = t * vd * vp / (vd - vp);
	int cnt = 0;
	
	while (x < c - EPS)
	{
		double y = (2 * x + f * vd) * vp / (vd - vp);
		x += y;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}