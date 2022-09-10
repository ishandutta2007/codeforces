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

#define N 5000007
#define M 1000000007

int t, l, r;

ll pot = 1, res;
	
ll dp[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t >> l >> r;

	for(int i = 2; i <= r; ++i)
		dp[i] = INF;

	for(int i = 2; i <= r; ++i)
	{
		dp[i] = min(dp[i], (ll)i*(i-1)/2);

		for(int j = 2*i; j <= r; j += i)
		{
			dp[j] = min(dp[j], (ll)j*(j/i-1)/2+dp[i]);
		}
	}

	for(int i = 0; i < r-l+1; ++i)
	{
		res += pot*(dp[l+i]%M);
		res %= M;
		pot *= t;
		pot %= M;
	}

	cout << res;
}