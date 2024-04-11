#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x1, y1, r1;
	int x2, y2, r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;

	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if(d > r1 + r2)
		cout << setprecision(8) << (d - r1 - r2) / 2 << '\n';
	else if(d < abs(r1 - r2))
		cout << setprecision(8) << (abs(r1 - r2) - d) / 2 << '\n';
	else
		cout << 0 << '\n';
	return 0;
}