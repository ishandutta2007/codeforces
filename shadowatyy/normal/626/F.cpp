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

#define N 207
#define K 1007
#define MOD 1000000007

int n, k;

int a[N];

int dp[N][N][K];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+n+1);

	dp[0][0][0] = 1;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			for(int l = 0; l <= k; ++l)
			{
				int d = a[i+1]-a[i];

				if(l+j*d<=k)
				{
					dp[i+1][j][l+j*d] = (dp[i+1][j][l+j*d]+(ll)dp[i][j][l])%MOD;
					dp[i+1][j+1][l+j*d] = (dp[i+1][j+1][l+j*d]+(ll)dp[i][j][l])%MOD;
					dp[i+1][j][l+j*d] = (dp[i+1][j][l+j*d]+(ll)dp[i][j][l]*j)%MOD;
					dp[i+1][j-1][l+j*d] = (dp[i+1][j-1][l+j*d]+(ll)dp[i][j][l]*j)%MOD;
				}
				else
					break;
			}
		}
	}

	int res = 0;

	for(int i = 0; i <= k; ++i)
	{
		res = (res+dp[n][0][i])%MOD;
	}

	cout << res;
}