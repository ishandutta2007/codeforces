#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 57;

int n, m;

char g[N][N];
int ans[N][N];

VI G[2*N];

bitset<2*N> vis;

VI comp;

void dfs(int v)
{
	vis[v] = 1;
	comp.pb(v);

	for(auto it:G[v])
	{
		if(!vis[it])
			dfs(it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> g[i][j];

			if(g[i][j]=='#')
			{
				G[i].pb(n+j);
				G[n+j].pb(i);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			comp.clear();
			dfs(i);

			for(auto x:comp)
			{
				for(auto y:comp)
				{
					if(x<=n && y>n)
						ans[x][y-n] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		if(!vis[n+i])
		{
			comp.clear();
			dfs(n+i);

			for(auto x:comp)
			{
				for(auto y:comp)
				{
					if(x<=n && y>n)
						ans[x][y-n] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if((ans[i][j] && g[i][j]=='.') || (!ans[i][j] && g[i][j]=='#'))
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
}