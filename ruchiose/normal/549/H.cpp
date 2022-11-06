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

int A, B, C, D;

pair<d64,d64> Rg(d64 a, d64 b, d64 r)
{
	d64 I = 1e+100, A = -1e+100;
	I = min(I, (a - r) * (b - r));
	A = max(A, (a - r) * (b - r));
	I = min(I, (a - r) * (b + r));
	A = max(A, (a - r) * (b + r));
	I = min(I, (a + r) * (b - r));
	A = max(A, (a + r) * (b - r));
	I = min(I, (a + r) * (b + r));
	A = max(A, (a + r) * (b + r));
	return make_pair(I, A);
}

int main()
{
	scanf("%d%d%d%d", &A, &B, &C, &D);
	if (A * 1LL * D == B * 1LL * C)
		{
			printf("0\n");
			return 0;
		}
	d64 L = 0, R = max(max(abs(A), abs(B)), max(abs(C), abs(D)));
	for (int Rnd = 300; Rnd; Rnd--)
		{
			d64 Mid = (L + R) / 2;
			pair<d64,d64> AD, BC;
			AD = Rg(A, D, Mid);
			BC = Rg(B, C, Mid);
			if (max(AD.first, BC.first) <= min(AD.second, BC.second) + 1e-30)
				R = Mid;
			else
				L = Mid;
		}
	printf("%.9f\n", double(R));
	return 0;
}