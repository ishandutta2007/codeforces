// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const i64 MOD = 1000000009; 

int N, W, B;
i64 fact[4040];

i64 inv(i64 x)
{
	i64 r = 1;
	for (i64 t = MOD - 2; t; t >>= 1)
		{
			if (t & 1) r = (r * x) % MOD;
			x = (x * x) % MOD;
		}
	return r;
}

i64 bino(int n, int m)
{
	if (m < 0) return 0;
	if (m > n) return 0;
	return fact[n] * (inv(fact[m]) * inv(fact[n - m]) % MOD) % MOD;
}

i64 distri(int s, int x)
{
	return bino(s - 1, x - 1);
}

int main()
{
	scanf("%d%d%d", &N, &W, &B);
	fact[0] = 1;
	int i;
	fortodo(i, 1, 4000) fact[i] = (fact[i - 1] * i) % MOD;
	i64 ret = 0;
	fortodo(i, 1, N - 2)
		{
			i64 wh = (fact[W] * distri(W, N - i) % MOD) * (N - i - 1) % MOD;
			i64 bh = (fact[B] * distri(B, i) % MOD);
			ret += wh * bh % MOD;
			ret %= MOD;
		}
	cout << ret << endl;
}