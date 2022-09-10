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

int n, a, b;

double A[N];
double B[N];

pair<double, int> dp[N][N];

void solve(double c)
{
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= a; ++j)
		{
			dp[i][j] = {-inf, -inf};
		}
	}

	dp[0][0] = {0, 0};

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= a; ++j)
		{
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], {dp[i][j].st+A[i+1], dp[i][j].nd});
			dp[i+1][j] = max(dp[i+1][j], {dp[i][j].st+B[i+1]-c, dp[i][j].nd+1});
			dp[i+1][j+1] = max(dp[i+1][j+1], {dp[i][j].st+1-(1-A[i+1])*(1-B[i+1])-c, dp[i][j].nd+1});
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b;

	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> B[i];
	}

	double l = 0, r = n;

	for(int i = 1; i <= 50; ++i)
	{
		double m = (l+r)/2;

		solve(m);

		if(dp[n][a].nd<b)
			r = m;
		else
			l = m;
	}

	solve(l);

	cout << fixed << setprecision(10) << dp[n][a].st+l*b;
}