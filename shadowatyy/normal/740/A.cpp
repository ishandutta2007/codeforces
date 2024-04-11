#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

ll n, a, b, c, k, res = inf;

ll dp[107];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b >> c;

	while(n%4!=0)
	{
		++n;
		++k;
	}

	for(int i = 1; i <= 100; ++i)
	{
		dp[i] = INF;

		dp[i] = min(dp[i], dp[i-1]+a);

		if(i-2>-1)
			dp[i] = min(dp[i], dp[i-2]+b);

		if(i-3>-1)
			dp[i] = min(dp[i], dp[i-3]+c);
	}

	for(int i = k; i <= 100; i += 4)
	{
		res = min(res, dp[i]);
	}

	cout << res;


}