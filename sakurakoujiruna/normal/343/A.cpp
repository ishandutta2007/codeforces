#include <iostream>
using namespace std;

typedef long long intl;

intl gcd(intl a, intl b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	intl a, b;
	cin >> a >> b;
	intl ans = 0;
	while(a != b)
	{
		//cout << a << ' ' << b << '\n';
		intl g = gcd(a, b);
		a /= g;
		b /= g;
		if(a > b)
		{
			//cout << a << ' ' << b << '\n';
			if(a % b != 0)
			{
				ans += a / b;
				a -= (a / b) * b;
			}
			else
			{
				ans += a / b - 1;
				a -= (a / b - 1) * b;
			}
		}
		else
			swap(a, b);
	}
	cout << ans + 1 << '\n';
	return 0;
}