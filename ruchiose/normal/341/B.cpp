#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int N, i, j, A[MAXN];
int lis[MAXN];

int main()
{
	scanf("%d", &N);
	fortodo(i, 1, N) scanf("%d", &A[i]);
	lis[0] = 1;
	lis[1] = A[1];
	fortodo(i, 2, N)
		if (lis[lis[0]] < A[i])
			lis[++lis[0]] = A[i];
		else
			{
				j = upper_bound(lis + 1, lis + lis[0] + 1, A[i]) - lis;
				lis[j] = A[i];
			}
	printf("%d\n", lis[0]);
}