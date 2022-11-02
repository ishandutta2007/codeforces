#include <iostream>
using namespace std;

typedef long long intl;
const intl Mod = (intl)1e9 + 7;

intl qpow(intl a, intl b)
{
	intl ret = 1;
	intl tmp = a;
	for(; b > 0; b >>= 1)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
	}
	return ret;
}
intl inv(intl a)
{
	return qpow(a, Mod - 2);
}

int main()
{
	ios :: sync_with_stdio(false);
	intl n, m;
	cin >> n >> m;

	intl tmp = qpow(m, n) * n % Mod;
	intl ans = qpow(m, n) + tmp;
	for(int i = 1; i < n; i ++)
	{
		tmp *= m - 1;
		tmp %= Mod;
		tmp *= inv(m);
		tmp %= Mod;

		tmp *= inv(i + 1);
		tmp %= Mod;
		tmp *= n - i;
		tmp %= Mod;

		ans += tmp;
	}
	cout << ans % Mod << '\n';
	return 0;
}