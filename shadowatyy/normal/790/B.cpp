#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 200007

int n, k, a, b;

ll res;

VI G[N];

int p[N];

int sub[N];

ll dp[N][5];

ll dpd[N];

void dfs(int v)
{
	sub[v] = 1;
	++dp[v][0];

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			p[it] = v;
			dfs(it);

			for(int i = 0; i < k; ++i)
			{
				for(int j = 0; j < k; ++j)
				{
					if(i+j+1>k)
						res += dp[it][i]*dp[v][j]*2;
					else
						res += dp[it][i]*dp[v][j];
				}
			}

			res += sub[it]*dpd[v];
			res += sub[v]*dpd[it];

			for(int i = 0; i < k; ++i)
			{
				dp[v][(i+1)%k] += dp[it][i];
			}

			sub[v] += sub[it];

			dpd[v] += dpd[it]+dp[it][k-1];
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	p[1] = 1;

	dfs(1);

	cout << res;
}