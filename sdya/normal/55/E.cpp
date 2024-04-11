#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long x[210000], y[210000];
int n;

long long ab(long long x)
{
	return (x > 0 ? x : - x);
}

bool in(long long p, long long q)
{
	x[n + 1] = x[1], y[n + 1] = y[1];
	long long s = 0;
	for (int i = 1; i <= n; i ++)
		s += x[i] * y[i + 1] - x[i + 1] * y[i];
	if (s < 0) s = - s;

	long long r = 0;
	for (int i = 1; i <= n; i ++)
		r += ab((x[i] - p) * (y[i + 1] - q) - (x[i + 1] - p) * (y[i] - q));
	if (r < 0) r = - r;
	return (s == r);
}

long long solve(long long p, long long q)
{
	if (!in(p, q)) return 0;
	for (int i = n + 1; i <= n + n; i ++)
		x[i] = x[i - n], y[i] = y[i - n];

	long long res = 0;
	for (int i = 1; i <= n; i ++)
	{
		long long A = y[i] - q, B = p - x[i], C = x[i] * q - y[i] * p;
		long long side;
		if (A * x[i + 1] + B * y[i + 1] + C > 0) side = + 1; else side = - 1;
		int l = i + 1, r = i + n - 1;
		while (r - l > 1)
		{
			int key = (l + r) / 2;
			long long D = A * x[key] + B * y[key] + C;
			if ((D > 0 && side == +1) || (D < 0 && side == -1))	l = key; else r = key;
		}
		int u = l;
		long long D = A * x[r] + B * y[r] + C;
		if ((D > 0 && side == +1) || (D < 0 && side == -1)) u = r;
		res += ((long long)(u - i) * (long long)(u - i - 1LL)) / 2LL;
		//res += ((i + n - 1 - (u + 1) + 1) * (i + n - 1 - (u + 1))) / 2LL;
	} 

	long long x = (long long)(n) * (long long)(n - 1LL) * (long long)(n - 2LL);

	return (x / 6LL) - res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%I64d%I64d", &x[i], &y[i]);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++)
	{
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		cout << solve(a, b) << endl;
	}
	return 0;
}