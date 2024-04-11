#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	intl n;
	cin >> n;
	if(n == 0)
	{
		cout << 0 << ' ' << 0 << '\n';
		return 0;
	}
	intl left = 0, right = 6 * 1e8;
	while(left + 1 < right)
	{
		intl mid = (left+ right) >> 1;
		intl tmp = 3 * (mid - 1) * mid;
		if(n <= tmp)
			right = mid;
		else
			left = mid;
	}
	intl k = left;
	intl x = 2 * k - 1;
	intl y = 2;
	n -= 3 * (k - 1) * k + 1;

	//cout << n << ' ' << x << ' ' << y << '\n';

	intl t = min(n, k - 1);
	x -= t;
	y += 2 * t;
	n -= t;

	t = min(n, k);
	x -= 2 * t;
	n -= t;

	t = min(n, k);
	x -= t;
	y -= 2 * t;
	n -= t;

	t = min(n, k);
	x += t;
	y -= 2 * t;
	n -= t;

	t = min(n, k);
	x += 2 * t;
	n -= t;

	t = min(n, k);
	x += t;
	y += 2 * t;
	n -= t;

	cout << x << ' ' << y << '\n';
	return 0;
}