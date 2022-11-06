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

const i64 P = int(1e+9) + 7;
const int MAXN = 100010;

int N;
char S[MAXN], T[MAXN];

inline i64 LEG(i64 x)
{
	x %= P; if (x < 0) x += P;
	return x;
}

i64 pow2[MAXN], pow10[MAXN], diaosi[MAXN];
//                           111111111111
i64 sumRaw[MAXN], sumProduct[MAXN];

i64 sumProductWithPrefix(i64 prefix, int tail)
{
	i64 background = prefix * pow10[tail] % P;
	return LEG(background * background % P * (pow2[tail] - 1) + background * LEG(2 * sumRaw[tail] - 11 * diaosi[tail]) + sumProduct[tail]);
}

void preprocess()
{
	int i;
	pow2[0] = 1;
	fortodo(i, 1, N) pow2[i] = (pow2[i - 1] * 2) % P;
	pow10[0] = 1;
	fortodo(i, 1, N) pow10[i] = (pow10[i - 1] * 10) % P;
	diaosi[0] = 0;
	fortodo(i, 1, N) diaosi[i] = (diaosi[i - 1] * 10 + 1) % P;
	sumRaw[0] = 0;
	fortodo(i, 1, N)
		sumRaw[i] = (sumRaw[i - 1] * 2 + (pow2[i - 1] * pow10[i - 1] % P) * 11) % P;
	sumProduct[0] = 0;
	fortodo(i, 1, N)
		sumProduct[i] = LEG(sumProductWithPrefix(4, i - 1) + LEG(4 * pow10[i - 1] + 7 * diaosi[i - 1]) * LEG(7 * pow10[i - 1] + 4 * diaosi[i - 1]) + sumProductWithPrefix(7, i - 1));
}

i64 mainprocess(char* ch)
{
	i64 ANS = 0, prefix = 0;
	int i;
	fortodo(i, 1, N)
		{
			if (ch[i] == '7')
				{
					ANS += sumProductWithPrefix((prefix * 10 + 4) % P, N - i);
					ANS += LEG(LEG(prefix * 10 + 4) * pow10[N - i] + 7 * diaosi[N - i]) * LEG(LEG(prefix * 10 + 7) * pow10[N - i] + 4 * diaosi[N - i]); 
					ANS %= P;
				}
			prefix = (prefix * 10 + ch[i] - '0') % P;
		}
	return ANS;
}

int main()
{
	scanf("%s%s", S + 1, T + 1);
	N = strlen(S + 1);
	preprocess();
	cout << LEG(mainprocess(T) - mainprocess(S)) << endl;
}