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

int n, L, ans;

int c[37];
int dp[37];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> L;

	for(int i = 0; i < n; ++i)
	{
		cin >> c[i];
	}

	for(int i = n; i < 30; ++i)
	{
		c[i] = INF;
	}

	for(int i = 1; i < 30; ++i)
	{
		c[i] = min(c[i], 2*c[i-1]);
	}

	if(L&1)
		dp[0] = c[0];

	for(int i = 1; i < 30; ++i)
	{
		if(L&(1<<i))
			dp[i] = min(dp[i-1]+c[i], 2*c[i]);
		else
			dp[i] = min(dp[i-1], c[i]);
	}

	cout << dp[29];
}