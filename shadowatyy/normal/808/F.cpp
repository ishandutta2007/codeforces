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
using namespace std;

#define s 0
#define t (n+1)
#define N 107
#define A 200007

int n, k, sum, l, flow, max1;

int c[N];
int p[N];
VI L[N];

bitset<A> sieve;

VI G[N];
VI::iterator beg[N];
int cap[N][N];
int dist[N];
queue<int> Q;

bool bfs()
{
	for(int i = s; i <= t; ++i)
	{
		dist[i] = inf;
	}

	dist[s] = 0;
	Q.push(s);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(dist[it]>dist[v]+1 && cap[v][it])
			{
				dist[it] = dist[v]+1;
				Q.push(it);
			}
		}
	}

	return dist[t]!=inf;
}

int dfs(int v, int mc)
{
	if(!mc || v==t)
		return mc;

	int res = 0;

	for(auto &it = beg[v]; it!=G[v].end(); ++it)
	{
		if(cap[v][*it] && dist[v]+1==dist[*it])
		{
			int f = dfs(*it, min(cap[v][*it], mc));
			cap[v][*it] -= f;
			cap[*it][v] += f;
			res += f;
			mc -= f;

			if(!mc)
				break;
		}
	}

	return res;
}

void powieksz()
{
	for(int i = 1; i <= n; ++i)
	{
		if(c[i]==1 && i!=max1)
		{
			G[s].pb(i);
			G[i].pb(s);
			cap[s][i] = p[i];
		}
	}

	while(bfs())
	{
		for(int i = s; i <= t; ++i)
		{
			beg[i] = G[i].begin();
		}

		flow += dfs(s, inf); 
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i] >> c[i] >> l;
		L[l].pb(i);
	}

	for(int i = 2; i < A; ++i)
	{
		if(!sieve[i])
		{
			for(int j = 2*i; j < A; j += i)
			{
				sieve[j] = 1;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(c[i]%2==0 && c[j]%2==1 && !sieve[c[i]+c[j]])
			{
				G[i].pb(j);
				G[j].pb(i);
				cap[i][j] += inf;
			}
		}	
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:L[i])
		{
			sum += p[it];

			if(c[it]==1 && p[it]>p[max1])
				max1 = it;

			if(c[it]%2==0)
			{
				G[s].pb(it);
				G[it].pb(s);
				cap[s][it] += p[it];
			}
			else
			{
				G[it].pb(t);
				G[t].pb(it);
				cap[it][t] += p[it];
			}
		}

		powieksz();

		if(sum-flow>=k)
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;
}