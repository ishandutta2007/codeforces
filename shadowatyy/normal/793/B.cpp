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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
using namespace std;

#define int long long
#define double long double

#define N 1007

int n, m, sy, sx, ty, tx;

char g[N][N];

int dist[4][N][N];

deque<pair<int, PII> > Q;

int Y[] = {-1, 0, 1, 0};
int X[] = {0, 1, 0, -1};

bool out(int y, int x)
{
	return y>n || y<1 || x>m || x<1;
}

void bfs(int s, int y, int x)
{
	Q.pop_front();

	for(int i = 0; i < 4; ++i)
	{
		if(out(y+Y[i], x+X[i]) || g[y+Y[i]][x+X[i]]=='*')
			continue;

		if(i==s)
		{
			if(dist[i][y+Y[i]][x+X[i]]>dist[s][y][x])
			{
				dist[i][y+Y[i]][x+X[i]] = dist[s][y][x];
				Q.emplace_front(i, mp(y+Y[i], x+X[i]));
			}
		}
		else
		{
			if(dist[i][y+Y[i]][x+X[i]]>dist[s][y][x]+1)
			{
				dist[i][y+Y[i]][x+X[i]] = dist[s][y][x]+1;
				Q.emplace_back(i, mp(y+Y[i], x+X[i]));
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> g[i][j];

			if(g[i][j]=='S')
			{
				sy = i;
				sx = j;
			}
			else if(g[i][j]=='T')
			{
				ty = i;
				tx = j;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				dist[k][i][j] = inf;
			}
		}
	}

	dist[0][sy][sx] = dist[1][sy][sx] = dist[2][sy][sx] = dist[3][sy][sx] = 0;

	Q.eb(0, mp(sy, sx));
	Q.eb(1, mp(sy, sx));
	Q.eb(2, mp(sy, sx));
	Q.eb(3, mp(sy, sx));

	while(!Q.empty())
	{
		bfs(Q.front().st, Q.front().nd.st, Q.front().nd.nd);
	}

	for(int k = 0; k < 4; ++k)
	{
		if(dist[k][ty][tx]<=2)
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}