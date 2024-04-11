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

#define N 300007

int n, m;

pair<PII, int> dp[N];

ll w, c;

VLL v[4];

ll res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> w >> c;
		v[w].pb(c);
	}

	v[1].pb(INF);
	v[2].pb(INF);
	v[3].pb(INF);

	sort(ALL(v[1]), greater<ll>());
	sort(ALL(v[2]), greater<ll>());
	sort(ALL(v[3]), greater<ll>());

	v[1][0] = 0;
	v[2][0] = 0;
	v[3][0] = 0;

	for(int i = 1; i < v[1].size(); ++i)
	{
		v[1][i] += v[1][i-1];
	}

	for(int i = 1; i < v[2].size(); ++i)
	{
		v[2][i] += v[2][i-1];
	}

	for(int i = 1; i < v[3].size(); ++i)
	{
		v[3][i] += v[3][i-1];
	}

	v[1].pb(-INF);
	v[2].pb(-INF);
	v[3].pb(-INF);

	for(int i = 1; i <= m; ++i)
	{
		if(i>=2 && v[1][dp[i].st.st]+v[2][dp[i].st.nd]+v[3][dp[i].nd]<v[1][dp[i-2].st.st]+v[2][dp[i-2].st.nd+1]+v[3][dp[i-2].nd])
		{
			dp[i].st.st = dp[i-2].st.st;
			dp[i].st.nd = dp[i-2].st.nd+1;
			dp[i].nd = dp[i-2].nd;
		}

		if(v[1][dp[i].st.st]+v[2][dp[i].st.nd]+v[3][dp[i].nd]<v[1][dp[i-1].st.st+1]+v[2][dp[i-1].st.nd]+v[3][dp[i-1].nd])
		{
			dp[i].st.st = dp[i-1].st.st+1;
			dp[i].st.nd = dp[i-1].st.nd;
			dp[i].nd = dp[i-1].nd;
		}

		if(v[1][dp[i].st.st]+v[2][dp[i].st.nd]+v[3][dp[i].nd]<v[1][dp[i-1].st.st]+v[2][dp[i-1].st.nd]+v[3][dp[i-1].nd])
			dp[i] = dp[i-1];
	}

	for(int i = 0; i <= min(m/3, (int)v[3].size()-2); ++i)
	{
		res = max(res, v[1][dp[m-3*i].st.st]+v[2][dp[m-3*i].st.nd]+v[3][i]);
	}

	cout << res;
	
}