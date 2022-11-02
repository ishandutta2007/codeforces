#include <iostream>
using namespace std;

typedef unsigned long long intl;

intl solve(intl y1, intl y2)
{
	intl all = y2 - y1 + 1;
	//cout << y2 << ' ' << y1 << '\n';
	if((all & 1) && y1 % 2 == 0)
		return all / 2 + 1;
	return all / 2;
}

int main()
{
	intl x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	intl dx = x2 - x1;
	intl dy = y2 - y1;
	x1 = y1 = 0;
	x2 = dx;
	y2 = dy;
	intl all = x2 - x1 + 1;
	intl odd = all / 2;
	intl even = all / 2;
	if(all & 1)
	{
		if(x1 % 2 == 0)
			even ++;
		else
			odd ++;
	}
	//cout << odd << ' ' << even << '\n';
	//cout << solve(y1, y2) << '\n';
	//cout << solve(y1 + 1, y2 + 1) << '\n';
	cout << even * solve(y1, y2) + odd * solve(y1 + 1, y2 + 1) << '\n';
	return 0;
}