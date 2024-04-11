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

const int N = 2e5+7;
const int M = 1<<18;

int n, q, c;

VI G[N];

int pre[N];
int post[N];

int sub[2*M];
int lazy[2*M];

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
	{
		dfs(it);
	}

	post[v] = c;
}

void push(int v, int l, int r)
{
	if(lazy[v])
	{
		lazy[2*v] ^= 1;
		lazy[2*v+1] ^= 1;
		sub[2*v+1] = (r-l+1)/2-sub[2*v+1];
		sub[2*v] = (r-l+1)/2-sub[2*v];
		lazy[v] = 0;
	}
}

void insert(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		lazy[v] ^= 1;
		sub[v] = (r-l+1)-sub[v];
		return;
	}

	push(v, l, r);
	insert(a, b, 2*v, l, (l+r)/2);
	insert(a, b, 2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
}

int query(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>r || l>b)
		return 0;

	if(a<=l && r<=b)
		return sub[v];

	push(v, l, r);
	int res = query(a, b, 2*v, l, (l+r)/2)+query(a, b, 2*v+1, (l+r)/2+1, r);
	sub[v] = sub[2*v]+sub[2*v+1];
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		G[p].pb(i);
	}

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		int t;
		cin >> t;

		if(t)
			insert(pre[i], pre[i]);
	}

	cin >> q;

	while(q--)
	{
		string t;
		int u;
		cin >> t >> u;

		if(t=="get")
			cout << query(pre[u], post[u]) << endl;
		else
			insert(pre[u], post[u]);
	}
}