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

#define N 207

int n, k, res;

int ile2[N];
int ile5[N];

ll a[N];

int dp[N][30*N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		while(a[i]%2==0)
		{
			++ile2[i];
			a[i] /= 2;
		}

		while(a[i]%5==0)
		{
			++ile5[i];
			a[i] /= 5;
		}
	}

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j < 30*N; ++j)
		{
			dp[i][j] = -inf;
		}
	}

	dp[0][0] = 0;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = N-2; j >= 0; --j)
		{
			for(int l = 30*N-1-ile5[i]; l >= 0; --l)
			{
				dp[j+1][l+ile5[i]] = max(dp[j+1][l+ile5[i]], dp[j][l]+ile2[i]);
			}
		}
	}

	for(int j = 0; j < 30*N; ++j)
	{
		res = max(res, min(j, dp[k][j]));
	}

	cout << res;
}