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

const int MAXN = 100010;

int N, K, A[MAXN];
i64 ANS;

int main()
{
	ANS = 0;
	scanf("%d%d", &N, &K);
	int i;
	fortodo(i, 1, N) scanf("%d", &A[i]);
	fortodo(i, 1, N)
		{
			int p = i - (lower_bound(A + 1, A + N + 1, A[i] - K) - A);
			ANS += p * (p - 1LL) / 2LL;
		}
	cout << ANS << endl;
}