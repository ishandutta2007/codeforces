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

int n, res, k;

ll e[47];

int dp[1<<20];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;

			if(a)
			{
				e[i] |= (1ll<<j);
				e[j] |= (1ll<<i);
			}
		}
	}

	int m = n/2;

	for(int i = 0; i < (1<<m); ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(i&(1<<j))
				dp[i] = max(dp[i], dp[i^(1<<j)]);
		}

		int c = i;

		for(int j = 0; j < m; ++j)
		{
			if(i&(1<<j))
				c &= e[j]|(1<<j);
		}

		if(c==i)
			dp[i] = __builtin_popcount(i);
	}

	res = dp[(1<<m)-1];

	for(int i = 0; i < (1<<(n-m)); ++i)
	{
		int c = i;

		for(int j = 0; j < n-m; ++j)
		{
			if(i&(1<<j))
				c &= (e[j+m]>>m)|(1<<j);
		}

		if(c==i)
		{
			int adj = (1<<m)-1;

			for(int j = 0; j < n-m; ++j)
			{
				if(i&(1<<j))
					adj &= e[j+m];
			}

			res = max(res, __builtin_popcount(i)+dp[adj]);
		}
	}

	cout << fixed << " " << setprecision(10) << (double)k*k*(res-1)/res/2;
}