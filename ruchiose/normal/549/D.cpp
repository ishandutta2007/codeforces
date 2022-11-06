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

int N, M;

char ch[111][111];
int C[111][111];

int main()
{
	scanf("%d%d", &N, &M);
	int i, j;
	fortodo(i, 0, N)
		fortodo(j, 0, M)
			C[i][j] = 0;
	fortodo(i, 1, N)
		scanf("%s", ch[i] + 1);
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			{
				int a;
				if (ch[i][j] == 'W')
					a = 1;
				else
					a = -1;
				C[i - 1][j - 1] += a;
				C[i - 1][j] -= a;
				C[i][j - 1] -= a;
				C[i][j] += a;
			}
	int ANS = 0;
	fortodo(i, 1, N)
		fortodo(j, 1, M)
			ANS += (C[i][j]) ? 1 : 0;
	printf("%d\n", ANS);
	return 0;
}