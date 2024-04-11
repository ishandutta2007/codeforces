#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 2007;

int n;

int a[N];

int dp[N][N][2];

int pref[N];
int suf[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==1)
			pref[i] = 1;

		pref[i] += pref[i-1];
	}

	for(int i = n; i >= 1; --i)
	{
		if(a[i]==2)
			suf[i] = 1;

		suf[i] += suf[i+1];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==1)
			dp[i][i][1] = 1;
		else
			dp[i][i][0] = 1;

		for(int j = i+1; j <= n; ++j)
		{
			if(a[j]==2)
				dp[i][j][0] = 1+dp[i][j-1][0];
			else
				dp[i][j][1] = 1+max(dp[i][j-1][0], dp[i][j-1][1]);

			dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
			dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1]);
		}
	}

	int ans = 0;

	for(int i = 1; i <= n+1; ++i)
	{
		ans = max(ans, pref[i-1]+suf[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			ans = max(ans, pref[i-1]+max(dp[i][j][0], dp[i][j][1])+suf[j+1]);
		}
	}

	cout << ans << endl;
}