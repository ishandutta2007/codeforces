#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, x, y;
	cin >> a >> x >> y;
	if (abs (x) >= a || (y % a) == 0)
	{
		cout << "-1\n";
		return 0;
	}
	if (y < a)
	{
		if (abs (x) <= (a - 1) / 2)
			cout << "1\n";
		else
			cout << "-1\n";
		return 0;
	}
	int nsquare = 1;
	for (int i = 0; i < 100000000; i++)
	{
		int lo = (i + 1) * a, hi = (i + 2) * a;
		if (lo < y && y < hi)
		{
			if (i % 2 == 0)
			{
				if (abs (x) <= (a - 1) / 2)
					cout << nsquare + 1 << "\n";
				else
					cout << "-1\n";
			}
			else
			{
				if (abs (x) < a && x != 0)
					cout << nsquare + (x < 0 ? 1 : 2) << "\n";
				else
					cout << "-1\n";
			}
			return 0;
		}
		nsquare += ((i % 2 == 0) ? 1 : 2);
	}
	cout << "-1\n";
	return 0;
}