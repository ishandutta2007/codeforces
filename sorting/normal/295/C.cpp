#include<bits/stdc++.h>

using namespace std;

const long long N = 57;
const long long mod = 1e9 + 7;

long long a[2];
long long dp[N][N][4*N];
bool b[N][N][4*N];
long long k;

long long comb[4*N][4*N];
bool bomb[4*N][4*N];

long long calcComb(long long nn, long long kk)
{
	if(nn == kk)
		return 1;
	if(kk == 0)
		return 1;
	if(bomb[nn][kk])
		return comb[nn][kk];

	bomb[nn][kk] = 1;

	if(nn>kk)
		comb[nn][kk] = (calcComb(nn - 1,kk) + calcComb(nn - 1,kk - 1))%mod;
	else 
		comb[nn][kk] = calcComb(nn - 1,kk - 1);

	return comb[nn][kk];
}

long long solve(long long first, long long second, long long left)
{
	if(left == 0)
	{
		if(first == 0 && second ==0)
			return 1;
		return 0;
	}

	if(b[first][second][left])
		return dp[first][second][left];

	b[first][second][left] = 1;

	if(left % 2 == 1)
	{
		for(int i = 0; i <= first; i++)
			for(int j = 0; j <= second; j++)
			{
				if(i+j == 0)
					continue;
				if(i*50 + j*100 > k)
					break;

				long long tmp = solve(first - i, second - j, left - 1)*calcComb(first,i);
				tmp %= mod;
				tmp *= calcComb(second,j);
				tmp %= mod;

				dp[first][second][left] += tmp;
				dp[first][second][left] %= mod;
			}
	}
	else
	{
		for(int i = 0; i <= a[0]-first; i++)
			for(int j = 0; j <= a[1]-second; j++)
			{
				if(i+j == 0)
					continue;
				if(i*50 + j*100 > k)
					break;

				long long tmp;

				tmp = solve(first + i, second + j, left - 1)*calcComb(a[0]-first,i);
				tmp %= mod;
				tmp *= calcComb(a[1]-second,j);
				tmp %= mod;

				dp[first][second][left] += tmp;
				dp[first][second][left] %= mod;
			}
	}

	dp[first][second][left] %= mod;

	return dp[first][second][left];
}

long long realSolve(long long first,long long second, long long left)
{
	return solve(first, second, left) % mod;
}

int main ()
{
	long long n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(long long i = 0; i < n; i++)
	{
		long long x;

		cin >> x;

		if(x == 50)
			a[0]++;
		else
			a[1]++;
	}

	long long ind = -1, res = 0;

	for(int i = 4*n-1; i >= 0; i-=2)
		if(solve(a[0],a[1],i)  != 0)
		{
			//cout << i+1 << "\n" << realSolve(a[0],a[1],i+1) << "\n";
			//return 0;
			ind = i;
			res = solve(a[0],a[1],i);
		}

	cout << ind << "\n" << res << "\n";

	return 0;
}