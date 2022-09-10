#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

#define N 200007

int n, a, b, res;

VI G[N];

int ans[N];

void dfs(int v, int c)
{
	int curr = 0;

	for(auto it:G[v])
	{
		if(!ans[it])
		{
			ans[it] = ++curr;

			while(ans[it]==c || ans[it]==ans[v])
				ans[it] = ++curr;

			dfs(it, ans[v]);
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
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		res = max(res, (int)G[i].size()+1);
	}

	ans[1] = 1;

	dfs(1, 0);

	cout << res << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}

}