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

#define N 407

int n, m;

bitset<N> e[N];

VI G[N], D[N];

int dp[2][N][N];

deque<pair<PII, int> > Q;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a, b;

		cin >> a >> b;

		if(a>b)
			swap(a, b);

		e[a][b] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			if(e[i][j])
			{
				G[i].pb(j);
				G[j].pb(i);
			}
			else
			{
				D[i].pb(j);
				D[j].pb(i);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			dp[0][i][j] = dp[1][i][j] = inf;
		}
	}

	dp[0][1][1] = 0;
	Q.emplace_front(mp(1, 1), 0);

	while(!Q.empty())
	{
		auto v = Q.front();
		Q.pop_front();

		if(v.nd==0)
		{
			for(auto it:G[v.st.st])
			{
				if(dp[1][it][v.st.nd]>dp[0][v.st.st][v.st.nd]+1)
				{
					dp[1][it][v.st.nd] = dp[0][v.st.st][v.st.nd]+1;
					Q.emplace_back(mp(it, v.st.nd), 1);
				}
			}

			if(v.st.st==n && dp[1][v.st.st][v.st.nd]>dp[0][v.st.st][v.st.nd]+1)
			{
				dp[1][v.st.st][v.st.nd] = dp[0][v.st.st][v.st.nd]+1;
				Q.emplace_back(mp(v.st.st, v.st.nd), 1);
			}
		}
		else
		{
			for(auto it:D[v.st.nd])
			{
				if((v.st.st!=it || v.st.st==n) && dp[0][v.st.st][it]>dp[1][v.st.st][v.st.nd])
				{
					dp[0][v.st.st][it] = dp[1][v.st.st][v.st.nd];
					Q.emplace_front(mp(v.st.st, it), 0);
				}
			}

			if(v.st.nd==n && dp[0][v.st.st][v.st.nd]>dp[1][v.st.st][v.st.nd])
			{
				dp[0][v.st.st][v.st.nd] = dp[1][v.st.st][v.st.nd];
				Q.emplace_back(mp(v.st.st, v.st.nd), 0);
			}
		}
	}

	if(dp[0][n][n]==inf)
		cout << -1;
	else
		cout << dp[0][n][n];
}