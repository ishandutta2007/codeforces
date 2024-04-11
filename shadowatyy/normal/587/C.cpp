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

const int N = 1e5+7;
const int M = (1<<17);
const int S = 19;

int n, m, q, c, curr = 1;

VI G[N];

VI ins[N];

int root[N];

int L[100*N];
int R[100*N];
int sum[100*N];

int pre[N];
int post[N];
int p[S][N];

int build(int v = 1, int l = 0, int r = M-1)
{
	if(l==r)
		return v;

	L[v] = ++curr;
	R[v] = ++curr;

	build(L[v], l, (l+r)/2);
	build(R[v], (l+r)/2+1, r);
	return v;
}

int insert(int a, int v, int l = 0, int r = M-1)
{
	int nv = ++curr;

	if(l==r)
	{
		sum[nv] = sum[v]+1;
		return nv;
	}

	L[nv] = L[v];
	R[nv] = R[v];

	if(a<=(l+r)/2)
		L[nv] = insert(a, L[nv], l, (l+r)/2);
	else
		R[nv] = insert(a, R[nv], (l+r)/2+1, r);

	sum[nv] = sum[L[nv]]+sum[R[nv]];
	return nv;
}

int kth(int r1, int r2, int r3, int r4, int k, int l = 0, int r = M-1)
{
	if(l==r)
		return l;

	if(sum[L[r1]]+sum[L[r2]]-sum[L[r3]]-sum[L[r4]]>=k)
		return kth(L[r1], L[r2], L[r3], L[r4], k, l, (l+r)/2);
	else
		return kth(R[r1], R[r2], R[r3], R[r4], k-(sum[L[r1]]+sum[L[r2]]-sum[L[r3]]-sum[L[r4]]), (l+r)/2+1, r);
}

void dfs(int v)
{
	pre[v] = ++c;

	for(auto it:ins[v])
		root[v] = insert(it, root[v]);

	for(auto it:G[v])
	{
		if(!pre[it])
		{
			root[it] = root[v];
			p[0][it] = v;
			dfs(it);
		}
	}

	post[v] = c;
}

bool child(int a, int b)
{
	return pre[a]>=pre[b] && post[a]<=post[b];
}

int lca(int a, int b)
{
	if(child(a, b))
		return b;

	if(child(b, a))
		return a;

	int l = S-1;

	while(l>=0)
	{
		if(child(a, p[l][b]))
			--l;
		else
			b = p[l][b];
	}

	return p[0][b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= m; ++i)
	{
		int c;
		cin >> c;
		ins[c].pb(i);
	}

	root[0] = build();
	root[1] = root[0];
	p[0][1] = 1;
	dfs(1);

	for(int l = 1; l < S; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			p[l][i] = p[l-1][p[l-1][i]];
		}
	}

	while(q--)
	{
		int v, u, a;
		cin >> v >> u >> a;

		int l = lca(v, u), pl;

		if(l==1)
			pl = 0;
		else
			pl = p[0][l];

		a = min(a, sum[root[v]]+sum[root[u]]-sum[root[l]]-sum[root[pl]]);

		cout << a << " ";

		for(int i = 1; i <= a; ++i)
			cout << kth(root[v], root[u], root[l], root[pl], i) << " ";

		cout << endl;
	}
}