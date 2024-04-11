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

#define N 1000007

int n, q, a, b, t, x, g = inf, ans;

VI G[N];

int path[N];

void dfs(int v)
{
	for(auto it:G[v])
	{
		if(!path[it])
		{
			path[it] = min(path[v], it);
			dfs(it);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	cin >> t >> x;
	x = (x+ans)%n+1;

	path[x] = x;
	dfs(x);

	while(--q)
	{
		cin >> t >> x;
		x = (x+ans)%n+1;

		if(t==1)
			g = min(g, path[x]);
		else
			cout << (ans = min(g, path[x])) << endl;
	}
}