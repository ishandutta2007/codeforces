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

#define N 507

int n;

int in[N], out[N], w[N], s[N], v[N];

int dp[N][2*N];
int dpp[2*N];

VI par;

int c;

int solve(int i, int rs)
{
	dp[i][rs] = v[i];

	for(int j = 1; j <= n; ++j)
	{
		if(i!=j && rs-w[j]>=0 && in[i]<=in[j] && out[j]<=out[i] && dp[j][min(rs-w[j], s[j])]==-1)
			solve(j, min(rs-w[j], s[j]));
	}

	memset(dpp, 0, sizeof dpp);      

	int q = 0;

	for(auto j:par)
	{
		while(q<in[j])
			dpp[++q] = max(dpp[q], dpp[q-1]);

		if(i!=j && rs-w[j]>=0 && in[i]<=in[j] && out[j]<=out[i])
			dpp[out[j]] = max(dpp[out[j]], dpp[in[j]]+dp[j][min(rs-w[j], s[j])]);
	}

	while(q<2*n)
		dpp[++q] = max(dpp[q], dpp[q-1]);

	return dp[i][rs] = v[i]+dpp[out[i]];
}

bool comp(int a, int b)
{
	return in[a]<in[b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s[0];

	in[0] = 0;
	out[0] = 2*n;
	w[0] = 0;
	v[0] = 0;

	for(int i = 1; i <= n; ++i)
	{
		cin >> in[i] >> out[i] >> w[i] >> s[i] >> v[i];
		par.pb(i);
	}

	sort(ALL(par), comp);

	for(int i = 0; i <= n; ++i)
	{
		memset(dp[i], -1, sizeof dp[i]);
	}

	cout << solve(0, s[0]);
}