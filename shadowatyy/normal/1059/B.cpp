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

const int N = 1007;

int n, m;

char g[N][N];

VPII p = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}};

bool ok(int y, int x)
{
	return 1<=y && y<=n && 1<=x && x<=m && g[y][x]=='#';
}

bool check(int y, int x)
{
	for(auto a:p)
	{
		int dy = y-a.st;
		int dx = x-a.nd;
		bool dob = 1;

		for(auto b:p)
		{
			int Y = dy+b.st;
			int X = dx+b.nd;

			if(!ok(Y, X))
				dob = 0;
		}

		if(dob)
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
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(g[i][j]=='#' && !check(i, j))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
}