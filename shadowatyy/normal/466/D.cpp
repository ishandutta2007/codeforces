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

#define MOD inf
#define N 2007

int n, h;

int a[N];

ll dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> h;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	dp[0][0] = 1;
	a[0] = a[n+1] = h;

	for(int i = 0; i <= n+1; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if(h-a[i+1]==j-1 && j>0) dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j]*j)%MOD; //zamykam
			if(h-a[i+1]==j+1) dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD; //otwieram
			if(h-a[i+1]==j && j>0) dp[i+1][j] = (dp[i+1][j]+dp[i][j]*j)%MOD; //zamykam i otwieram
			if(h-a[i+1]==j) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD; //nic
		}
	}

	cout << dp[n+1][0];
}