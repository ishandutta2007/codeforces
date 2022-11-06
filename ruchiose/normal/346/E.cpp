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

int SOLVE(bool closed, int A, int N, int P)
{
	if (N * 1LL * A < P)
		return (closed) ? max(A, P - N * A) : ((N) ? A : 0);
	int L = (N * 1LL * A) % P;
	if (L + A <= (P / A) * A)
		N -= L / A + 1;
	int _A = (P / A + 1) * A - P;
	int _N = N * 1LL * A / P;
	return SOLVE(true, _A, _N, A);
}

int main()
{
	int T;
	for (scanf("%d", &T); T; T--)
		{
			int A, N, P, H;
			scanf("%d%d%d%d", &A, &N, &P, &H);
			A %= P;
			int RET = SOLVE(false, A, N, P);
			if (RET > H)
				puts("NO");
			else
				puts("YES");
		}
}