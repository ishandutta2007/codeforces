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
const int maxn = 500005;
int dp[maxn][5];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		for(int j = 0; j <= 4; j ++)
			dp[i + 1][j] = dp[i][j];
		if(s[i] == '[')
			dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + 1);
		else if(s[i] == ':')
		{
			if(dp[i][1] > 0)
				dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + 1);
			if(dp[i][2] > 0)
				dp[i + 1][3] = max(dp[i + 1][3], dp[i][2] + 1);
		}
		else if(s[i] == '|')
		{
			if(dp[i][2] > 0)
				dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + 1);
		}
		else if(s[i] == ']')
		{
			if(dp[i][3] > 0)
				dp[i + 1][4] = max(dp[i + 1][4], dp[i][3] + 1);
		}
	}
	cout << (dp[s.size()][4] > 0 ? dp[s.size()][4] : -1) << endl;
	
	return 0;
}