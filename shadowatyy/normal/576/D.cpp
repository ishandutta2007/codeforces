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

#define N 157

int n, m, curr, res = inf+2137;

VI G[N];

bitset<N> ok, bef;

int dist[N];
queue<int> Q;

vector<pair<int, PII> > e;

struct mat
{
	bitset<N> m[N];
};

mat M;

mat operator*(mat &a, mat &b)
{
	mat c, rb;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			rb.m[i][j] = b.m[j][i];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			c.m[i][j] = (a.m[i]&rb.m[j]).any();
		}
	}

	return c;
}

mat pot(mat a, int w)
{
	mat res;

	for(int i = 1; i <= n; ++i)
	{
		res.m[i][i] = 1;
	}

	for(int i = 0; i < 30; ++i)
	{	
		if(w&(1<<i))
			res = res*a;

		a = a*a;
	}

	return res;
}

void bfs()
{	
	for(int i = 1; i <= n; ++i)
	{
		if(ok[i])
		{
			Q.push(i);
			dist[i] = 0;
		}
		else
			dist[i] = inf+2137;
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(dist[v]+1<dist[it])
			{
				dist[it] = dist[v]+1;
				Q.push(it);
			}
		}
	}

	res = min(res, curr+dist[n]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a, b, d;
		cin >> a >> b >> d;
		e.eb(d, mp(a, b));
	}

	ok[1] = 1;

	sort(ALL(e));

	for(auto it:e)
	{
		bef = ok;
		ok.reset();
		mat p = pot(M, it.st-curr);

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(p.m[i][j] && bef[i])
					ok[j] = 1;
			}
		}

		M.m[it.nd.st][it.nd.nd] = 1;
		G[it.nd.st].pb(it.nd.nd);
		curr = it.st;
		bfs();
	}

	if(res==inf+2137)
		cout << "Impossible";
	else
		cout << res;
}