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

#define int long long
const int N = 57;

int n, k;

int a[N];

int dp[N][N];

bool check(int curr)
{
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			dp[i][j] = 0;
		}
	}

	dp[0][0] = 1;

	for(int l = 1; l <= k; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if((curr&(a[i]-a[j]))==curr && dp[l-1][j])
					dp[l][i] = 1;
			}
		}
	}

	return dp[k][n];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] += a[i-1];
	}

	int curr = 0;

	for(int i = 59; i >= 0; --i)
	{
		curr |= 1ll<<i;

		if(!check(curr))
			curr ^= 1ll<<i;
	}

	cout << curr << endl;
}