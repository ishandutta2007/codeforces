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

const int N = 5e4+7;
const int S = 3e5+7;

int n, m;

VI G[N];

int v[N];
int u[N];
int c[N];
int t[N];

VI val;

struct sat2
{
	VI imp[S];

	bitset<S> vis;
	bitset<S> res;

	VI post;

	int last[N];
	int ile[N];

	void dfs_rev(int v)
	{
		vis[v] = 1;

		for(auto it:imp[v^1])
		{
			if(!vis[it^1])
				dfs_rev(it^1);
		}

		post.pb(v);
	}

	void dfs_mark(int v)
	{
		vis[v] = 1;
		res[v] = !vis[v^1];

		for(auto it:imp[v])
		{
			if(!vis[it])
				dfs_mark(it);
		}
	}

	void add(int a, int b)
	{
		imp[a^1].pb(b);
		imp[b^1].pb(a);
	}

	bool solve(int k)
	{
		for(int i = 1; i <= m; ++i)
		{
			if(t[i]>k)
				add(2*i^1, 2*i^1);
		}

		int curr = m;

		for(int v = 1; v <= n; ++v)
		{
			for(auto it:G[v])
				last[c[it]] = ile[c[it]] = 0;

			for(auto it:G[v])
			{
				++ile[c[it]];

				if(ile[c[it]]==3)
					return 0;
			}

			for(auto it:G[v])
			{
				if(last[c[it]])
					add(2*it, 2*last[c[it]]);

				last[c[it]] = it;
			}

			for(int i = 0; i < G[v].size(); ++i)
			{
				int it = G[v][i];
				++curr;

				if(i>0)
				{
					add(2*(curr-1)^1, 2*it^1);
					add(2*(curr-1)^1, 2*curr);
				}

				add(2*it^1, 2*curr);
			}
		}

		for(int v = 2; v <= 2*curr+1; ++v)
		{
			if(!vis[v])
				dfs_rev(v);
		}

		reverse(ALL(post));
		vis.reset();

		for(auto v:post)
		{
			if(!vis[v])
				dfs_mark(v);
		}

		for(int v = 2; v <= 2*curr+1; ++v)
		{
			for(auto it:imp[v])
			{
				if(res[v] && !res[it])
					return 0;
			}
		}

		return 1;
	}

	void print()
	{
		int ile = 0;

		for(int i = 1; i <= m; ++i)
		{
			if(res[2*i])
				++ile;
		}

		cout << ile << endl;

		for(int i = 1; i <= m; ++i)
		{
			if(res[2*i])
				cout << i << " ";
		}
	}

	sat2(){}
};

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> v[i] >> u[i] >> c[i] >> t[i];
		G[v[i]].pb(i);
		G[u[i]].pb(i);
		val.pb(c[i]);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 1; i <= m; ++i)
	{
		c[i] = lower_bound(ALL(val), c[i])-val.begin()+1;
	}

	int l = 0, r = 1e9;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--m;

		sat2 sat;
		
		if(sat.solve(m))
			r = m;
		else
			l = m+1;
	}

	sat2 sat;

	if(sat.solve(l))
	{
		cout << "Yes" << endl << l << " ";
		sat.print();
	}
	else
		cout << "No";

}