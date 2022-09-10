#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 17

char g[N][N];

int dp[N][N];

bool check()
{
	for(int i = 1; i <= 10; ++i)
	{
		memset(dp[i], 0, sizeof dp[i]);
	}

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(g[i][j]=='X')
				dp[i][j] = dp[i-1][j]+1;

			if(dp[i][j]==5)
				return 1;
		}
	}

	for(int i = 1; i <= 10; ++i)
	{
		memset(dp[i], 0, sizeof dp[i]);
	}

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(g[i][j]=='X')
				dp[i][j] = dp[i][j-1]+1;

			if(dp[i][j]==5)
				return 1;
		}
	}

	for(int i = 1; i <= 10; ++i)
	{
		memset(dp[i], 0, sizeof dp[i]);
	}

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(g[i][j]=='X')
				dp[i][j] = dp[i-1][j-1]+1;

			if(dp[i][j]==5)
				return 1;
		}
	}

	for(int i = 1; i <= 10; ++i)
	{
		memset(dp[i], 0, sizeof dp[i]);
	}

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(g[i][j]=='X')
				dp[i][j] = dp[i-1][j+1]+1;

			if(dp[i][j]==5)
				return 1;
		}
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			cin >> g[i][j];
		}
	}

	for(int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			if(g[i][j]=='.')
			{
				g[i][j] = 'X';

				if(check())
				{
					cout << "YES";
					return 0;
				}

				g[i][j] = '.';
			}
		}
	}

	cout << "NO";
}