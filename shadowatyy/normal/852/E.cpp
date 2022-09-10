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
#define SIZE(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+7;

int n;

ll res;

VI G[N];

ll dp[N];
ll nad[N];
ll syn[N];

bitset<N> vis;

ll fpow(ll a, ll b)
{
	if(b==0)
		return 1;
	else if(b%2)
		return a*fpow(a, b-1)%MOD;
	else
	{
		ll q = fpow(a, b/2);
		return q*q%MOD;
	}
}

void dfs1(int v)
{
	vis[v] = 1;
	syn[v] = 1;

	if(v!=1 && G[v].size()==1)
	{
		dp[v] = 1;
		return;
	}

	ll ile = 2;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs1(it);
			ile = ile*dp[it]%MOD;
			syn[v] = syn[v]*dp[it]%MOD;
		}
	}

	dp[v] = ile%MOD;
}

void dfs2(int v)
{
	vis[v] = 1;
	ll curr = 2;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			curr = curr*dp[it]%MOD;

			if(v==1 && G[v].size()==1)
				nad[it] = nad[v]*syn[v]%MOD*fpow(dp[it], MOD-2)%MOD;
			else
				nad[it] = 2*nad[v]*syn[v]%MOD*fpow(dp[it], MOD-2)%MOD;

			dfs2(it);
		}
	}

	curr = curr*nad[v]%MOD;
	res += curr;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs1(1);
	vis.reset();
	nad[1] = 1;
	dfs2(1);

	cout << res%MOD;
}