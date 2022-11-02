#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);

	intl s, x;
	cin >> s >> x;
	intl old_s = s, old_x = x;
	intl ans = 1;
	for(int i = 60; i >= 0; i --)
		if((x >> i) & 1)
		{
			ans *= 2;
			s -= (1LL << i);
		}
	if(s < 0 || (s & 1))
		ans = 0;
	s /= 2;
	for(int i = 60; i >= 0; i --)
		if(((x >> i) & 1) == 0)
			if(s >= (1LL << i))
				s -= (1LL << i);
	if(s != 0)
		ans = 0;
	if(ans != 0 && old_x == old_s)
		ans -= 2;
	cout << ans << '\n';

	return 0;
}