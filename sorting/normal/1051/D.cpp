#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 1000 + 7;
const long long mod = 998244353;

long long dp[N][2*N][3][3];
bool b[N][2*N][3][3];

long long n;

long long solve(long long pos, long long left, long long pr0, long long pr1)
{
	if(pos == 0)
	{
		if(pr0 != pr1)
			left -= 2;
		else
			left--;

		if(left == 0)
			return 1;

		return 0;
	}
	if(left < 0)
		return 0;

	if(b[pos][left][pr0][pr1])
		return dp[pos][left][pr0][pr1];

	b[pos][left][pr0][pr1] = true;

	long long& res = dp[pos][left][pr0][pr1];

	if(pr0 != pr1)
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
			{
				long long newLeft = left;

				if(pr0 != i)
					newLeft--;
				if(pr1 != j)
					newLeft--;

				res += solve(pos - 1, newLeft, i, j);
			}

		res %= mod;
	}
	else
	{
		if(pr0 == 2)
		{
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
				{
					res += solve(pos - 1, left, i, j);
				}

			res %= mod;
		}
		else
		{
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++)
				{
					long long newLeft = left;

					if(pr0 != i && pr1 != j)
						newLeft--;

					res += solve(pos - 1, newLeft, i, j);
				}

			res %= mod;
		}
	}

	return res;
}

int main ()
{
	long long x, y;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;

	cout << solve(x, y, 2, 2) << "\n";

	return 0;
}