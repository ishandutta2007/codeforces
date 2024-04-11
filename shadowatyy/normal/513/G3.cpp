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
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 107

int n, k;

int p[N];

double res;

double curr[N][N];
double last[N][N];

int przejscia[4][N][N][2*N];

VPII v[4][N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	k = min(k, 1000);

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(p[i]>p[j])
				curr[i][j] = 1;
		}
	}

	double s = n*(n+1)/2;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(int x = 1; x <= n; ++x)
			{
				for(int y = x; y <= n; ++y)
				{
					if(x<=i && i<=y && x<=j && j<=y)
					{
						if(x+y-i<=x+y-j) 
							++przejscia[0][i][j][x+y];
					}
					else if(x<=i && i<=y)
					{
						if(x+y-i<=j) 
							++przejscia[1][i][j][x+y];
					}
					else if(x<=j && j<=y)
					{
						if(i<=x+y-j)
							 ++przejscia[2][i][j][x+y];
					}
					else
					{
						if(i<=j) 
							++przejscia[3][i][j][0];
					}
				}
			}
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(int c = 0; c <= 2*n; ++c)
			{
				for(int q = 0; q < 4; ++q)
				{
					if(przejscia[q][i][j][c])
						v[q][i][j].eb(c, przejscia[q][i][j][c]);
				}
			}
		}
	}

	for(int l = 1; l <= k; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				last[i][j] = curr[i][j];
				curr[i][j] = 0;
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				double val = last[i][j]/s;

				for(auto it:v[0][i][j])
					curr[it.st-i][it.st-j] += it.nd*val;

				for(auto it:v[1][i][j])
					curr[it.st-i][j] += it.nd*val;

				for(auto it:v[2][i][j])
					curr[i][it.st-j] += it.nd*val;

				for(auto it:v[3][i][j])
					curr[i][j] += it.nd*val;
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			for(int j = i+1; j <= n; ++j)
			{
				curr[j][i] = 1-curr[i][j];
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			res += curr[i][j];
		}
	}

	cout << setprecision(15) << fixed << res;
}