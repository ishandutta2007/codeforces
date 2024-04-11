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
using namespace std;

const int N = 1e5+7;
const int M = 1<<17;

int n, r, c, m, last;

int a[N];

VI G[N];

int d[N];
int pre[N];
int post[N];

struct pm
{
	VI depth, val;

	int ask(int d)
	{
		auto it = upper_bound(ALL(depth), d);

		if(it==depth.begin())
			return inf;

		return val[it-depth.begin()-1];
	}

	void merge(pm &x)
	{
		VI ndepth, nval;

		int i = 0, j = 0;

		while(i<depth.size() || j<x.depth.size())
		{
			if(i==depth.size())
			{
				ndepth.pb(x.depth[j]);
				nval.pb(x.val[j++]);
			}
			else if(j==x.depth.size())
			{
				ndepth.pb(depth[i]);
				nval.pb(val[i++]);
			}
			else if(depth[i]==x.depth[j])
			{
				ndepth.pb(depth[i]);
				nval.pb(min(val[i++], x.val[j++]));
			}
			else if(depth[i]<x.depth[j])
			{
				ndepth.pb(depth[i]);
				nval.pb(val[i++]);
			}
			else if(x.depth[j]<depth[i])
			{
				ndepth.pb(x.depth[j]);
				nval.pb(x.val[j++]);
			}
		}

		depth = ndepth;
		val = nval;

		for(int i = 1; i < val.size(); ++i)
		{
			val[i] = min(val[i], val[i-1]);
		}
	}
};

pm tree[2*M];

int query(int a, int b, int d, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return inf;

	if(a<=l && r<=b)
		return tree[v].ask(d);

	return min(query(a, b, d, 2*v, l, (l+r)/2), query(a, b, d, 2*v+1, (l+r)/2+1, r));
}

/*int query(int a, int b, int d)
{
	a += M;
	b += M;

	int res = min(tree[a].ask(d), tree[b].ask(d));

	while(a<b-1)
	{
		if(a%2==0)
			res = min(res, tree[a+1].ask(d));

		if(b%2==1)
			res = min(res, tree[b-1].ask(d));

		a /= 2;
		b /= 2;
	}

	return res;
}*/

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		if(!pre[it])
		{
			d[it] = d[v]+1;
			dfs(it);
		}
	}

	post[v] = c;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> r;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		G[x].pb(y);
		G[y].pb(x);
	}

	dfs(r);

	for(int i = 1; i <= n; ++i)
	{
		tree[pre[i]+M].val.pb(a[i]);
		tree[pre[i]+M].depth.pb(d[i]);
	}

	for(int i = M-1; i >= 1; --i)
	{
		tree[i] = tree[2*i];
		tree[i].merge(tree[2*i+1]);
	}

	cin >> m;

	while(m--)
	{
		int p, q, x, k;
		cin >> p >> q;
		x = (p+last)%n+1;
		k = (q+last)%n;
		cout << (last = query(pre[x], post[x], d[x]+k)) << endl;
	}
}