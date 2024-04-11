#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const int M = 1211;
int dp[N][M];

void update(int &a, int b)
{
	if(a == -1)
		a = b;
	else
		a = max(a, b);
}

int main()
{
	ios :: sync_with_stdio(false);
	int v1, v2, t, d;
	cin >> v1 >> v2 >> t >> d;

	memset(dp, -1, sizeof(dp));
	dp[0][v1] = v1;
	for(int i = 0; i < t - 1; i ++)
		for(int j = 0; j < M; j ++)
			if(dp[i][j] != -1)
				for(int k = -d; k <= d; k ++)
					if(j + k >= 0 && j + k < M)
						update(dp[i + 1][j + k], dp[i][j] + j + k);
	cout << dp[t - 1][v2] << '\n';
	return 0;
}