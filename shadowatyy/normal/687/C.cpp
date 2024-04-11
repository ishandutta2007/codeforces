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

#define N 507

int n, k, v;

bitset<N> dp[N];

VI res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	dp[0][0] = 1;

	for(int e = 1; e <= n; ++e)
	{
		cin >> v;

		for(int i = N-1; i >= 0; --i)
		{
			for(int j = N-1; j >= 0; --j)
			{
				if(dp[i][j] && i+v<N)
					dp[i+v][j] = 1;

				if(dp[i][j] && j+v<N)
					dp[i][j+v] = 1;

			}
		}
	}

	for(int i = 0; i <= k; ++i)
	{
		if(dp[i][k-i])
			res.pb(i);
	}

	cout << res.size() << endl;

	for(auto it:res)
		cout << it << " ";
}