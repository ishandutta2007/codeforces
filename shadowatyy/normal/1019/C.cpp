#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1e6+7;

int n, m;

VI G[N];

int vis[N];
int ans[N];
int deg[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:G[i])
		{
			if(it>i)
				++deg[it];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			ans[i] = 1;

			for(auto it:G[i])
			{
				if(it>i)
				{
					vis[it] = 1;
				}
			}
		}
	}

	for(int i = n; i >= 1; --i)
	{
		for(auto it:G[i])
		{
			if(it<i && ans[it] && ans[i])
				ans[it] = 0;
		}
	}

	int ile = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i])
			++ile;
	}

	cout << ile << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i])
			cout << i << " ";
	}

	cout << endl;
}