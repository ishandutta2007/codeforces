#include <bits/stdc++.h>

const int N = 2007;
const int S = 1e5 + 7;
const int K = 11;
const int inf = 1e9;

int a[N][N];
int q[S];

int dp[K][K];
int n, m, k, s;

void solve(int num[2])
{
	int sum_mn[2] = {inf, inf}, sum_mx[2] = {-inf, -inf}, sub_mn[2] = {inf, inf}, sub_mx[2] = {-inf, -inf};


	for(int ind = 0; ind < 2; ind++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(a[i][j] == num[ind])
				{
					sum_mn[ind] = std::min(sum_mn[ind], i+j);
					sum_mx[ind] = std::max(sum_mx[ind], i+j);
					sub_mn[ind] = std::min(sub_mn[ind], i-j);
					sub_mx[ind] = std::max(sub_mx[ind], i-j);
				}

	int &res = dp[num[0]][num[1]];

	res = std::max(res, sum_mx[0] - sum_mn[1]);
	res = std::max(res, sum_mx[1] - sum_mn[0]);
	res = std::max(res, sub_mx[0] - sub_mn[1]);
	res = std::max(res, sub_mx[1] - sub_mn[0]);

	return ;
}

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> n >> m >> k >> s;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> a[i][j];

	for(int i = 0; i < s; i++)
		std::cin >> q[i];

	int arr[2];

	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= k; j++)
		{
			arr[0] = i;
			arr[1] = j;
			solve(arr);
		}

	int res = -inf;

	for(int i = 1; i < s; i++)
		res = std::max(res, dp[ q[i-1] ][ q[i] ]);

	std::cout << res << "\n";

	return 0;
}