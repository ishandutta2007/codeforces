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
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+7;

int n;

int cnt[77];

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int dp[77][1<<19];
ll pot[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	pot[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		pot[i] = pot[i-1]*2%MOD;
	}

	cin >> n;

	while(n--)
	{
		int a;
		cin >> a;
		++cnt[a];
	}

	dp[0][0] = 1;

	for(int i = 1; i <= 70; ++i)
	{
		if(!cnt[i])
		{
			for(int j = 0; j < 1<<19; ++j)
			{
				dp[i][j] = dp[i-1][j];
			}

			continue;
		}

		int curr = i, maska = 0;

		for(int j = 0; j < 19; ++j)
		{
			while(curr%p[j]==0)
			{
				curr /= p[j];
				maska ^= (1<<j);
			}
		}

		for(int j = 0; j < 1<<19; ++j)
		{
			dp[i][j^maska] += pot[cnt[i]-1]*dp[i-1][j]%MOD;
			dp[i][j^maska] %= MOD;
			dp[i][j] += pot[cnt[i]-1]*dp[i-1][j]%MOD;
			dp[i][j] %= MOD;
		}
	}

	cout << (dp[70][0]-1+MOD)%MOD;
}