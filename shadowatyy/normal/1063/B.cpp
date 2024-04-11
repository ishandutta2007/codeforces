#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 2007;

int n, m, r, c, x, y, ans;

char g[N][N];

int dist[N][N];

deque<PII> Q;

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool ins(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m && g[y][x]=='.';
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> r >> c >> x >> y;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> g[i][j];
			dist[i][j] = inf;
		}
	}

	dist[r][c] = 0;
	Q.eb(r, c);

	while(!Q.empty())
	{
		int y = Q.front().st;
		int x = Q.front().nd;
		Q.pop_front();

		for(int i = 0; i < 3; ++i)
		{
			if(ins(y+Y[i], x+X[i]) && dist[y+Y[i]][x+X[i]]>dist[y][x])
			{
				dist[y+Y[i]][x+X[i]] = dist[y][x];
				Q.emplace_front(y+Y[i], x+X[i]);
			}
		}

		for(int i = 3; i < 4; ++i)
		{
			if(ins(y+Y[i], x+X[i]) && dist[y+Y[i]][x+X[i]]>dist[y][x]+1)
			{
				dist[y+Y[i]][x+X[i]] = dist[y][x]+1;
				Q.eb(y+Y[i], x+X[i]);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{	
			int C = c-j;
			int lewo = dist[i][j];
			int prawo = lewo-C;

			if(lewo<=x && prawo<=y)
				++ans;
		}
	}

	cout << ans << endl;
}