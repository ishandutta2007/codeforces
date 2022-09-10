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

const int N = 5e5+7;
const int M = 1<<19;

int n, curr, q;

VI G[N];

int pos[N];
int sub_end[N];
int sub[N];
int top[N];
int p[N];

int lazy[2*M];

void shift(int v)
{
	if(lazy[v]!=-1)
	{
		lazy[2*v] = lazy[2*v+1] = lazy[v];
		lazy[v] = -1;
	}
}

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return;

	if(a<=l && r<=b)
	{
		lazy[v] = c;
		return;
	}

	shift(v);
	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
}

int query(int a, int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
		return lazy[v];
	
	shift(v);

	if(a<=(l+r)/2)
		return query(a, 2*v, l, (l+r)/2);
	else
		return query(a, 2*v+1, (l+r)/2+1, r);
}

void dfs(int v)
{
	sub[v] = 1;

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			p[it] = v;
			dfs(it);
			sub[v] += sub[it];
		}
	}
}

void hld(int v, int r)
{
	pos[v] = ++curr;
	top[v] = r;

	auto h = mp(-1, -1);

	for(auto it:G[v])
	{
		if(it!=p[v])
			h = max(h, mp(sub[it], it));
	}

	if(h.nd!=-1)
	{
		hld(h.nd, r);

		for(auto it:G[v])
		{
			if(it!=p[v] && it!=h.nd)
				hld(it, it);
		}
	}

	sub_end[v] = curr;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);
	hld(1, 1);

	cin >> q;

	while(q--)
	{
		int t, v;

		cin >> t >> v;

		if(t==1)
			insert(pos[v], sub_end[v], 1);
		else if(t==2)
		{
			while(v)
			{
				insert(pos[top[v]], pos[v], 0);
				v = p[top[v]];
			}
		}
		else if(t==3)
		{
			int q = query(pos[v]);

			if(q==0 || q==-1)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
	}
}