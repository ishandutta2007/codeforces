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

#define int long long
const int N = 57;

int n;

int a[N];
int sum[N];
int dp[N][N];
bool vis[N][N];

int solve(int a, int b)
{
	if(vis[a][b])
		return dp[a][b];

	vis[a][b] = 1;

	if(a>b)
		return 0;

	dp[a][b] = solve(a+1, b);
	dp[a][b] = max(dp[a][b], sum[b]-sum[a-1]-solve(a+1, b));

	return dp[a][b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	//sort(a+1, a+1+n);

	for(int i = 1; i <= n; ++i)
	{
		sum[i] += sum[i-1];
		sum[i] += a[i];
	}

	cout << sum[n]-solve(1, n) << " " << solve(1, n);
}