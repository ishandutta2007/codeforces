#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
int a[20], b[20], c[20], d[20];

int dp[11][1100];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d%d%d", &n, &m, &c[0], &d[0]);
	for (int i = 1; i <= m; i ++)
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	for (int i = 0; i <= n; i ++)
		if (c[0] * i <= n)
			dp[0][c[0] * i] = d[0] * i;

	for (int i = 1; i <= m; i ++)
		for (int j = 0; j <= n; j ++)
			for (int k = 0; k <= j && k * b[i] <= a[i] && k * c[i] <= j; k ++)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i]] + k * d[i]);
	int res = 0;
	for (int i = 0; i <= n; i ++)
		res = max(res, dp[m][i]);
	cout << res << endl;
	return 0;
}