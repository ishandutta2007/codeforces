#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

#define N 100007

int n, m, x, a;

int r[N];

PII d[N];

VPII G[N];

bitset<N> vis;

bitset<N> res;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			if(it.nd)
				res[it.st] = res[v];
			else
				res[it.st] = !res[v];

			dfs(it.st);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> r[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> x;

		for(int j = 1; j <= x; ++j)
		{
			cin >> a;

			if(!d[a].st)
				d[a].st = i;
			else
				d[a].nd = i;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		G[d[i].st].eb(d[i].nd, r[i]);
		G[d[i].nd].eb(d[i].st, r[i]);
	}

	for(int i = 1; i <= m; ++i)
	{
		if(!vis[i])
			dfs(i);
	}
	
	for(int v = 1; v <= m; ++v)
	{
		for(auto it:G[v])
		{
			if(it.nd && res[v]!=res[it.st])
			{
				cout << "NO";
				return 0;
			}

			if(!it.nd && res[v]==res[it.st])
			{
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
}