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

#define N 107

int n, m;

char g[N][N];

bitset<256> vis;

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
		}
	}

	if(n%3==0)
	{
		char curr = -1;

		bool ok = 1;

		vis.reset();

		for(int i = 1; i <= n/3; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		curr = -1;

		for(int i = n/3+1; i <= 2*n/3; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		curr = -1;

		for(int i = 2*n/3+1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		if(ok && vis.count()==3)
		{
			cout << "YES";
			return 0;
		}
	}

	if(m%3==0)
	{
		char curr = -1;

		bool ok = 1;

		vis.reset();

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m/3; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		curr = -1;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = m/3+1; j <= 2*m/3; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		curr = -1;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 2*m/3+1; j <= m; ++j)
			{
				if(curr==-1)
					curr = g[i][j];
				else if(curr!=g[i][j])
					ok = 0;

				vis[g[i][j]] = 1;
			}
		}

		if(ok && vis.count()==3)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}