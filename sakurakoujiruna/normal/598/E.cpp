#include <iostream>
#include <cstring>
using namespace std;

const int N = 31;
const int M = 51;
const int Inf = 0x3f3f3f3f;

int memo[N][N][M];
int dp(int n, int m, int k)
{
	if(n * m < k)
		return Inf;
	if(n * m == k || k == 0)
		return 0;
	if(memo[n][m][k] != Inf)
		return memo[n][m][k];
	int ret = Inf;
	for(int t = 0; t < 2; t ++)
	{
		for(int i = 1; i < n; i ++)
			for(int j = 0; j <= k; j ++)
				ret = min(ret, dp(i, m, j) + dp(n - i, m, k - j) + m * m);
		swap(n, m);
	}
	memo[n][m][k] = ret;
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int case_cnt;
	cin >> case_cnt;
	memset(memo, 0x3f, sizeof(memo));
	while(case_cnt --)
	{
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp(n, m, k) << '\n';
	}
	return 0;
}