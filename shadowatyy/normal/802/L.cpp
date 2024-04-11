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
#define N 100007
#define M inf

int n, u, v, c;

VI G[N];

int wolny[N];
int wspol[N];
int ojciec[N];
int deg[N];
bitset<N> vis;

int fpow(int a, int w)
{
	int res = 1;

	for(int i = 0; i < 31; ++i)
	{
		if(w&(1<<i))
			res = (res*a)%M;

		a = (a*a)%M;
	}

	return res;
}

int inv(int a)
{
	return fpow(a, M-2);
}

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			ojciec[it] = v;
			dfs(it);
		}
	}
}	

queue<int> Q;

void elim(int v)
{
	int ile = (inv(wspol[v])*inv(G[ojciec[v]].size()))%M;

	wolny[ojciec[v]] = (wolny[ojciec[v]]+ile*wolny[v])%M;
	
	if(G[v].size()>1)
		wspol[ojciec[v]] = (wspol[ojciec[v]]+ile*( ( M-inv(G[v].size()) )%M ) )%M;

	if(--deg[ojciec[v]]==1 && ojciec[v])
		Q.push(ojciec[v]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		cin >> u >> v >> c;
		G[v].pb(u);
		G[u].pb(v);
		wolny[u] += c;
		wolny[v] += c;
	}

	dfs(0);

	for(int i = 0; i < n; ++i)
	{
		if(G[i].size()==1)
		{
			wspol[i] = 1;
			wolny[i] = 0;
			Q.push(i);
		}
		else
		{
			wspol[i] = 1;
			wolny[i] = (wolny[i]*inv(G[i].size()))%M;
		}

		deg[i] = G[i].size();
	}

	while(!Q.empty())
	{
		elim(Q.front());
		Q.pop();
	}

	cout << (wolny[0]*inv(wspol[0]))%M;
}