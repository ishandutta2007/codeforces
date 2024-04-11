#include <iostream>
#include <cstdio>
using namespace std;

typedef long long intl;

int d[5];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < 5; i ++)
	{
		d[i] = n % 10;
		n /= 10;
	}
	intl nn = d[3] + d[1] * 10 + d[0] * 100 + d[2] * 1000 + d[4] * 10000;
	//cout << nn << '\n';
	intl ans = 1;
	for(int i = 0; i < 5; i ++)
	{
		ans *= nn;
		ans %= 100000;
	}
	printf("%05lld\n", ans);
	return 0;
}