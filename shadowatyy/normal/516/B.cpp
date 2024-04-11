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
#define SIZE(x) (int)(x).size()
using namespace std;

#define N 2007

int n, m, cnt, ile;

int deg[N][N];

char g[N][N];

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

queue<PII> Q;

char res[N][N];
bitset<N> del[N];
bitset<N> vis[N];

bool ins(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m;
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

			if(g[i][j]=='.')
				++ile;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				if(g[i][j]=='.' && g[i+Y[k]][j+X[k]]=='.' && ins(i+Y[k], j+X[k]))
					++deg[i][j];
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(g[i][j]=='.' && deg[i][j]==1)
			{
				Q.emplace(i, j);
				vis[i][j] = 1;
			}
				
		}
	}

	//int X[] = {1, -1, 0, 0};
	//int Y[] = {0, 0, 1, -1};

	while(!Q.empty())
	{
		int y = Q.front().st;
		int x = Q.front().nd;
		Q.pop();
	
		if(del[y][x])
		{
			for(int i = 0; i < 4; ++i)
			{
				if(g[y+Y[i]][x+X[i]]=='.' && ins(y+Y[i], x+X[i]) && --deg[y+Y[i]][x+X[i]]==1 && !vis[y+Y[i]][x+X[i]])
				{
					Q.emplace(y+Y[i], x+X[i]);
					vis[y+Y[i]][x+X[i]] = 1;
				}
			}
		}
		else
		{
			for(int i = 0; i < 4; ++i)
			{
				if(g[y+Y[i]][x+X[i]]=='.' && ins(y+Y[i], x+X[i]) && !del[y+Y[i]][x+X[i]])
				{
					del[y][x] = del[y+Y[i]][x+X[i]] = 1;
					cnt += 2;

					if(!vis[y+Y[i]][x+X[i]])
					{
						Q.emplace(y+Y[i], x+X[i]);
						vis[y+Y[i]][x+X[i]] = 1;
					}

					if(i==0)
					{
						res[y][x] = '<';
						res[y][x+1] = '>';
					}
					else if(i==1)
					{
						res[y][x-1] = '<';
						res[y][x] = '>';
					}
					else if(i==2)
					{
						res[y][x] = '^';
						res[y+1][x] = 'v';
					}
					else if(i==3)
					{
						res[y-1][x] = '^';
						res[y][x] = 'v';
					}
				}
			}
		}
	}

	if(cnt==ile)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(!res[i][j])
					cout << '*';
				else
					cout << res[i][j];
			}

			cout << endl;
		}
	}
	else
		cout << "Not unique";
}