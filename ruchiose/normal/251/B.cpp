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

const int MAXN = 110;

int N, K;
int Q[MAXN], iQ[MAXN], T[MAXN], id[MAXN];

void Permcpy(int* S, int* T)
{
	int i;
	fortodo(i, 1, N) T[i] = S[i];
}

bool Permcmp(int* S, int* T)
{
	int i;
	fortodo(i, 1, N)
		if (S[i] != T[i])
			return false;
	return true;
}

void Apply(int *A, int *Q)
{
	static int P[MAXN];
	int i;
	fortodo(i, 1, N) P[i] = Q[A[i]];
	Permcpy(P, A);
}

int main()
{
	scanf("%d%d", &N, &K);
	int i;
	fortodo(i, 1, N) scanf("%d", &Q[i]);
	fortodo(i, 1, N) iQ[Q[i]] = i;
	fortodo(i, 1, N) scanf("%d", &T[i]);
	fortodo(i, 1, N) id[i] = i;
	static int y[MAXN];
	if (Permcmp(id, T))
		{
			puts("NO");
			return 0;
		}
	int ln = K + 1, rn = K + 1;
	Permcpy(id, y);
	fortodo(i, 1, K)
		{
			Apply(y, Q);
			if (Permcmp(y, T))
				{
					rn = i;
					break;
				}
		}
	Permcpy(id, y);
	fortodo(i, 1, K)
		{
			Apply(y, iQ);
			if (Permcmp(y, T))
				{
					ln = i;
					break;
				}
		}
	if (ln + rn == 2)
		if (K == 1)
			printf("YES\n");
		else
			printf("NO\n");
	else
		if (((K >= ln) && ((K - ln) % 2 == 0)) || ((K >= rn) && ((K - rn) % 2 == 0)))
			printf("YES\n");
		else
			printf("NO\n"); 
}