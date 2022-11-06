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

const int M = 30000;
const int L = 250;
const int INF = 0x23333333;

int N, D, S[M+1];
int DP[M+1][(L<<1)+10];

int main()
{
	int i, j;
	fortodo(i, 0, M) S[i] = 0;
	scanf("%d%d", &N, &D);
	int MI = max(1, D - L), MA = D + L;
	fortodo(i, 1, N)
		{
			int u;
			scanf("%d", &u);
			S[u]++;
		}
	fortodo(i, 0, M)
		fortodo(j, 0, MA - MI)
			DP[i][j] = -INF;
	DP[D][D - MI] = S[D];
	fortodo(i, D, M)
		fortodo(j, MI, MA)
			if (DP[i][j - MI] >= 0)
				{
					if (i + j - 1 <= M)
						DP[i + j - 1][j - 1 - MI] = max(DP[i + j - 1][j - 1 - MI], DP[i][j - MI] + S[i + j - 1]);
					if (i + j <= M)
						DP[i + j][j - MI] = max(DP[i + j][j - MI], DP[i][j - MI] + S[i + j]);
					if (i + j + 1 <= M)
						DP[i + j + 1][j + 1 - MI] = max(DP[i + j + 1][j + 1 - MI], DP[i][j - MI] + S[i + j + 1]);
				}
	int ANS = -INF;
	fortodo(i, 0, M)
		fortodo(j, 0, MA - MI)
			ANS = max(ANS, DP[i][j]);
	printf("%d\n", ANS);		
}