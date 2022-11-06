// Author: Ruchiose, on zhzxpc
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#define i64 long long

const i64 MOD = 1000000007;

i64 Qipow(i64 bas, i64 t)
{
	i64 ans = 1;
	for (; t; t >>= 1)
		{
			if (t & 1) ans = (ans * bas) % MOD;
			bas = (bas * bas) % MOD;
		}
	return ans;
}

i64 Inv(i64 x)
{
	return Qipow(x, MOD - 2);
}

const int MAXN = 100010;

int N, K, D[MAXN];
i64 Fact[MAXN], pow10[MAXN];
char ch[MAXN];

i64 Comb(int N, int M)
{
	return (Fact[N] * Inv(Fact[M]) % MOD) * Inv(Fact[N - M]) % MOD;
}

int main()
{
	scanf("%d%d%s", &N, &K, ch + 1);
	if (K == 0)
		{
			i64 ans = 0;
			int i;
			fortodo(i, 1, N)
				ans = (ans * 10 + (ch[i] - '0')) % MOD;
			cout << ans << endl;
			return 0;
		}
	int i;
	fortodo(i, 1, N) D[i] = ch[i] - '0';
	D[0] = 0;
	fortodo(i, 1, N) D[i] += D[i - 1];
	Fact[0] = 1;
	fortodo(i, 1, N)
		Fact[i] = (Fact[i - 1] * i) % MOD;
	pow10[0] = 1;
	fortodo(i, 1, N)
		pow10[i] = (pow10[i - 1] * 10) % MOD;
	i64 ans = 0;
	fortodo(i, 0, N - K - 1)
		{
			i64 subans = 0;
			subans += D[N - 1 - i] * Comb(N - i - 2, K - 1);
			subans += (ch[N - i] - '0') * Comb(N - i - 1, K);
			subans %= MOD;
			ans += subans * pow10[i];
			ans %= MOD;
		}
	cout << ans << endl;
	return 0;
}