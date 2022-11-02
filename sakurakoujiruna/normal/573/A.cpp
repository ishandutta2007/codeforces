#include <iostream>
using namespace std;

typedef long long intl;

intl gcd(intl a, intl b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

bool check(intl n)
{
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	return n == 1;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	intl last;
	bool flag = true;
	for(int i = 1; i <= n; i ++)
	{
		intl x;
		cin >> x;
		if(i != 1)
		{
			intl lcm = x / gcd(x, last) * last;
			if(!check(lcm / x) || !check(lcm / last))
				flag = false;
		}
		last = x;
	}
	if(flag)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}