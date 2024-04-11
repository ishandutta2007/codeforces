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

const int N = 400007;
const int M = (1<<18);

int n, q, c;

VI G[N];

int a[N];
int b[N];
int w[N];
int root[N];
int pre[N];
int post[N];
int akt[N];

ll load[2*M];
ll sub[2*M];

void insert(int a, int b, int c, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return;

	if(a<=l && r<=b)
	{
		load[v] += c;
		sub[v] += c;
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = load[v]+min(sub[2*v], sub[2*v+1]);
}

ll query(int a, int b, int v = 1, int l = 0, int r = M-1)
{
	if(a>b || l>b || a>r)
		return INF;

	if(a<=l && r<=b)
		return sub[v];

	return load[v]+min(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
}

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:G[v])
		dfs(it);

	post[v] = c;
}

bool child(int a, int b)
{
	return pre[a]>=pre[b] && post[a]<=post[b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n-1; ++i)
	{
		cin >> a[i] >> b[i] >> w[i];
		G[a[i]].pb(b[i]);
	}

	for(int i = n; i <= 2*n-2; ++i)
	{
		cin >> a[i] >> b[i] >> w[i];
		akt[a[i]] = w[i];
	}

	dfs(1);

	for(int i = 1; i <= n-1; ++i)
	{
		insert(pre[b[i]], post[b[i]], w[i]);
	}

	for(int i = n; i <= 2*n-2; ++i)
	{
		insert(pre[a[i]], pre[a[i]], w[i]);
	}

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int i, c;
			cin >> i >> c;

			if(i<=n-1)
			{
				insert(pre[b[i]], post[b[i]], -w[i]);
				w[i] = c;
				insert(pre[b[i]], post[b[i]], w[i]);
			}
			else
			{
				insert(pre[a[i]], pre[a[i]], -w[i]);
				w[i] = c;
				akt[a[i]] = w[i];
				insert(pre[a[i]], pre[a[i]], w[i]);
			}
		}
		else
		{
			int u, v;
			cin >> u >> v;

			if(child(v, u))
				cout << (query(pre[v], pre[v])-akt[v])-(query(pre[u], pre[u])-akt[u]) << endl;
			else
				cout << query(pre[u], post[u])-query(pre[u], pre[u])+akt[u]+query(pre[v], pre[v])-akt[v] << endl;
		}
	}
}