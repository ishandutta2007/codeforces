#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	intl a, x, y;
	cin >> a >> x >> y;
	a *= 2;
	x *= 2;
	y *= 2;

	int ans = -1;
	if(-a / 2 < x && x < a / 2
		&& 0 < y && y < a)
		ans = 1;
	for(int i = 2; i < 2e6; i ++)
	{
		int sid = (i + 1) / 3;
		intl lx, ly;
		if(i % 3 == 2)
		{
			lx = -a / 2;
			ly = a + (sid - 1) * 2 * a;
		}
		else if(i % 3 == 0)
		{
			lx = -a;
			ly = a + a + (sid - 1) * 2 * a;
		}
		else
		{
			lx = 0;
			ly = a + a + (sid - 1) * 2 * a;
		}
		if(lx < x && x < lx + a &&
			ly < y && y < ly + a)
			ans = i;
	}
	cout << ans << '\n';
	return 0;
}