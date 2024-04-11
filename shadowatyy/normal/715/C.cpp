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

#define N 100007

int n, M, a, b, c;

ll res;

VPII G[N];

ll inv[N];
ll pot[N];
int sub[N];
int max_sub[N];
int depth[N];

VI curr, comp;

bitset<N> del;
bitset<N> vis;

map<int, int> paths;

ll fpow(ll a, ll b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%M;

	if(b%2)
		return (a*fpow(a, b-1))%M;
	else
	{
		ll q = fpow(a, b/2);
		return (q*q)%M;
	}
}

void dfs1(int v)
{
	curr.pb(v);
	vis[v] = 1;
	sub[v] = 1;
	max_sub[v] = 0;

	for(auto it:G[v])
	{
		if(!del[it.st] && !vis[it.st])
		{
			dfs1(it.st);
			sub[v] += sub[it.st];
			max_sub[v] = max(max_sub[v], sub[it.st]);
		}
	}

	vis[v] = 0;
}

void dfs2(int v, ll up, ll down)
{
	comp.pb(down);
	vis[v] = 1;
	res += paths[(-up*inv[depth[v]]%M+M)%M];

	for(auto it:G[v])
	{
		if(!del[it.st] && !vis[it.st])
		{
			depth[it.st] = depth[v]+1;
			dfs2(it.st, (up*10+it.nd)%M, (down+it.nd*pot[depth[v]])%M);
		}
	}

	vis[v] = 0;
}

void solve(int s)
{	
	curr.clear();
	dfs1(s);

	for(auto &v:curr)
	{
		max_sub[v] = max(max_sub[v], (int)curr.size()-sub[v]);

		if(max_sub[curr[0]]>max_sub[v])
			swap(curr[0], v);
	}

	int centro = curr[0];
	del[centro] = 1;

	paths.clear();
	++paths[0];

	for(auto v:G[centro])
	{
		if(!del[v.st])
		{
			comp.clear();
			depth[v.st] = 1;
			dfs2(v.st, v.nd%M, v.nd%M);

			for(auto it:comp)
				++paths[it];
		}
	}

	reverse(ALL(G[centro]));

	paths.clear();

	for(auto v:G[centro])
	{
		if(!del[v.st])
		{
			comp.clear();
			depth[v.st] = 1;
			dfs2(v.st, v.nd%M, v.nd%M);

			for(auto it:comp)
				++paths[it];
		}
	}

	res += paths[0];

	for(auto it:G[centro])
	{
		if(!del[it.st])
			solve(it.st);
	}
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> M;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	int curr = M, phi = M;

	for(int i = 2; i*i <= M; ++i)
	{
		if(curr%i==0)
		{
			curr /= i;
			phi -= phi/i;

			while(curr%i==0)
				curr /= i;
		}
	}

	if(curr>1)
		phi -= phi/curr;

	inv[1] = fpow(10, phi-1);
	pot[1] = 10%M;

	for(int i = 2; i <= n; ++i)
	{
		inv[i] = (inv[i-1]*inv[1])%M;
		pot[i] = (pot[i-1]*pot[1])%M;
	}

	solve(1);

	cout << res;
}