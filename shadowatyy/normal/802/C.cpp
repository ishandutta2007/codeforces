#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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

#define int long long
#define N 167
#define s 0
#define t 2*n+1

int n, k, flow, ans, res = INF;

int a[N];
int c[N];

VI G[N];

int cost[N][N];
int cap[N][N];

int dist[N];
queue<int> Q;
bitset<N> vis;
int p[N];

void powieksz()
{
	for(int i = s; i <= t; ++i)
	{
		dist[i] = inf;
	}

	dist[s] = 0;
	Q.push(s);
	vis[s] = 1;

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		vis[v] = 0;

		for(auto it:G[v])
		{
			if(cap[v][it]>0)
			{
				if(dist[v]+cost[v][it]<dist[it])
				{
					p[it] = v;
					dist[it] = dist[v]+cost[v][it];

					if(!vis[it])
					{
						Q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}

	ans += dist[t];

	int v = t;

	while(v)
	{
		cap[v][p[v]] += 1;
		cap[p[v]][v] -= 1;

		v = p[v];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		G[s].pb(2*i-1);
		G[2*i-1].pb(s);
		cap[s][2*i-1] = 1;
		cost[s][2*i-1] = c[a[i]];
		cost[2*i-1][s] = -cost[s][2*i-1];

		G[2*i-1].pb(2*i);
		G[2*i].pb(2*i-1);
		cap[2*i-1][2*i] = 1;
		cost[2*i-1][2*i] = -inf;
		cost[2*i][2*i-1] = -cost[2*i-1][2*i];

		G[2*i].pb(t);
		G[t].pb(2*i);
		cap[2*i][t] = 1;

		for(int j = i+1; j <= n; ++j)
		{
			G[2*i].pb(2*j-1);
			G[2*j-1].pb(2*i);
			cap[2*i][2*j-1] = 1;
			cost[2*i][2*j-1] = (a[i]==a[j]?0:c[a[j]]);
			cost[2*j-1][2*i] = -cost[2*i][2*j-1];
		}
	}

	for(int i = 1; i <= min(n, k); ++i)
	{
		powieksz();
		res = min(res, ans);
	}

	cout << res+n*inf;
}