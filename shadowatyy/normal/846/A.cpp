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

const int N = 107;

int n;

int a[N];

int dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	dp[1] = 1;
	int res = 1;

	for(int i = 2; i <= n; ++i)
	{
		dp[i] = 1;

		if(a[i]==1)
		{
			for(int j = 1; j < i; ++j)
			{
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		else
		{
			for(int j = 1; j < i; ++j)
			{
				if(a[j]==0)
					dp[i] = max(dp[i], dp[j]+1);
			}
		}

		res = max(res, dp[i]);
	}

	cout << res;
}