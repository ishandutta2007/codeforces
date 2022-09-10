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

#define N 103
#define M 1003

int n, m, s;

double dp[N][N*M];
double sum[N][N*M];

int x[N];

inline double suma(int l, int a, int b)
{
	if(a>b || b<0)
		return 0;

	if(a-1>=0)
		return sum[l][b]-sum[l][a-1];
	else
		return sum[l][b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	if(m==1)
	{
		cout << fixed << " " << setprecision(15) << 1;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
		s += x[i];
	}

	dp[0][0] = 1;
	sum[0][0] = 1;

	for(int i = 1; i <= n*m; ++i)
	{
		sum[0][i] = sum[0][i-1]+dp[0][i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= n*m; ++j)
		{
			dp[i][j] += suma(i-1, j-m, j-x[i]-1)*(double)1/(m-1);
			dp[i][j] += suma(i-1, j-x[i]+1, j-1)*(double)1/(m-1);
		}

		sum[i][0] = dp[i][0];

		for(int j = 1; j <= n*m; ++j)
		{
			sum[i][j] = sum[i][j-1]+dp[i][j];
		}
	}

	for(int i = n*m; i >= 0; --i)
	{
		dp[n][i] += dp[n][i+1];
	}

	cout << fixed << " " << setprecision(15) << m-(m-1)*dp[n][s];
}