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
#define flush fflush(stdout)
using namespace std;

#define N 57

int n, m, x, a, b, c;

VPII E[N];
VI G[N];
int cap[N][N];
VI::iterator beg[N];
int dist[N];
queue<int> Q;

int dfs(int v = 1, int mc = inf)
{
	if(!mc || v==n)
		return mc;

	int res = 0;

	for(auto &it = beg[v]; it!=G[v].end(); ++it)
	{
		if(cap[v][*it]>0 && dist[v]+1==dist[*it])
		{
			int f = dfs(*it, min(mc, cap[v][*it]));
			cap[v][*it] -= f;
			cap[*it][v] += f;
			mc -= f;
			res += f;
		}
	}

	return res;
}

bool bfs()
{
	for(int i = 1; i <= n; ++i)
	{
		beg[i] = G[i].begin();
	}

	for(int i = 2; i <= n; ++i)
	{
		dist[i] = inf;
	}

	Q.push(1);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(cap[v][it]>0 && dist[it]==inf)
			{
				dist[it] = dist[v]+1;
				Q.push(it);
			}
		}
	}

	return dist[n]!=inf;
}

bool check(long double k)
{
	for(int i = 1; i <= n; ++i)
	{
		memset(cap[i], 0, sizeof cap[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:E[i])
		{
			cap[i][it.st] += floor(min((long double)x, it.nd/k));
		}
	}

	int flow = 0;

	while(bfs())
		flow += dfs();

	return flow>=x;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> x;

	while(m--)
	{
		cin >> a >> b >> c;
		E[a].eb(b, c);
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		sort(ALL(G[i]));
		G[i].erase(unique(ALL(G[i])), G[i].end());
	}

	long double l = 0, r = 1e9;

	for(int i = 1; i <= 100; ++i)
	{
		long double m = (l+r)/2;

		if(check(m))
			l = m;
		else
			r = m;
	}

	cout << fixed << setprecision(15) << x*l;
}