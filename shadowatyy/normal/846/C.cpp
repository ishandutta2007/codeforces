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

const int N = 5007;

int n;

int a[N];

ll dp[N][5];
int skad[N][5];

VI res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j < 5; ++j)
		{
			dp[i][j] = -INF;
		}
	}

	dp[0][0] = 0;

	for(int i = 0; i <= n; ++i)
	{
		ll sum = -a[i];

		for(int j = i; j <= n; ++j)
		{
			sum += a[j];

			if(dp[j][1]<dp[i][0]+sum)
			{
				dp[j][1] = dp[i][0]+sum;
				skad[j][1] = i+1;
			}

			if(dp[j][2]<dp[i][1]-sum)
			{
				dp[j][2] = dp[i][1]-sum;
				skad[j][2] = i+1;
			}

			if(dp[j][3]<dp[i][2]+sum)
			{
				dp[j][3] = dp[i][2]+sum;
				skad[j][3] = i+1;
			}

			if(dp[j][4]<dp[i][3]-sum)
			{
				dp[j][4] = dp[i][3]-sum;
				skad[j][4] = i+1;
			}
		}
	}

	int curr = n;

	for(int i = 4; i >= 2; --i)
	{
		res.pb(skad[curr][i]);
		curr = skad[curr][i]-1;
	}

	reverse(ALL(res));

	for(auto it:res)
		cout << it-1 << " ";
}