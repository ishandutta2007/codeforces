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

#define N 200007
#define K 57

int n, k;

int t[N];

double s[N];
double p[N];
double o[N];

double dp[K][N];

deque<pair<double, double> > env;

double intersect(double a1, double b1, double a2, double b2)
{
	return (b1-b2)/(a2-a1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		s[i] = s[i-1]+t[i];
		o[i] = o[i-1]+(double)1/t[i];
		p[i] = p[i-1]+(double)s[i]/t[i];
	}

	for(int l = 0; l <= k; ++l)
	{
		for(int i = 0; i <= n; ++i)
		{
			dp[l][i] = 1e16;
		}
	}

	dp[0][0] = 0;

	for(int l = 1; l <= k; ++l)
	{
		env.clear();
		env.eb(-s[0], dp[l-1][0]-p[0]+s[0]*o[0]);

		for(int i = 1; i <= n; ++i)
		{
			//dp[l][i] = min(dp[l][i], dp[l-1][j]-p[j]+s[j]*o[j]-s[j]*o[i]+p[i]);

			while(env.size()>=2 && env[0].st*o[i]+env[0].nd>=env[1].st*o[i]+env[1].nd)
				env.pop_front();

			dp[l][i] = env[0].st*o[i]+env[0].nd+p[i];

			while(env.size()>=2 && intersect(env[env.size()-2].st, env[env.size()-2].nd, -s[i], dp[l-1][i]-p[i]+s[i]*o[i])
				<=intersect(env[env.size()-2].st, env[env.size()-2].nd, env.back().st, env.back().nd))
				env.pop_back();

			env.eb(-s[i], dp[l-1][i]-p[i]+s[i]*o[i]);
		}
	}

	cout << setprecision(10) << fixed << dp[k][n];
}