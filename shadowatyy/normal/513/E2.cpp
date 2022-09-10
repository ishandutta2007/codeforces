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

#define N 30007
#define K 207
#define m 0
#define p 1

int n, k;

int dp[2][2][N][K]; //[znak][otwarte]

int a[N];

int mul(int j)
{
	if(j==1 || j==k)
		return 1;
	else
		return 2;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < K; ++j)
		{
			dp[m][0][i][j] = dp[m][1][i][j] = dp[p][0][i][j] = dp[p][1][i][j] = -inf;
		}
	}

	dp[m][0][0][0] = dp[p][0][0][0] = 0;

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= k; ++j)
		{	
			//minus

			//otwarty
			dp[m][1][i+1][j] = max(dp[m][1][i+1][j], dp[m][1][i][j]-mul(j)*a[i+1]); //zostaje
			dp[m][0][i][j] = max(dp[m][0][i][j], dp[m][1][i][j]); //zamykam

			//zamkniety
			dp[m][0][i+1][j] = max(dp[m][0][i+1][j], dp[m][0][i][j]); //zostaje
			dp[p][1][i+1][j+1] = max(dp[p][1][i+1][j+1], dp[m][0][i][j]+mul(j+1)*a[i+1]); //otwieram

			//zapychacz
			if(j>0 && j+1<k)
				dp[m][0][i+1][j+1] = max(dp[m][0][i+1][j+1], dp[m][0][i][j]);

			//plus

			//otwarty
			dp[p][1][i+1][j] = max(dp[p][1][i+1][j], dp[p][1][i][j]+mul(j)*a[i+1]); //zostaje
			dp[p][0][i][j] = max(dp[p][0][i][j], dp[p][1][i][j]); //zamykam

			//zamkniety
			dp[p][0][i+1][j] = max(dp[p][0][i+1][j], dp[p][0][i][j]); //zostaje
			dp[m][1][i+1][j+1] = max(dp[m][1][i+1][j+1], dp[p][0][i][j]-mul(j+1)*a[i+1]); //otwieram

			//zapychacz
			if(j>0 && j+1<k)
				dp[p][0][i+1][j+1] = max(dp[p][0][i+1][j+1], dp[p][0][i][j]);
		}
	}

	cout << max(dp[m][0][n][k], dp[p][0][n][k]);

}