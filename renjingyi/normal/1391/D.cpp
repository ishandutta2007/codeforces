#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo = 1e9;
string s[10];
int cnt[10];
int trans[10][10];
bool ok[10][10];
int dp[2][10];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	if(n >= 4)
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i ++)
		cin >> s[i];
	if(n == 2)
	{
		int now = 0;
		cnt[0] = 0;
		cnt[1] = cnt[2] = 1;
		cnt[3] = 2;
		for(int i = 0; i < 4; i ++)
			for(int j = 0; j < 4; j ++)
			{
				trans[i][j] = cnt[i ^ j];
				ok[i][j] = (cnt[i] + cnt[j]) & 1;
			}
		int c = (s[1][0] - '0') | ((s[2][0] - '0') << 1);
		for(int i = 0; i < 4; i ++)
			dp[now][i] = trans[c][i];
		for(int i = 1; i < m; i ++)
		{
			now ^= 1;
			for(int j = 0; j < 4; j ++)
				dp[now][j] = oo;
			c = (s[1][i] - '0') | ((s[2][i] - '0') << 1);
			for(int j = 0; j < 4; j ++)
				for(int k = 0; k < 4; k ++)
					if(ok[j][k])
						dp[now][k] = min(dp[now][k], dp[now ^ 1][j] + trans[c][k]);
		}
		int ans = oo;
		for(int i = 0; i < 4; i ++)
			ans = min(ans, dp[now][i]);
		cout << ans << endl;
	}
	if(n == 3)
	{
		int now = 0;
		cnt[0] = 0;
		cnt[1] = cnt[2] = cnt[4] = 1;
		cnt[3] = cnt[5] = cnt[6] = 2;
		cnt[7] = 3;
		for(int i = 0; i < 8; i ++)
			for(int j = 0; j < 8; j ++)
			{
				trans[i][j] = cnt[i ^ j];
				ok[i][j] = ((cnt[i & 3] + cnt[j & 3]) & 1) & ((cnt[i >> 1] + cnt[j >> 1]) & 1);
			}
		int c = (s[1][0] - '0') | ((s[2][0] - '0') << 1) | ((s[3][0] - '0') << 2);
		for(int i = 0; i < 8; i ++)
			dp[now][i] = trans[c][i];
		for(int i = 1; i < m; i ++)
		{
			now ^= 1;
			for(int j = 0; j < 8; j ++)
				dp[now][j] = oo;
			c = (s[1][i] - '0') | ((s[2][i] - '0') << 1) | ((s[3][i] - '0') << 2);
			for(int j = 0; j < 8; j ++)
				for(int k = 0; k < 8; k ++)
					if(ok[j][k])
						dp[now][k] = min(dp[now][k], dp[now ^ 1][j] + trans[c][k]);
		}
		int ans = oo;
		for(int i = 0; i < 8; i ++)
			ans = min(ans, dp[now][i]);
		cout << ans << endl;
	}
	
	return 0;
}