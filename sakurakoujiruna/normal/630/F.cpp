#include <iostream>
using namespace std;

typedef long long intl;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int c[15];

intl combine(int n, int m)
{
	intl ans = 1;
	for(int i = 1; i <= m; i ++)
		c[i] = n - i + 1;
	for(int j = 2; j <= m; j ++)
	{
		int tmp = j;
		for(int i = 1; i <= m; i ++)
		{
			int g = gcd(c[i], tmp);
			tmp /= g;
			c[i] /= g;
		}
	}
	for(int i = 1; i <= m; i ++)
		ans *= c[i];
	//cout << ans << '\n';
	return ans;
}

int main()
{
	int n;
	cin >> n;
	cout << combine(n, 5) + combine(n, 6) + combine(n, 7) << '\n';
	return 0;
}