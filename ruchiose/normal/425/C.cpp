#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXC = 310;

int N, M, S, E, C, i, j;
int A[MAXN], dp[MAXC];
vector<int> B[MAXN];

int main()
{
	scanf("%d%d%d%d", &N, &M, &S, &E);
	C = S / E;
	fortodo(i, 1, 100000) B[i].clear();
	fortodo(i, 1, N) scanf("%d", &A[i]);
	fortodo(i, 1, M)
		{
			scanf("%d", &j);
			B[j].push_back(i);
		}
	fortodo(i, 1, C) dp[i] = M + 1;
	dp[0] = 0;
	int ANS = 0;
	fortodo(i, 1, N)
		for (j = C; j; j--)
			{
				vector<int>::iterator p = upper_bound(B[A[i]].begin(), B[A[i]].end(), dp[j - 1]);
				if (p != B[A[i]].end())
					{
						dp[j] = min(dp[j], *p);
						if (S - E * j >= (i + dp[j]))
							ANS = max(ANS, j);
					}
			}
	printf("%d\n", ANS);
}