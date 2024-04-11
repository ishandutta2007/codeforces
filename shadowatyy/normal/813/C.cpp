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

int n, x, a, b, ans;
VI G[N];

int dp[N];
int depth[N];
int p[N];

bitset<N> vis;

int dfs(int v)
{
	vis[v] = 1;

	int res = inf;

	if(v==x)
		res = 0;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			depth[it] = depth[v]+1;
			p[it] = v;

			res = min(res, dfs(it)+1);

			dp[v] = max(dp[v], dp[it]+1);
		}
	}

	if(depth[v]>res)
		ans = max(ans, depth[v]+dp[v]);

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	cout << 2*ans;
}