#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

int N, M, K, X;
LL	f[55], g[55], h[55];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	K = read(), X = read(), N = read(), M = read();
	for (int s1 = 0; s1 <= N / 2; ++ s1)
	for (int s2 = 0; s2 <= M / 2; ++ s2)
	{
		for (int a = 0; a < 2; ++ a)
		for (int b = 0; b < 2; ++ b)
		for (int c = 0; c < 2; ++ c)
		for (int d = 0; d < 2; ++ d)
		{
			if (s1 + s1 + a + b <= N && s2 + s2 + c + d <= M)
			{
				f[1] = s1, g[1] = a, h[1] = b;
				f[2] = s2, g[2] = c, h[2] = d;
				for (int i = 3; i <= K; ++ i)
				{
					f[i] = f[i - 2] + f[i - 1];
					if (h[i - 2] && g[i - 1])	f[i] ++;
					g[i] = g[i - 2];
					h[i] = h[i - 1];
					if (f[i] > X)
					{
						f[K] = X + 1;
						break;
					}
				}
				if (f[K] == X)
				{
					if (a)	printf("C");
					for (int i = 1; i <= s1; ++ i)	printf("AC");
					for (int i = 1; i <= N - s1 - s1 - a - b; ++ i)	printf("B");
					if (b)	printf("A");
					printf("\n");
					
					if (c)	printf("C");
					for (int i = 1; i <= s2; ++ i)	printf("AC");
					for (int i = 1; i <= M - s2 - s2 - c - d; ++ i)	printf("B");
					if (d)	printf("A");
					printf("\n");
					return 0;
				}
			} 
		}
	}
	printf("Happy new year!\n");

	return 0;
}