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

#define N 5007
#define A 100007

int n, res;

int a[N];

int dp[N][N];

VI wyst[A];
VI wmod[7];

int mod[N][7];

int front[N];

int lastf[A];
int mf[7];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		wyst[a[i]].pb(i);
		wmod[a[i]%7].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		front[i] = 1;

		if(lastf[a[i]-1])
			front[i] = max(front[i], front[lastf[a[i]-1]]+1);

		if(lastf[a[i]+1])
			front[i] = max(front[i], front[lastf[a[i]+1]]+1);

		if(mf[a[i]%7])
			front[i] = max(front[i], front[mf[a[i]%7]]+1);

		mf[a[i]%7] = i;
		lastf[a[i]] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i>j)
				dp[i][j] = front[j]+1;
			else if(j>i)
				dp[i][j] = front[i]+1;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < 7; ++j)
		{
			if(!wmod[j].empty() && wmod[j].back()>i)
			{
				mod[i][j] = *upper_bound(ALL(wmod[j]), i);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			if(i==j)
				continue;

			int ind = -1;

			dp[i][j] = dp[j][i] = max(dp[i][j], dp[j][i]);

			if(!wyst[a[i]+1].empty() && wyst[a[i]+1].back()>max(i, j))
			{
				ind = *upper_bound(ALL(wyst[a[i]+1]), max(i, j));
				dp[ind][j] = max(dp[ind][j], dp[i][j]+1);
			}

			if(!wyst[a[i]-1].empty() && wyst[a[i]-1].back()>max(i, j))
			{
				ind = *upper_bound(ALL(wyst[a[i]-1]), max(i, j));
				dp[ind][j] = max(dp[ind][j], dp[i][j]+1);
			}

			if(mod[max(i, j)][a[i]%7])
			{
				ind = mod[max(i, j)][a[i]%7];
				dp[ind][j] = max(dp[ind][j], dp[i][j]+1);
			}

			if(!wyst[a[j]+1].empty() && wyst[a[j]+1].back()>max(i, j))
			{
				ind = *upper_bound(ALL(wyst[a[j]+1]), max(i, j));
				dp[i][ind] = max(dp[i][ind], dp[i][j]+1);
			}

			if(!wyst[a[j]-1].empty() && wyst[a[j]-1].back()>max(i, j))
			{
				ind = *upper_bound(ALL(wyst[a[j]-1]), max(i, j));
				dp[i][ind] = max(dp[i][ind], dp[i][j]+1);
			}

			if(mod[max(i, j)][a[j]%7])
			{
				ind = mod[max(i, j)][a[j]%7];
				dp[i][ind] = max(dp[i][ind], dp[i][j]+1);
			}

			res = max(res, dp[i][j]);
		}
	}

	cout << res;
}