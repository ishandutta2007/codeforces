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
using namespace std;

#define y1 abacabadabacaba
const int N = 1007;

int n, m, k, y1, x1, y2, x2;

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int dist[N][N][4];
int ile[N][N][4];

deque<pair<PII, int> > Q;

bitset<N> g[N];

bool ins(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m && g[y][x];
}

void bfs(int y, int x, int s)
{
	Q.pop_front();

	if(ile[y][x][s])
	{
		if(ins(y+Y[s], x+X[s]) && (dist[y+Y[s]][x+X[s]][s]>dist[y][x][s] || (dist[y+Y[s]][x+X[s]][s]==dist[y][x][s] && ile[y+Y[s]][x+X[s]][s]<ile[y][x][s]-1)))
		{
			dist[y+Y[s]][x+X[s]][s] = dist[y][x][s];
			ile[y+Y[s]][x+X[s]][s] = ile[y][x][s]-1;
			Q.emplace_front(mp(y+Y[s], x+X[s]), s);
		}
	}

	for(int i = 0; i < 4; ++i)
	{
		if(ins(y+Y[i], x+X[i]) && (dist[y+Y[i]][x+X[i]][i]>dist[y][x][s]+1 || (dist[y+Y[i]][x+X[i]][i]==dist[y][x][s]+1 && ile[y+Y[i]][x+X[i]][i]<k-1)))
		{
			dist[y+Y[i]][x+X[i]][i] = dist[y][x][s]+1;
			ile[y+Y[i]][x+X[i]][i] = k-1;
			Q.eb(mp(y+Y[i], x+X[i]), i);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			char c;
			cin >> c;

			if(c=='.')
				g[i][j] = 1;

			for(int l = 0; l < 4; ++l)
			{
				dist[i][j][l] = inf;
			}
		}
	}

	cin >> y1 >> x1 >> y2 >> x2;

	for(int i = 0; i < 4; ++i)
	{
		dist[y1][x1][i] = 0;
		Q.eb(mp(y1, x1), i);
	}

	while(!Q.empty())
	{
		bfs(Q.front().st.st, Q.front().st.nd, Q.front().nd);
	}

	int res = inf;

	for(int i = 0; i < 4; ++i)
	{
		res = min(res, dist[y2][x2][i]);
	}

	if(res==inf)
		cout << -1;
	else
		cout << res;
}