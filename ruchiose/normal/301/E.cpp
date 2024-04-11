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

const int MOD = int(1e+9) + 7;

int N, M, K;
int Bino[110][110];
int ANS = 0;

inline int Distribute(int a, int b)
{
	return Bino[a - 1][b - 1];
}

int dp[2][110][110][110];

void init(int x)
{
	int i, j, k;
	fortodo(i, 1, N)
		fortodo(j, 1, K)
			fortodo(k, 0, N)
				dp[x][i][j][k] = 0;
}

void stat(int x, int rate)
{
	int sub = 0, i, j;
	fortodo(i, 1, N)
		fortodo(j, 1, K)
			sub = (sub + dp[x][i][j][0]) % MOD;
	ANS = (ANS + sub * 1LL * rate) % MOD;
}

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	int i, j, k, m, n;
	fortodo(i, 0, N)
		{
			Bino[i][0] = Bino[i][i] = 1;
			fortodo(j, 1, i - 1)
				Bino[i][j] = min(Bino[i - 1][j - 1] + Bino[i - 1][j], K + 1);
		}
	init(0);
	fortodo(i, 1, N)
		dp[0][i][1][i] = 1;
	fortodo(k, 2, M)
		{
			int cur = k & 1, nxt = cur ^ 1;
			stat(cur, M - k + 2);
			init(nxt);
			fortodo(i, 1, N)
				fortodo(j, 1, K)
					fortodo(m, 1, N)
						if (dp[cur][i][j][m])
							fortodo(n, m, N - i)
								{
									int nj = j * Distribute(n, m);
									if (nj <= K)
										if ((dp[nxt][i + n][nj][n - m] += dp[cur][i][j][m]) >= MOD)
											dp[nxt][i + n][nj][n - m] -= MOD;
								}
		}
	stat((~M) & 1, 1);
	printf("%d\n", ANS);
}