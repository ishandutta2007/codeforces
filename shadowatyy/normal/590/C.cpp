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

#define N 1007

int n, m, curr;

char g[N][N];

int X[] = {0, 0, 1, -1};
int Y[] = {-1, 1, 0, 0};

int dist[4][N][N];

deque<PII> Q;

bitset<3> con[3];

bool ins(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m;
}

void bfs(int y, int x)
{
	Q.pop_front();

	for(int i = 0; i < 4; ++i)
	{
		if(ins(y+Y[i], x+X[i]) && dist[curr][y+Y[i]][x+X[i]]==inf && g[y+Y[i]][x+X[i]]!='#')
		{
			if(g[y+Y[i]][x+X[i]]=='.')
			{
				dist[curr][y+Y[i]][x+X[i]] = dist[curr][y][x]+1;
				Q.emplace_back(y+Y[i], x+X[i]);
			}
			else
			{
				dist[curr][y+Y[i]][x+X[i]] = dist[curr][y][x];
				Q.emplace_front(y+Y[i], x+X[i]);
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
		}
	}

	for(int c = 1; c <= 3; ++c)
	{
		curr = c;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(g[i][j]=='0'+c)
				{
					dist[curr][i][j] = 0;
					Q.emplace_back(i, j);
				}
				else
					dist[curr][i][j] = inf;
			}
		}

		while(!Q.empty())
			bfs(Q.front().st, Q.front().nd);

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{	
				if(g[i][j]=='1' && !dist[curr][i][j])
					con[curr][1] = con[1][curr] = 1;

				if(g[i][j]=='2' && !dist[curr][i][j])
					con[curr][2] = con[2][curr] = 1;

				if(g[i][j]=='3' && !dist[curr][i][j])
					con[curr][3] = con[3][curr] = 1;
			}
		}
	}

	ll res = inf;

	if((con[1][2] && con[2][3]) || (con[2][1] && con[2][3]) || (con[3][1] && con[3][2]))
		res = 0;
	else if(con[1][2] || con[1][3] || con[2][3])
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(g[i][j]!='.')
					res = min(res, (ll)dist[1][i][j]+dist[2][i][j]+dist[3][i][j]);
			}
		}
	}
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(g[i][j]=='.')
					res = min(res, (ll)dist[1][i][j]+dist[2][i][j]+dist[3][i][j]-2);
				else
					res = min(res, (ll)dist[1][i][j]+dist[2][i][j]+dist[3][i][j]);
			}
		}
	}

	if(res==inf)
		cout << -1;
	else
		cout << res;
}