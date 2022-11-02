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

long long dp[1 << 9][20][2520];
long long d[1 << 9][20];
long long p2[20], p10[20];
long long g[1 << 9];

long long gcd(long long a, long long b)
{
	if (a == 0LL || b == 0LL) return a + b;
	if (a >= b) return gcd(a % b, b);
	return gcd(b % a, a);
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a, b)) * b;
}

long long s[2520];

void precalc()
{
	dp[0][0][0] = 1;
	for (int i = 1; i < 20; i ++)
		dp[0][i][0] = 1;
	for (int i = 1; i < (1 << 9); i ++)
	{
		g[i] = 1;
		for (int j = 0; j < 9; j ++)
			if (i & (1 << j))
				g[i] = lcm(g[i], j + 1);
		bool used[10];
		used[0] = true;
		for (int j = 0; j < 9; j ++)
			if (i & (1 << j)) used[j + 1] = true; else used[j + 1] = false;
		for (int digits = 1; digits < 20; digits ++)
		{
			for (int j = 0; j < 2520; j ++)	s[j] = 0;
			for (int j = 0; j < 2520; j ++)	s[(j * 10) % 2520] += dp[i][digits - 1][j];
			for (int j = 0; j < 2520; j ++)
				if (s[j] != 0)
					for (int k = 0, p = j; k < 10; k ++, p ++)
						if (used[k])
							dp[i][digits][p % 2520] += s[j];

			for (int k = 1; k < 10; k ++)
				if (used[k])
				{
					int nmask = i - (1 << (k - 1));
					for (int j = 0; j < 2520; j ++)
						dp[i][digits][((j * 10) + k) % 2520] += dp[nmask][digits - 1][j];
				}
		}
	}

	p10[0] = 1LL;
	for (int i = 1; i < 20; i ++)
		p10[i] = p10[i - 1] * 10LL;
}

long long calc(long long n)
{
	if (n == 0LL) return 0LL;
	int a[30], k = 0;
	long long m = n;
	while (m)
		k ++, a[k] = m % 10LL, m /= 10LL;
	long long res = 0;
	if (k > 1)
	{
		for (int i = 1; i < (1 << 9); i ++)
			for (int j = 0; j < 2520; j += g[i])
				res += dp[i][k - 1][j];
	}
	reverse(a + 1, a + k + 1);
	int mask = 0;
	long long number = 0;
	for (int t = 1; t <= k; t ++)
	{
		for (int i = (t == 1 ? 1 : 0); i < a[t]; i ++)
			for (int j = 0; j < (1 << 9); j ++)
			{
				long long x = number + (long long)(i) * p10[k - t];
				int y = (mask | j);
				if (i != 0) y |= (1 << (i - 1));
				x %= g[y];
				int f = g[y] - x;
				if (f == g[y]) f = 0;
				for (int l = f; l < 2520; l += g[y]) res += dp[j][k - t][l];
			}

		if (a[t] != 0) number += (long long)(a[t]) * p10[k - t];
		if (a[t] != 0) mask |= (1 << (a[t] - 1));
	}
	for (int i = 1; i <= k; i ++)
		if (a[i] != 0 && (n % (long long)(a[i])) != 0LL) return res;
	return res + 1LL;
}

int trivial(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i ++)
	{
		int p = i, q = i;
		bool good = true;
		while (q)
		{
			if (q % 10 != 0)
			{
				if (p % (q % 10) != 0) good = false;
			}
			q /= 10;
		}
		if (good) res ++;
	}
	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	precalc();
	int t;
	cin >> t;

	for (int i = 1; i <= t; i ++)
	{
		long long l, r;
		cin >> l >> r;
		cout << calc(r) - calc(l - 1LL) << endl;
	}

	return 0;
}