#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

int n, k;
long long l[2000], r[2000];
double d[2000];

double p[1100][1100];

long long calc(long long n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long res = 1LL;
	long long p = 1LL;
	while (true)
	{
		if (p == 1000000000000000000LL) return res;
		p *= 10LL;
		if (n < p) return res;
		if (n < p + p) return res + n - p + 1LL;
		res += p;
	}
}

long long calc(long long l, long long r)
{
	return calc(r) - calc(l - 1);
}

long long check(long long n)
{
	int res = 0;
	for (int i = 1; i <= n; i ++)
	{
		int m = 0;
		int x = i;
		while (x)
			m = m * 10 + (x % 10), x /= 10;
		if (m % 10 == 1) res ++;
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> l[i] >> r[i];
	cin >> k;
	for (int i = 1; i <= n; i ++)
		d[i] = (double)(calc(l[i], r[i])) / (double)(r[i] - l[i] + 1LL);

	p[0][0] = 1.0;
	for (int i = 1; i <= n; i ++)
	{
		p[i][0] = p[i - 1][0] * (1.0 - d[i]);
		for (int j = 1; j <= i; j ++)
			p[i][j] = p[i - 1][j] * (1.0 - d[i]) + p[i - 1][j - 1] * d[i];
	}

	double res = 0.0;
	for (int i = 0; i <= n; i ++)
		if (100 * i >= n * k) res += p[n][i];
	printf("%.10lf\n", res);
	return 0;
}