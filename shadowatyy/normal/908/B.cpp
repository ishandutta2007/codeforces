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

const int N = 57;

int n, m, sy, sx, ty, tx;

char g[N][N];

int Y[] = {0, 0, 1, -1};
int X[] = {1, -1, 0, 0};

string s;

bool ins(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m && g[y][x]!='#';
}

VI p = {0, 1, 2, 3};

bool check()
{
	int y = sy, x = sx;

	for(int i = 0; i < s.size(); ++i)
	{
		y += Y[p[s[i]-'0']];
		x += X[p[s[i]-'0']];

		if(!ins(y, x))
			return 0;

		if(y==ty && x==tx)
			return 1;
	}

	return 0;
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
			else if(g[i][j]=='E')
			{
				ty = i;
				tx = j;
			}
		}
	}

	cin >> s;

	int res = 0;

	for(int i = 0; i < 24; ++i)
	{
		next_permutation(ALL(p));
		
		if(check())
			++res;
	}

	cout << res;
}