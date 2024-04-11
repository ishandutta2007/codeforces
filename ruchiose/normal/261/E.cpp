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

const int MAGIC = 3333333;

int L, R, p;
int P[50];
int A[MAGIC], dp[MAGIC], Q[MAGIC];

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void DFS(int x, int a, bool sig)
{
	if (sig) A[++A[0]] = x;
	if (a > P[0]) return;
	DFS(x, a + 1, false);
	if (x <= R / P[a]) DFS(x * P[a], a, true);
}

int main()
{
	scanf("%d%d%d", &L, &R, &p);
	P[0] = 0;
	int i;
	fortodo(i, 2, p)
		if (isPrime(i))
			P[++P[0]] = i;
	A[0] = 0;
	DFS(1, 1, true);
	sort(A + 1, A + A[0] + 1);
	fortodo(i, 1, A[0]) dp[i] = Q[i] = 2333;
	dp[1] = 0; Q[1] = 0;
	fortodo(i, 2, p)
		{
			int j, r = 1;
			fortodo(j, 1, A[0])
				{
					if (A[j] > A[A[0]] / i) break;
					while (A[r] != A[j] * i) r++;
					dp[r] = min(dp[r], dp[j] + 1);
					Q[r] = min(Q[r], dp[r] + i);
				}
		}
	int ans = 0;
	fortodo(i, 1, A[0])
		if ((A[i] >= L) && (Q[i] <= p))
			ans++;
	printf("%d\n", ans);
}