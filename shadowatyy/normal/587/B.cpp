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

#define real dweiefweif

const int N = 1e6+7;
const int MOD = 1e9+7;

int n;

ll l, k, ans;

int a[N];

VLL dp[N];
VLL pref[N];

int pos[N];
int real[N];

VPII v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> l >> k;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		v.eb(a[i], i);
	}

	sort(ALL(v));

	for(int i = n-1; i >= 0; --i)
	{
		if(i<n-1 && v[i].st==v[i+1].st)
			pos[i] = pos[i+1];
		else
			pos[i] = i;

		real[i] = v[i].nd;
	}

	for(int i = 0; i <= k; ++i)
	{
		dp[i].resize(n);
		pref[i].resize(n);
		fill(ALL(dp[i]), 0);
		fill(ALL(pref[i]), 0);		
	}

	dp[0][0] = 1;
	pref[0][0] = 1;

	for(int i = 1; i < n; ++i)
	{
		pref[0][i] += pref[0][i-1];
		pref[0][i] %= MOD;
	}

	for(int i = 1; i <= k; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			dp[i][j] = pref[i][j] = pref[i-1][pos[j]];
		}

		for(int j = 1; j < n; ++j)
		{
			pref[i][j] += pref[i][j-1];
			pref[i][j] %= MOD;
		}
	}

	ll d = l/n;

	for(int i = 1; i <= min(k, d+1); ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(real[j]<l%n)
				ans += dp[i][j]*((d-i+2)%MOD)%MOD;
			else
				ans += dp[i][j]*((d-i+1)%MOD)%MOD;

			ans %= MOD;
			ans += MOD;
			ans %= MOD;
		}
	}	

	cout << ans;
}