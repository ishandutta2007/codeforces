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

#define N 107

int n, m, res = inf;

int g[N][N];
int t[N][N];

VI row, col, crow, ccol;

int check(int k)
{
	crow.clear();
	ccol.clear();

	for(int i = 1; i <= n; ++i)
	{
		memset(t[i], 0, sizeof t[i]);
	}

	for(int i = 0; i < k; ++i)
	{
		crow.pb(1);
	}

	for(int i = 1; i <= m; ++i)
	{
		t[1][i] = k;
	}

	for(int i = 1; i <= m; ++i)
	{
		int ile = g[1][i]-t[1][i];

		if(ile<0)
			return inf;

		for(int j = 0; j < ile; ++j)
		{
			ccol.pb(i);
		}

		for(int j = 1; j <= n; ++j)
		{
			t[j][i] += ile;
		}
	}

	for(int i = 2; i <= n; ++i)
	{
		for(int j = 2; j <= m; ++j)
		{
			if(g[i][j-1]-t[i][j-1]!=g[i][j]-t[i][j])
				return inf;
		}

		int ile = g[i][1]-t[i][1];

		if(ile<0)
			return inf;

		for(int j = 0; j < ile; ++j)
		{
			crow.pb(i);
		}

		for(int j = 1; j <= m; ++j)
		{
			t[i][j] += ile;
		}
	}

	return crow.size()+ccol.size();
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

	for(int i = 0; i <= 500; ++i)
	{
		int c = check(i);

		if(c<res)
		{
			res = c;
			row = crow;
			col = ccol;
		}
	}

	if(res==inf)
		cout << -1 << endl;
	else
	{
		cout << res << endl;

		for(auto it:row)
		{
			cout << "row " << it << endl;
		}

		for(auto it:col)
		{
			cout << "col " << it << endl;
		}
	}
}