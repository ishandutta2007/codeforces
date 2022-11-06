// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N, T;
int dp[110][1010];

vector<int> VI[110];

int main()
{
	scanf("%d%d", &N, &T);
	int i, j;
	fortodo(i, 0, T) VI[i].clear();
	fortodo(i, 1, N)
		{
			int t, q;
			scanf("%d%d", &t, &q);
			VI[t].push_back(q);
		}
	fortodo(i, 0, T)
		{
			sort(VI[i].begin(), VI[i].end());
			reverse(VI[i].begin(), VI[i].end());
		}
	fortodo(i, 0, T)
		fortodo(j, 0, N)
			dp[i][j] = -(1<<28);
	dp[T][1] = 0;
	for (i = T; i; i--)
		fortodo(j, 0, N)
			{
				int sum = dp[i][j], cnt = j;
				dp[i - 1][min(N, cnt * 2)] = max(dp[i - 1][min(N, cnt * 2)], sum);
				for (vector<int>::iterator it = VI[i].begin(); it != VI[i].end(); it++)
					{
						if (cnt == 0) break;
						cnt--;
						sum += *it;
						dp[i - 1][min(N, cnt * 2)] = max(dp[i - 1][min(N, cnt * 2)], sum);
					}
			}
	int ans = 0;
	fortodo(i, 0, N) ans = max(ans, dp[0][i]);
	cout << ans << endl;
	return 0;
}