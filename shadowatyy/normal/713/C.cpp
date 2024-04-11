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

#define N 3007

int n;

int a[N];
int b[N];

ll dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] -= i;
		b[i] = a[i];
	}

	sort(b+1, b+1+n);

	for(int i = 1; i <= n; ++i)
	{
		memset(dp[i], inf16, sizeof dp[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			dp[i][j] = dp[i][j-1];
			dp[i][j] = min(dp[i][j], dp[i-1][j]+max(a[i]-b[j], b[j]-a[i]));
		}
	}

	cout << dp[n][n];
}