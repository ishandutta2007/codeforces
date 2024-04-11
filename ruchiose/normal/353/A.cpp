#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N;
int C, U, L;

int main()
{
	scanf("%d", &N);
	int i;
	C = U = L = 0;
	fortodo(i, 1, N)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			U ^= a & 1;
			L ^= b & 1;
			C += (a ^ b) & 1;
		}
	if (C & 1)
		printf("-1\n");
	else
		if ((C == 0) && (U & 1))
			printf("-1\n");
		else
			printf("%d\n", U & 1);
}