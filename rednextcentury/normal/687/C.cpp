#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int c[5001];
bool dp[2][501][501];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int p = i % 2;
		for (int j = 0; j <= k; j++)
		{
			for (int x = 0; x <= k; x++)
			{
				if (j >= c[i])
					dp[p][j][x] |= dp[!p][j - c[i]][x];
				if (x >= c[i])
					dp[p][j][x] |= dp[!p][j][x - c[i]];
				dp[p][j][x] |= dp[!p][j][x];
			}
		}
	}

	vector<int> ret;
	for (int i = 0; i <= k; i++)
		if (dp[n % 2][i][k - i])
			ret.push_back(i);
	cout << ret.size() << endl;
	for (auto x : ret)
		cout << x << ' ';
	cout << endl;
	return 0;
}