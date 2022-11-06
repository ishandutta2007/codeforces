// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N;
int F[222];
int C[222];

i64 gcd(i64 a, i64 b)
{
	return (b) ? gcd(b, a % b) : a;
}

int main()
{
	scanf("%d", &N);
	int i, j;
	fortodo(i, 1, N) scanf("%d", &F[i]);
	i64 ans = 1;
	fortodo(i, 1, N)
		{
			int u = i;
			fortodo(j, 1, N)
				if ((u = F[u]) == i)
					break;
			if (j <= N)
				{
					C[i] = j;
					ans *= j / gcd(j, ans);
				}
			else
				C[i] = 0;
		}
	int dep = 0;
	fortodo(i, 1, N)
		{
			if (C[i]) continue;
			int u = i;
			fortodo(j, 1, N)
				if (C[u = F[u]])
					break;
			dep = max(dep, j);
		}
	i64 ret = ans;
	while (ret < dep) ret += ans;
	cout << ret << endl;
	return 0;
}