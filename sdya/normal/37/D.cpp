#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <queue>

using namespace std;

long long MD = 1000000007LL;

long long powmod(long long a, long long n)
{
	if (n == 1LL) return a;
	long long b = powmod(a, n / 2LL);
	b *= b; b %= MD;
	if (n % 2LL == 0LL)
		return b;
	return (b * a) % MD;
}

long long inv(long long a, long long p)
{
	return powmod(a, p - 2);
}

long long p[1100];
long long invp[1100];

long long cnk(long long n, long long k)
{
	long long cur = p[n];
	long long bc = invp[k] * invp[n - k]; bc %= MD;
	return (cur * bc) % MD;
}

long long f[110][1100];

int m;
long long x[110], y[110];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &m);
	long long n = 0;
	for (int i = 1; i <= m; i ++)
	{
		cin >> x[i];
		n += x[i];
	}
	for (int i = 1; i <= m; i ++)
		cin >> y[i];

	p[0] = 1LL;
	for (int i = 1; i <= 1000; i ++)
		p[i] = p[i - 1] * (long long)(i), p[i] %= MD;
	for (int i = 0; i <= 1000; i ++)
		invp[i] = inv(p[i], MD);

	for (int i = 0; i <= n; i ++)
		f[m][i] = (bool)(i <= y[m]);
	for (int i = m - 1; i >= 1; i --)
		for (int k = n; k >= 0; k --)
			for (int j = max(0LL, k - y[i]); j <= k; j ++)
				if (x[i + 1] + j <= n)
					f[i][k] += cnk(k, j) * f[i + 1][(x[i + 1] + (long long)(j))], f[i][k] %= MD;

	long long res = f[1][x[1]];
	res *= p[n]; res %= MD;
	for (int i = 1; i <= m; i ++)
		res *= invp[x[i]], res %= MD;
	cout << res << endl;


	return 0;
}