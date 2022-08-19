#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 200005
#define ld long double
using namespace std;
int dp[105][maxn];
int n, k, l[maxn], r[maxn];
int q[maxn][2];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
		scanf("%d%d", &l[i + 1], &r[i + 1]);
	l[1] = r[1] = 0;
	l[k + 2] = r[k + 2] = n * 2;
	for(int i = 0; i <= 2 * n; i++)
		dp[k + 2][i] = maxn;
	dp[k + 2][n] = 0;
	int fr, ed;
	for(int i = k + 1; i >= 1; i--)
	{
		for(int j = 0; j <= 2 * n; j++)
			dp[i][j] = maxn;
		//check 0
		for(int j = 0; j <= n; j++)
		{
			int ed = j + l[i + 1] - l[i];
			if(ed <= 2 * n && ed >= 0)
				dp[i][j] = min(dp[i][j], dp[i + 1][ed]);
		}
		//check 1
		fr = ed = 0;
		for(int j = 2 * n; j >= 0; j--)
		{
			while(ed > fr && q[ed - 1][1] >= dp[i + 1][j])
				ed--;
			q[ed][0] = j, q[ed++][1] = dp[i + 1][j];
			if(q[fr][0] == j + r[i] - l[i] + 1)
				fr++;
			if(fr < ed)
			{
				int npl = j - (l[i + 1] - r[i]);
				npl = l[i] - npl;
				if(npl >= 0 && npl <= 2 * n)
					dp[i][npl] = min(dp[i][npl], q[fr][1] + 1);
			}
		}
		//check 2
		fr = ed = 0;
		for(int j = 2 * n; j >= 0; j--)
		{
			while(ed > fr && q[ed - 1][1] >= dp[i + 1][j])
				ed--;
			q[ed][0] = j, q[ed++][1] = dp[i + 1][j];
			if(q[fr][0] == j + r[i] - l[i] + 1)
				fr++;
			if(fr < ed)
			{
				int npl = j - (l[i + 1] - r[i]);
				if(npl >= 0 && npl <= 2 * n)
					dp[i][npl] = min(dp[i][npl], q[fr][1] + 2);
			}
		}
	}
	if(dp[1][0] >= maxn) printf("Hungry\n");
	else printf("Full\n%d\n", dp[1][0]);
}
/*
9
1 1 1 1 1 1 1 1 1
-8 -1 -2 -4 -4 -2 -3 -4 -5
1 2
1 3
1 4
1 5
5 6
4 7
3 8
2 9

*/