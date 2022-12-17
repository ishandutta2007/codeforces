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
const long long oo = 1e18;
const int maxn = 1e5 + 5;
long long a[maxn];
long long dp[maxn][4];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	dp[0][1] = dp[0][2] = dp[0][3] = oo;
	for(int i = 1; i <= n; i ++)
	{
		if(s[i - 1] == 'h')
		{
			dp[i][0] = dp[i - 1][0] + a[i];
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
			dp[i][2] = dp[i - 1][2];
			dp[i][3] = dp[i - 1][3];
		}
		else if(s[i - 1] == 'a')
		{
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1] + a[i];
			dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]);
			dp[i][3] = dp[i - 1][3];
		}
		else if(s[i - 1] == 'r')
		{
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2] + a[i];
			dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
		}
		else if(s[i - 1] == 'd')
		{
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
			dp[i][3] = dp[i - 1][3] + a[i];
		}
		else
		{
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
			dp[i][3] = dp[i - 1][3];
		}
	}
	cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << endl;
	
	return 0;
}