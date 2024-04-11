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

int N;
int A[1010][1010];

int main()
{
	scanf("%d", &N);
	if (N == 4)
		{
			puts("-1");
			return 0;
		}
	int i, j;
	fortodo(i, 1, N)
		fortodo(j, 1, N)
			A[i][j] = 0;
	int n = N;
	while ((N > 4) && (N != 6))
		{
			fortodo(i, 1, N - 2)
				{
					A[N - 1][i] = 1;
					A[i][N] = 1;
				}
			A[N][N - 1] = 1;
			N -= 2;
		}
	if (N == 3)
		A[2][1] = A[3][2] = A[1][3] = 1;
	else
		A[2][1] = A[3][2] = A[1][3] = A[4][5] = A[5][6] = A[6][4] = A[4][2] = A[4][3] = A[5][3] = A[5][1] = A[6][1] = A[6][2] = A[1][4] = A[2][5] = A[3][6] = 1;
	fortodo(i, 1, n)
		fortodo(j, 1, n)
			printf("%d%s", A[i][j], (j == n) ? "\n" : " ");
}