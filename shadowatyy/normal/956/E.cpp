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

const int N = 1e4+7;

int n, l, r, s;

int a[N];
int b[N];
int dp[N];

bitset<N> ple;

VI c;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> l >> r;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s += a[i];
	}

	l = s-l;
	r = s-r;
	swap(l, r);

	ple[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];

		if(b[i])
			c.pb(a[i]);
		else
			ple |= ple<<a[i];
	}

	sort(ALL(c));
	reverse(ALL(c));

	for(int i = 0; i < N; ++i)
	{
		if(ple[i])
			dp[i] = 0;
		else
			dp[i] = -inf;
	}

	for(auto it:c)
	{
		for(int i = N-1-it; i >= 0; --i)
		{
			if(l<=i+it && i+it<=r)
				dp[i+it] = max(dp[i+it], dp[i]+1);
			else
				dp[i+it] = max(dp[i+it], dp[i]);
		}
	}

	int ans = 0;

	for(int i = 0; i < N; ++i)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}