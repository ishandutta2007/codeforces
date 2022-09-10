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
#define SIZE(x) (int)(x).size()
using namespace std;

#define N 307

int n, ans = inf;

VI fact[N];

int c[N];
int l[N];

int dp[1<<10];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> l[i];

		int curr = l[i];

		for(int j = 2; j*j <= l[i]; ++j)
		{
			if(curr%j==0)
			{
				while(curr%j==0)
					curr /= j;

				fact[i].pb(j);
			}
		}

		if(curr>1)
			fact[i].pb(curr);
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		memset(dp, inf16, sizeof dp);

		int d = fact[i].size();

		dp[(1<<d)-1] = c[i];

		for(int j = i+1; j <= n; ++j)
		{
			for(int m = 0; m < (1<<d); ++m)
			{
				int curr = m;

				for(int k = 0; k < d; ++k)
				{
					if(l[j]%fact[i][k])
						curr &= ~(1<<k);
				}

				dp[curr] = min(dp[curr], dp[m]+c[j]);
			}
		}

		ans = min(ans, dp[0]);
	}

	if(ans==inf)
		cout << -1;
	else
		cout << ans;
}