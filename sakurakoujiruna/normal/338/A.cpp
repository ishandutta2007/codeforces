#include <iostream>
using namespace std;

typedef long long intl;
const intl Mod = (intl)1e9 + 9;

intl qpow(intl a, int b)
{
	intl tmp = a;
	intl ret = 1;
	while(b > 0)
	{
		if(b & 1)
		{
			ret *= tmp;
			ret %= Mod;
		}
		tmp *= tmp;
		tmp %= Mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);

	intl n, m, k;
	cin >> n >> m >> k;
	int left = 0, right = m / k + 1;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		intl l = (mid - 1) * k;
		intl r = m - l;
		intl ru = 0;
		if(r > 0)
			ru = r + (r + k - 2) / (k - 1) - 1;
		if(ru <= n - l)
			right = mid;
		else
			left = mid;
	}
	//cout << left << '\n';
	left = left * k;
	intl c = left / k;
	intl ans = (qpow(2, c + 1) - 2) * k % Mod;
	ans += (m - left);
	cout << (ans % Mod + Mod) % Mod << '\n';

	return 0;
}