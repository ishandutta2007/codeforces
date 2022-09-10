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

#define N 100007
#define int long long

int n, u, v, c, k;

VPII G[N];

bitset<N> vis;

int dp[N];
int stay[N];

bool comp(PII a, PII b)
{
	return dp[a.st]+a.nd>dp[b.st]+b.nd;
}

void dfs(int v)
{
	vis[v] = 1;
	VPII s;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			dfs(it.st);
			s.pb(it);
		}
	}

	sort(ALL(s), comp);

	if(s.size()>=k)
	{
		int sum = 0;

		for(int i = 0; i < k-1; ++i)
		{
			sum += dp[s[i].st]+s[i].nd;
		}

		dp[v] = stay[v] = sum;

		for(int i = 0; i < k-1; ++i)
		{
			stay[v] = max(stay[v], sum-dp[s[i].st]+stay[s[i].st]+dp[s[k-1].st]+s[k-1].nd);
		}

		for(int i = k-1; i < s.size(); ++i)
		{
			stay[v] = max(stay[v], sum+stay[s[i].st]+s[i].nd);
		}
	}
	else
	{
		int sum = 0;

		for(int i = 0; i < s.size(); ++i)
		{
			sum += dp[s[i].st]+s[i].nd;
		}

		dp[v] = stay[v] = sum;

		for(int i = 0; i < s.size(); ++i)
		{
			stay[v] = max(stay[v], sum-dp[s[i].st]+stay[s[i].st]);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i < n; ++i)
	{
		cin >> u >> v >> c;
		G[u].eb(v, c);
		G[v].eb(u, c);
	}

	dfs(0);

	cout << stay[0];
}