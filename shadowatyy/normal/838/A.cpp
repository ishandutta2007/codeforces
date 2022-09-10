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

const int N = 5007;

int n, m, res = inf; 

char c;

int g[N][N];

int rec(int y, int x, int k)
{
	return g[y+k-1][x+k-1]+g[y-1][x-1]-g[y-1][x+k-1]-g[y+k-1][x-1];
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
			cin >> c;
			g[i][j] = c-'0';
		}
	}

	for(int i = 1; i <= 2*max(n, m); ++i)
	{
		for(int j = 1; j <= 2*max(n, m); ++j)
		{
			g[i][j] += g[i][j-1];
		}
	}

	for(int i = 1; i <= 2*max(n, m); ++i)
	{
		for(int j = 1; j <= 2*max(n, m); ++j)
		{
			g[i][j] += g[i-1][j];
		}
	}

	for(int k = 2; k <= max(n, m); ++k)
	{
		int curr = 0;

		for(int i = 1; i <= n; i += k)
		{
			for(int j = 1; j <= m; j += k)
			{
				curr += min(k*k-rec(i, j, k), rec(i, j, k));
			}
		}

		res = min(res, curr);
	}

	cout << res;
}