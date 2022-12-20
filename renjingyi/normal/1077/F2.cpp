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
const int maxn = 5005;
long long dp[maxn][maxn];
long long q[maxn];
long long a[maxn];
int st = 0, ed = 0;
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		dp[0][i] = -1e18;
	for(int i = 1; i <= x; i ++)
	{
		st = ed = q[0] = 0;
		ed ++;
		for(int j = 1; j <= n; j ++)
		{
			for(; st < ed && q[st] < j - k; st ++);
			dp[i][j] = dp[i - 1][q[st]] + a[j];
			for(; st < ed && dp[i - 1][q[ed - 1]] <= dp[i - 1][j]; ed --);
			q[ed ++] = j;
		}
	}
	long long ans = -1e18;
	for(int i = n; i >= n - k + 1; i --)
		ans = max(ans, dp[x][i]);
	cout << (ans > 0 ? ans : -1) << endl;
	
	return 0;
}