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

int n, m, k, s;

VI G[N];

int a[N];

int dist[107][N];

VI takie[107];

queue<int> Q;

ll ans[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k >> s;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		takie[a[i]].pb(i);
	}

	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			dist[i][j] = inf;
		}

		for(auto it:takie[i])
		{
			dist[i][it] = 0;
			Q.push(it);
		}

		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();

			for(auto it:G[v])
			{
				if(dist[i][it]>dist[i][v]+1)
				{
					dist[i][it] = dist[i][v]+1;
					Q.push(it);
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		VI v;

		for(int j = 1; j <= k; ++j)
		{
			v.pb(dist[j][i]);
		}

		sort(ALL(v));

		for(int j = 0; j < s; ++j)
		{
			ans[i] += v[j];
		}

		cout << ans[i] << " ";
	}

	cout << endl;
}