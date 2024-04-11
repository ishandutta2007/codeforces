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

const int N = 2e5+7;

int n, m, c;

VI G[N];

int pre[N];
int p[N];

VI powr[N];

VI curr;

vector<VI> res;

bitset<N> used;

void dfs1(int v)
{
	pre[v] = ++c;
	curr.pb(v);

	for(auto it:G[v])
	{
		if(!pre[it])
		{
			p[it] = v;
			dfs1(it);
		}
		else if(it!=p[v] && pre[it]<pre[v])
			powr[v].pb(it);
	}
}

void dfs2(int v)
{
	VI unused;

	for(auto it:G[v])
	{
		if(v==p[it])
		{
			dfs2(it);

			if(!used[it])
				unused.pb(it);
		}
	}

	while(unused.size()>=2)
	{
		res.pb({unused.back(), v, unused[unused.size()-2]});
		unused.pop_back();
		unused.pop_back();
	}

	if(!unused.empty() && !powr[v].empty())
	{
		res.pb({unused[0], v, powr[v][0]});
	}
	else if(unused.empty() && !powr[v].empty())
	{	
		if(p[v])
		{
			res.pb({powr[v][0], v, p[v]});
			used[v] = 1;
		}	
	}
	else if(!unused.empty() && powr[v].empty())
	{
		if(p[v])
		{
			res.pb({unused[0], v, p[v]});
			used[v] = 1;
		}	
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!pre[i])
		{
			curr.clear();
			dfs1(i);

			for(auto it:curr)
			{
				while(powr[it].size()>=2)
				{
					res.pb({powr[it].back(), it, powr[it][powr[it].size()-2]});
					powr[it].pop_back();
					powr[it].pop_back();
				}
			}

			dfs2(i);
		}
	}

	cout << res.size() << endl;

	for(auto it:res)
	{
		cout << it[0] << " " << it[1] << " " << it[2] << endl;
	}
}