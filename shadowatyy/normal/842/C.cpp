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

const int N = 2e5+7;

int n;

set<int> S[N];

int all[N];
int a[N];
int res[N];

VI G[N];

bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;
	res[v] = all[v];

	for(auto it:S[v])
	{
		res[v] = max(res[v], it);
	}

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			all[it] = __gcd(all[v], a[it]);

			for(auto g:S[v])
			{
				S[it].insert(__gcd(g, a[it]));
			}

			S[it].insert(all[v]);

			if(v==1)
				S[it].insert(a[it]);

			dfs(it);
		}
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

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	all[1] = a[1];
	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}