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

const int N = 2507;
#define ld long double

int n;

ld res;

int x[N];
int y[N];

ld dist(int a, int b)
{
	return sqrtl((ll)(x[a]-x[b])*(x[a]-x[b])+(ll)(y[a]-y[b])*(y[a]-y[b]));
}

ld dp[2][N][N];
bitset<N> vis[2][N];

void solve(int s, int a, int b)
{
	if(vis[s][a][b])
		return;

	vis[s][a][b] = 1;

	if((a-1+n)%n==b)
		return;

	if(s==0)
	{
		solve(0, (a-1+n)%n, b);
		dp[s][a][b] = max(dp[s][a][b], dist(a, (a-1+n)%n)+dp[0][(a-1+n)%n][b]);
		solve(1, a, (b+1)%n);
		dp[s][a][b] = max(dp[s][a][b], dist(a, (b+1)%n)+dp[1][a][(b+1)%n]);
	}
	else
	{
		solve(1, a, (b+1)%n);
		dp[s][a][b] = max(dp[s][a][b], dist(b, (b+1)%n)+dp[1][a][(b+1)%n]);
		solve(0, (a-1+n)%n, b);
		dp[s][a][b] = max(dp[s][a][b], dist(b, (a-1+n)%n)+dp[0][(a-1+n)%n][b]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; ++i)
	{
		solve(0, i, i);
		res = max(res, dp[0][i][i]);
		solve(1, i, i);
		res = max(res, dp[1][i][i]);
	}

	cout << fixed << " " << setprecision(15) << res;
}