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

#define N 2007
#define M 100007

bitset<N> used[N];

int a, b, m, d;

int x[M];
int y[M];

int col[N][N];
int sec[N][N];

VI G[N];

void dfs(int v, int teraz, int chce)
{
	int u = sec[v][teraz];

	used[v][teraz] = used[u][teraz] = 0;
	col[v][u] = col[u][v] = 0;

	if(used[u][chce])
		dfs(u, chce, teraz);

	col[v][u] = col[u][v] = chce;
	used[v][chce] = used[u][chce] = 1;
	sec[v][chce] = u;
	sec[u][chce] = v;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> x[i] >> y[i];
		y[i] += a;
		G[x[i]].pb(y[i]);
		G[y[i]].pb(x[i]);
		d = max(d, (int)G[x[i]].size());
		d = max(d, (int)G[y[i]].size());
	}

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= d; ++j)
		{
			if(!used[x[i]][j] && !used[y[i]][j])
			{
				col[x[i]][y[i]] = col[y[i]][x[i]] = j;
				used[x[i]][j] = used[y[i]][j] = 1;
				sec[x[i]][j] = y[i];
				sec[y[i]][j] = x[i];
				break;
			}
		}

		if(!col[x[i]][y[i]])
		{
			int cx = -1, cy = -1;

			for(int j = 1; j <= d; ++j)
			{
				if(used[x[i]][j] && !used[y[i]][j])
					cx = j;
				else if(!used[x[i]][j] && used[y[i]][j])
					cy = j;
			}

			dfs(x[i], cx, cy);
			col[x[i]][y[i]] = col[y[i]][x[i]] = cx;
			used[x[i]][cx] = used[y[i]][cx] = 1;
			sec[x[i]][cx] = y[i];
			sec[y[i]][cx] = x[i];
		}
	}

	cout << d << endl;

	for(int i = 1; i <= m; ++i)
	{
		cout << col[x[i]][y[i]] << " ";
	}
}