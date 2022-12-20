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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 2005;
char c[maxn][maxn];
int dp[maxn][maxn];
bool mark[maxn][maxn];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> c[i][j];
	dp[1][1] = c[1][1] != 'a';
	for(int i = 2; i <= n; i ++)
	{
		dp[1][i] = dp[1][i - 1] + (c[1][i] != 'a');
		dp[i][1] = dp[i - 1][1] + (c[i][1] != 'a');
	}
	for(int i = 2; i <= n; i ++)
		for(int j = 2; j <= n; j ++)
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (c[i][j] != 'a');
	if(dp[n][n] <= k)
	{
		for(int i = 1; i <= 2 * n - 1; i ++)
			cout << 'a';
		cout << endl;
		return 0;
	}
	int mx = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(dp[i][j] == k)
				mx = max(mx, i + j - 1);
	vector<pp> now;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(dp[i][j] == k && i + j - 1 == mx)
			{
				now.push_back(mp(i, j));
				//cout << "push : " << i << " " << j << endl;
			}
//	for(int i = 1; i <= n; i ++)
//		for(int j = 1; j <= n; j ++)
//			cout << "dp : " << i << " " << j << " " << dp[i][j] << endl;
	for(int i = 1; i <= mx; i ++)
		cout << 'a';
	for(int i = 0; i <= n + 1; i ++)
		mark[i][0] = mark[0][i] = mark[n + 1][i] = mark[i][n + 1] = 1;
	if(k == 0)
		now.push_back(mp(0, 1)); 
	for(int i = mx + 1; i <= 2 * n - 1; i ++)
	{
		//cout << "begin : " << i << endl;
		vector<pp> next;
		int go = 27;
		for(int j = 0; j < now.size(); j ++)
		{
			int x = now[j].first, y = now[j].second;
			for(int k = 0; k < 2; k ++)
				if(!mark[x + dx[k]][y + dy[k]])
					go = min(go, c[x + dx[k]][y + dy[k]] - 'a');
		}
		//cout << "go : " << go << endl;
		for(int j = 0; j < now.size(); j ++)
		{
			int x = now[j].first, y = now[j].second;
			for(int k = 0; k < 2; k ++)
				if(!mark[x + dx[k]][y + dy[k]] && c[x + dx[k]][y + dy[k]] - 'a' == go)
				{
					next.push_back(mp(x + dx[k], y + dy[k]));
					//cout << "get : " << x + dx[k] << " " << y + dy[k] << endl;
					mark[x + dx[k]][y + dy[k]] = 1;
				}
		}
		cout << (char)(go + 'a');
		now = next;
	}
	
	return 0;
}