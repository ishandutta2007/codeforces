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

#define N 200007
#define M 1000000007

int n, x, y;

ll res;

int a[N];
int phi[N];
VI divs[N];
VI G[N];
bitset<N> del;
bitset<N> vis;
int sub[N];
int max_sub[N];
int inv[N];
int depth[N];
ll sum_phi[N];
ll sum[N];

VI curr, comp;

ll fpow(ll a, ll b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%M;

	if(b%2)
		return (a%M*fpow(a, b-1))%M;
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
	max_sub[v] = 0;
	sub[v] = 1;

	for(auto it:G[v])
	{
		if(!del[it] && !vis[it])
		{
			dfs1(it);
			sub[v] += sub[it];
			max_sub[v] = max(max_sub[v], sub[it]);
		}
	}
}

void dfs2(int v)
{
	comp.pb(v);
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!del[it] && !vis[it])
		{
			depth[it] = depth[v]+1;
			dfs2(it);
		}
	}
}

void solve(int s)
{
	curr.clear();
	dfs1(s);

	for(auto v:curr)
	{
		max_sub[v] = max(max_sub[v], (int)curr.size()-sub[v]);
	}

	for(auto &v:curr)
	{
		if(max_sub[v]<max_sub[curr[0]])
			swap(v, curr[0]);
	}

	for(auto v:curr)
	{
		for(auto d:divs[v])
			sum_phi[d] += phi[v];

		vis[v] = 0;
	}

	vis[curr[0]] = 1;

	for(auto v:G[curr[0]])
	{
		if(!del[v])
		{
			comp.clear();
			depth[v] = 1;
			dfs2(v);
			
			for(auto it:comp)
			{
				for(auto d:divs[it])
					sum_phi[d] -= phi[it];
			}

			for(auto it:comp)
			{
				for(int i = divs[it].size()-1; i >= 0; --i)
				{
					int d = divs[it][i];

					sum[d] += sum_phi[d];
					res += 2ll*phi[it]%M*depth[it]%M*d%M*inv[phi[d]]%M*sum[d]%M;
					res %= M;

					for(auto x:divs[d])
						sum[x] -= sum[d];
				}

				for(auto d:divs[it])
					sum[d] = 0;
			}

			for(auto it:comp)
			{
				for(auto d:divs[it])
					sum_phi[d] += phi[it];
			}
		}
	}

	for(auto v:curr)
	{
		for(auto d:divs[v])
			sum_phi[d] -= phi[v];

		vis[v] = 0;
	}

	del[curr[0]] = 1;

	for(auto v:G[curr[0]])
	{
		if(!del[v])
			solve(v);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		inv[i] = fpow(i, M-2);
	}

	for(int i = 1; i <= n; ++i)
	{
		phi[i] = i;
	}

	for(int i = 2; i <= n; ++i)
	{
		if(phi[i]==i)
		{
			for(int j = i; j <= n; j += i)
			{
				phi[j] -= phi[j]/i;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			divs[j].pb(i);
		}
	}

	for(int i = 1; i < n; ++i)
	{
		cin >> x >> y;
		G[a[x]].pb(a[y]);
		G[a[y]].pb(a[x]);
	}

	solve(1);

	cout << (res*fpow((ll)n*(n-1), M-2))%M;
}