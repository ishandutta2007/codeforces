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

#define N 1000007

ll n, m, a, b;

ll res, s, p;

VI G[N];

bitset<N> vis;
bitset<N> e;
	
void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
			dfs(it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a >> b;

		if(a!=b)
		{
			G[a].pb(b);
			G[b].pb(a);
		}
		else
			++p;

		e[a] = e[b] = 1;
	}

	int q = 1;

	while(!e[q])
		++q;

	dfs(q);

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i] && e[i])
		{
			cout << 0;
			return 0;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		s = G[i].size();

		res += s*(s-1)/2;
	}

	res += p*(p-1)/2;
	res += (m-p)*p;

	cout << res;
}