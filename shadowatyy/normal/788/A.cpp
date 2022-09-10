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

ll res = -INF;

ll a[N];
ll d[N];

ll dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i < n; ++i)
	{
		d[i] = max(a[i]-a[i+1], a[i+1]-a[i]);
	}

	n -= 1;

	for(int i = 1; i <= n; ++i)
	{
		if(i%2)
			d[i] = max(d[i], -d[i]);
		else
			d[i] = -max(d[i], -d[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[i] = max(d[i], d[i]+dp[i-1]);
		res = max(dp[i], res);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(i%2)
			d[i] = -max(d[i], -d[i]);
		else
			d[i] = max(d[i], -d[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[i] = max(d[i], d[i]+dp[i-1]);
		res = max(dp[i], res);
	}

	cout << res;
}