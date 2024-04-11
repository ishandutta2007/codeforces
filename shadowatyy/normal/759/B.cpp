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

#define N 100007

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

		dp[i] = inf;
	}

	dp[0] = 0;

	int w1 = 1, w2 = 1;

	for(int i = 1; i <= n; ++i)
	{
		while(a[i]-a[w1]+1>90)
			++w1;

		while(a[i]-a[w2]+1>1440)
			++w2;

		dp[i] = min(dp[i], dp[i-1]+20);
		dp[i] = min(dp[i], dp[w1-1]+50);
		dp[i] = min(dp[i], dp[w2-1]+120);
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << dp[i]-dp[i-1] << endl;
	}
}