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
#define L 18

int n, q, a, b, c, curr;

VI G[N];

int p[L][N];
int d[N];
int pre[N];
int post[N];

void dfs(int v)
{
	pre[v] = ++curr;

	for(auto it:G[v])
	{
		p[0][it] = v;
		d[it] = d[v]+1;
		dfs(it);
	}

	post[v] = curr;
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

	int l = L-1;

	while(l>=0)
	{
		if(child(a, p[l][b]))
			--l;
		else
			b = p[l][b];
	}

	return p[0][b];
}

int dist(int a, int b)
{
	int l = lca(a, b);

	return d[a]+d[b]-2*d[l];
}

int abs(int a)
{
	return max(a, -a);
}

bool on_path(int a, int b, int l, int c)
{
	return (child(c, l) && (child(a, c) || child(b, c)));
}

int check(int a, int b, int c)
{
	int l = lca(a, b);

	if(lca(l, c)!=l)
		return max(dist(l, a), dist(l, b))+1;
	else
	{
		if(on_path(a, b, l, c))
			return max(dist(a, c), dist(b, c))+1;

		int s = L-1;

		while(s>=0)
		{
			if(on_path(a, b, l, p[s][c]) || child(l, p[s][c]))
				--s;
			else
				c = p[s][c];
		}

		return max(dist(a, p[0][c]), dist(b, p[0][c]))+1;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 2; i <= n; ++i)
	{
		cin >> a;
		G[a].pb(i);
	}

	p[0][1] = 1;
	dfs(1);

	for(int l = 1; l < L; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			p[l][i] = p[l-1][p[l-1][i]];
		}
	}

	while(q--)
	{
		int a, b, c, res = 0;

		cin >> a >> b >> c;

		res = max(res, check(a, b, c));
		res = max(res, check(c, b, a));
		res = max(res, check(a, c, b));

		cout << res << endl;
	}
}