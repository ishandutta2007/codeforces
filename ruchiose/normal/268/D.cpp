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

const int MOD = 1000000009;

int dp[1010][2][31][31][31];
int N, H;

int main()
{
	scanf("%d%d", &N, &H);
	int i, a, l1, l2, l3;
	fortodo(i, 0, N)
		fortodo(a, 0, 1)
			fortodo(l1, 0, H)
				fortodo(l2, 0, H)
					fortodo(l3, 0, H)
						dp[i][a][l1][l2][l3] = 0;
	dp[0][0][0][0][0] = 1;
	#define att(x) (x += dp[i][a][l1][l2][l3]) %= MOD
	fortodo(i, 0, N - 1)
		fortodo(a, 0, 1)
			fortodo(l1, 0, H)
				fortodo(l2, 0, H)
					fortodo(l3, 0, H)
						if (dp[i][a][l1][l2][l3])
							if (a)
								{
									att(dp[i + 1][a][min(l1 + 1,H)][min(l2 + 1,H)][min(l3 + 1,H)]);
									att(dp[i + 1][l1 == H][min(l2 + 1,H)][min(l3 + 1,H)][H]);
									att(dp[i + 1][l2 == H][min(l1 + 1,H)][min(l3 + 1,H)][H]);
									att(dp[i + 1][l3 == H][min(l1 + 1,H)][min(l2 + 1,H)][H]);
								}
							else
								{
									att(dp[i + 1][a][min(l1 + 1,H)][min(l2 + 1,H)][min(l3 + 1,H)]);
									att(dp[i + 1][l1 == H][1][min(l2 + 1,H)][min(l3 + 1,H)]);
									att(dp[i + 1][l2 == H][1][min(l1 + 1,H)][min(l3 + 1,H)]);
									att(dp[i + 1][l3 == H][1][min(l1 + 1,H)][min(l2 + 1,H)]);
								}
	int ans = 0;
	fortodo(a, 0, 1)
		fortodo(l1, 0, H)
			fortodo(l2, 0, H)
				fortodo(l3, 0, H)
					if ((a == 0) || (l1 < H) || (l2 < H) || (l3 < H))
						att(ans);
	printf("%d\n", ans);
}