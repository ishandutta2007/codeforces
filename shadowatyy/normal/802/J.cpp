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

#define N 107
#define int long long

int n, u, v, c, res;

VPII G[N];
int d[N];
bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			d[it.st] = d[v]+it.nd;
			dfs(it.st);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		cin >> u >> v >> c;
		G[u].eb(v, c);
		G[v].eb(u, c);
	}

	dfs(0);

	for(int i = 0; i < n; ++i)
	{
		res = max(res, d[i]);
	}

	cout << res;
}