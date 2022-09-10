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

#define N 100007
#define M (1<<17)

int n, q, c, res;

VPII G[N];

ll far[N];
ll d[N];

int pre[N];
int post[N];

ll load[2*M];
ll sub[2*M];

int fen[N];

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b || a>b)
		return;

	if(a<=l && r<=b)
	{
		load[v] += c;
		sub[v] += c;
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = load[v]+max(sub[2*v], sub[2*v+1]);
}

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		if(!pre[it.st])
		{
			d[it.st] = d[v]+it.nd;
			dfs(it.st);
		}
	}

	post[v] = c;
}

void build()
{
	for(int i = 1; i <= n; ++i)
	{
		sub[pre[i]+M] = d[i];
	}

	for(int i = M-1; i >= 1; --i)
	{
		sub[i] = max(sub[2*i], sub[2*i+1]);
	}
}

void licz(int v)
{
	far[v] = sub[1];

	for(auto it:G[v])
	{
		if(pre[it.st]>pre[v])
		{	
			sub[1] += it.nd;
			load[1] += it.nd;
			insert(pre[it.st], post[it.st], -2*it.nd);
			licz(it.st);
			sub[1] -= it.nd;
			load[1] -= it.nd;
			insert(pre[it.st], post[it.st], 2*it.nd);
		}
	}
}

void prep(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		if(!pre[it.st])
			prep(it.st);
	}

	post[v] = c;
}

void add(int a)
{
	while(a<=n)
	{
		++fen[a];
		a += (a&-a);
	}
}

int que(int a)
{
	int res = 0;

	while(a>0)
	{
		res += fen[a];
		a -= (a&-a);
	}

	return res;
}

vector<pair<pair<ll, int>, int> > events;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int x, y, v;
		cin >> x >> y >> v;
		G[x].eb(y, v);
		G[y].eb(x, v);
	}

	dfs(1);
	build();
	licz(1);

	int root = 1;
	ll mn = far[1];

	for(int i = 2; i <= n; ++i)
	{
		if(mn>far[i])
		{
			root = i;
			mn = far[i];
		}
	}

	memset(pre, 0, sizeof pre);
	c = 0;
	prep(root);

	cin >> q;

	while(q--)
	{
		ll l;
		int res = 0;

		cin >> l;

		events.clear();
		memset(fen, 0, sizeof fen);

		for(int i = 1; i <= n; ++i)
		{
			events.eb(mp(far[i], 1), i);
			events.eb(mp(far[i]-l, 0), i);
		}

		sort(ALL(events));

		for(auto it:events)
		{
			if(it.st.nd==1)
				res = max(res, que(post[it.nd])-que(pre[it.nd]-1));
			else
				add(pre[it.nd]);
		}

		cout << res << endl;
	}


}