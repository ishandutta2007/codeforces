#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 1e5+7;

int n, ans;

VI G[N];

bitset<N> vis;
int sub[N];

void dfs(int v)
{
	vis[v] = 1;
	sub[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);
			sub[v] ^= sub[it];
		}
	}

	if(!sub[v])
		++ans;
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	if(n%2)
	{
		cout << -1 << endl;
		return 0;
	}

	for(int i = 2; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	cout << ans-1 << endl;
}