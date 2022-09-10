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

#define N 57

int n, m;

int a[N];

double dp[N][N][N];
double prob[N][N][N];

double res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i];
	}

	for(int l = 1; l <= m; ++l)
	{
		prob[l][0][0] = 1;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j <= i; ++j)
			{
				if(j>0) 
					prob[l][i][j] += prob[l][i-1][j-1]*(double)1/l;

				prob[l][i][j] += prob[l][i-1][j]*(1-(double)1/l);
			}
		}
	}

	dp[0][0][0] = 1;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			for(int k = 0; k <= j; ++k)
			{
				for(int l = 0; l <= n-j; ++l)
				{
					dp[i+1][j+l][max(k, (l+a[i+1]-1)/a[i+1])] += dp[i][j][k]*prob[m-i][n-j][l];
				}
			}
		}
	}

	for(int i = 0; i <= n; ++i)
	{
		res += dp[m][n][i]*i;
	}

	cout << fixed << " " << setprecision(10) << res;
}