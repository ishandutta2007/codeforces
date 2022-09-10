#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

#define int ll
const int N = 2e5+7;

int n, x, y, wz;

VI G[N];

int w[N];
int vis[N];

void dfs(int v)
{
	vis[v] = 1;
	int cnt = 0;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);

			if(w[it])
				++cnt;
		}
	}

	wz += min(cnt, 2ll);

	if(cnt<=1)
		w[v] = 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x >> y;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	if(x>y)
	{
		int e = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(G[i].size()==n-1)
				e = 1;
		}

		if(e)
			cout << (n-2) * y + x << endl;
		else
			cout << (n-1) * y << endl;
	}
	else
	{
		dfs(1);
		cout << wz * x + (n - 1 - wz) * y << endl;
	}
}