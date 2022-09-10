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

const int N = 137;

int n;

double p[N][N];
double prob[N][N];
bitset<N> vis[N];
double dp[N][N];

void licz_prob(int v, int a, int b)
{
	if(a==b)
	{
		prob[v][a] = 1;
		return;
	}

	licz_prob(2*v, a, (a+b)/2);
	licz_prob(2*v+1, (a+b)/2+1, b);

	for(int i = a; i <= (a+b)/2; ++i)
	{
		for(int j = (a+b)/2+1; j <= b; ++j)
		{
			prob[v][i] += p[i][j]*prob[2*v][i]*prob[2*v+1][j];
		}
	}

	for(int i = (a+b)/2+1; i <= b; ++i)
	{
		for(int j = a; j <= (a+b)/2; ++j)
		{
			prob[v][i] += p[i][j]*prob[2*v+1][i]*prob[2*v][j];
		}
	}
}

double solve(int v, int a, int b, int win)
{
	if(vis[v][win])
		return dp[v][win];

	vis[v][win] = 1;

	if(a==b)
		return 0;

	int len = (b-a+1), waga = len/2;

	if(win<=(a+b)/2)
	{
		double res = -1;

		for(int i = (a+b)/2+1; i <= b; ++i)
		{
			solve(2*v+1, (a+b)/2+1, b, i);
			res = max(res, dp[2*v+1][i]);
		}

		solve(2*v, a, (a+b)/2, win);
		res += dp[2*v][win];

		for(int i = (a+b)/2+1; i <= b; ++i)
		{
			res += waga*p[win][i]*prob[2*v][win]*prob[2*v+1][i];
		}

		dp[v][win] = res;
		return res;
	}
	else
	{
		double res = -1;

		for(int i = a; i <= (a+b)/2; ++i)
		{
			solve(2*v, a, (a+b)/2, i);
			res = max(res, dp[2*v][i]);
		}

		solve(2*v+1, (a+b)/2, b, win);
		res += dp[2*v+1][win];

		for(int i = a; i <= (a+b)/2; ++i)
		{
			res += waga*p[win][i]*prob[2*v+1][win]*prob[2*v][i];
		}

		dp[v][win] = res;
		return res;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= (1<<n); ++i)
	{
		for(int j = 1; j <= (1<<n); ++j)
		{
			int x;
			cin >> x;
			p[i][j] = x;
			p[i][j] /= 100;
		}
	}

	licz_prob(1, 1, (1<<n));

	double res = -1;

	for(int i = 1; i <= (1<<n); ++i)
	{
		solve(1, 1, (1<<n), i);
		res = max(res, dp[1][i]);
	}

	cout << fixed << setprecision(15) << res;
}