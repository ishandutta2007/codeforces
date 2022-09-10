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

#define N 1000007
#define MOD inf

int n, res;

int h[N];
ll dp[N];
ll ok[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> h[i];
		--h[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(h[i-1]<=h[i])
		{
			dp[i] = h[i-1]*dp[i-1]+h[i];
			ok[i] = min(h[i-1], h[i+1])*dp[i-1]+min(h[i], h[i+1]);
		}
		else
		{
			dp[i] = h[i]*ok[i-1]+h[i];
			ok[i] = min(h[i], h[i+1])*ok[i-1]+min(h[i], h[i+1]);
		}

		dp[i] %= MOD;
		ok[i] %= MOD;
	}

	for(int i = 1; i <= n; ++i)
	{
		res = (res+dp[i])%MOD;
	}

	cout << res;
}