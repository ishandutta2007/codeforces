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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 100007

int n, a, b;

VI G[N];

VI s;

bitset<N> del;
bitset<N> vis;

int sub[N];
int max_sub[N];

char ans[N];

void dfs(int v)
{
	s.pb(v);
	vis[v] = sub[v] = 1;
	max_sub[v] = 0;

	for(auto it:G[v])
	{
		if(!del[it] && !vis[it])
		{
			dfs(it);
			max_sub[v] = max(max_sub[v], sub[it]);
			sub[v] += sub[it];
		}
	}
}	

void decompo(int v, int d)
{
	s.clear();

	dfs(v);

	for(auto it:s)
	{
		max_sub[it] = max(max_sub[it], (int)s.size()-sub[it]);
	}

	int centro = v;

	for(auto it:s)
	{
		if(max_sub[it]<max_sub[centro])
			centro = it;

		vis[it] = 0;
	}

	ans[centro] = 'A'+d;

	del[centro] = 1;

	for(auto it:G[centro])
	{
		if(!del[it])
			decompo(it, d+1);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	decompo(1, 0);

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
}