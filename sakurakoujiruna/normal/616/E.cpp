#include <iostream>
using namespace std;

typedef long long intl;
const intl Mod = (intl)1e9 + 7;
const intl Inv2 = (Mod + 1) / 2;

int main()
{
	ios :: sync_with_stdio(false);
	intl n, m;
	cin >> n >> m;
	intl ans = 0;
	if(m > n)
	{
		ans = (m - n) % Mod * (n % Mod) % Mod;
		m = n;
	}

	for(intl i = 1; i <= m; i = n / (n / i) + 1)
	{
		intl r = min(m, n / (n / i));
		//cout << i << ' ' << r << '\n';
		ans += (r - i + 1) % Mod * (n % Mod) % Mod;
		ans -= (n / i) % Mod * ((i + r) % Mod) % Mod
			* ((r - i + 1) % Mod) % Mod * Inv2 % Mod;
		ans %= Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}