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

#define N 507

int n;

int c[N];

int dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		memset(dp[i], inf16, sizeof dp[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		dp[i][i] = 1;
	}

	for(int d = 2; d <= n; ++d)
	{
		for(int a = 1; a+d-1 <= n; ++a)
		{
			int b = a+d-1;

			for(int i = a; i < b; ++i)
			{
				dp[a][b] = min(dp[a][b], dp[a][i]+dp[i+1][b]);
			}

			for(int i = 0; ; ++i)
			{
				if(c[a+i]==c[b-i])
					dp[a][b] = min(dp[a][b], dp[a+i+1][b-i-1]);
				else 
					break;

				if(a+i>=b-i)
				{
					dp[a][b] = 1;
					break;
				}
			}	
		}
	}

	cout << dp[1][n];
}