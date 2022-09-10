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

const int N = 507;

int n, m, k, q;

int y[N*N];
int x[N*N];
int t[N*N];
int p[N][N];

bool check(int c)
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			p[i][j] = 0;
		}
	}

	for(int i = 1; i <= q; ++i)
	{
		if(t[i]<=c)
			++p[y[i]][x[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			p[i][j] += p[i-1][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			p[i][j] += p[i][j-1];
		}
	}

	for(int i = k; i <= n; ++i)
	{
		for(int j = k; j <= m; ++j)
		{
			if(p[i][j]+p[i-k][j-k]-p[i-k][j]-p[i][j-k]==k*k)
				return 1;
		}
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> y[i] >> x[i] >> t[i];
	}

	int l = 0, r = 1e9+7;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--m;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	if(l>1e9)
		cout << -1;
	else
		cout << l;
}