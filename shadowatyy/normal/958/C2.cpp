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

const int N = 2e4+7;
const int P = 107;
const int K = 57;

int n, k, p;

int a[N];
int pref[N];
int last[N][P];

int dp[K][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> p;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		pref[i] %= p;

		for(int j = 0; j < p; ++j)
		{
			last[i][j] = last[i-1][j];
		}

		last[i][pref[i-1]] = i-1;
	}

	for(int l = 0; l <= k; ++l)
	{
		for(int i = 0; i <= n; ++i)
		{
			dp[l][i] = -inf;
		}
	}

	dp[0][0] = 0;

	for(int i = 1; i <= n; ++i)
	{
		dp[1][i] = pref[i];
	}

	for(int l = 2; l <= k; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < p; ++j)
			{
				dp[l][i] = max(dp[l][i], dp[l-1][last[i][j]]+(pref[i]-pref[last[i][j]]+p)%p);
			}
		}
	}

	cout << dp[k][n] << endl;
}