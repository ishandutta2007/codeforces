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
const int maxn = 405, maxm = 250005;
long long q[maxn];
int s[maxm], f[maxm], c[maxm], r[maxm];
vector<int> con[maxn];
long long dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> q[i];
	for(int i = 1; i <= m; i ++)
	{
		cin >> s[i] >> f[i] >> c[i] >> r[i];
		con[s[i]].push_back(i);
	}
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
			dp[0][j] = q[j] - q[i];
		for(int k = 1; k <= n; k ++)
		{
			int pos = i;
			for(int j = i + 1; j <= n; j ++)
			{
				for(; pos < j - 1 && max(dp[k - 1][pos], q[j] - q[pos]) > max(dp[k - 1][pos + 1], q[j] - q[pos + 1]); pos ++);
				dp[k][j] = max(dp[k - 1][pos], q[j] - q[pos]);
			}
		}
		for(int j = 0; j < con[i].size(); j ++)
		{
			int now = con[i][j];
			ans = max(ans, c[now] * dp[r[now]][f[now]]);
		}
	}
	cout << ans << endl;
	
	return 0;
}