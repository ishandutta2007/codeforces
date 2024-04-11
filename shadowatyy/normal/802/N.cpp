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

#define N 2207
#define int long long
#define s 0
#define t (n+1)

int n, k, ans;

int a[N];
int b[N];

VI G[N];

int cost[N][N];
int cap[N][N];

queue<int> Q;
int dist[N];
bitset<N> vis;
int p[N];

void powieksz()
{
	for(int i = s; i <= t; ++i)
	{
		dist[i] = INF;
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
		cin >> b[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		G[s].pb(i);
		G[i].pb(s);
		cap[s][i] = 1;
		cost[s][i] = a[i];

		G[i].pb(t);
		G[t].pb(i);
		cap[i][t] = 1;
		cost[i][t] = b[i];
	}

	for(int i = 1; i < n; ++i)
	{
		G[i].pb(i+1);
		G[i+1].pb(i);
		cap[i][i+1] = k;
		cost[i][i+1] = 0;
	}

	while(k--)
		powieksz();

	cout << ans;
}