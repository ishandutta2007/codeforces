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
const int MAXN = 100010;
const string s = "ACGT";

int N, C[4];
char ch[MAXN];

i64 Qipow(i64 bas, i64 t)
{
	i64 ans = 1;
	for (; t; t >>= 1)
		{
			if (t & 1)
				ans = (ans * bas) % MOD;
			bas = (bas * bas) % MOD;
		}
	return ans;
}

int main()
{
	scanf("%d%s", &N, &ch);
	int i, j;
	fortodo(i, 0, 3)
		{
			C[i] = 0;
			fortodo(j, 0, N - 1)
				if (s[i] == ch[j])
					C[i]++;
		}
	int maxfreq = 0;
	fortodo(i, 0, 3) maxfreq = max(maxfreq, C[i]);
	int maxtype = 0;
	fortodo(i, 0, 3)
		if (maxfreq == C[i])
			maxtype++;
	cout << Qipow(maxtype, N) << endl;
	return 0;
}