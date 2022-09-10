#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 5007;

int n;

int a[N];

int dp[N][N/2][3];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= (i+1)/2; ++j)
		{
			for(int k = 0; k < 3; ++k)
			{
				dp[i][j][k] = inf;
			}
		}
	}

	dp[0][0][0] = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j <= (i+1)/2; ++j)
		{
			for(int k = 0; k < 3; ++k)
			{	
				if(dp[i][j][k]==inf)
					continue;

				int wys = -1;

				if(k==0 || k==1)
					wys = a[i];
				else
					wys = min(a[i], a[i-1]-1);

				if(k==0 || k==2)
					dp[i+1][j+1][1] = min(dp[i+1][j+1][1], dp[i][j][k]+max(0, wys-a[i+1]+1));
				
				if(k==0)
					dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k]);
				else if(k==1)
					dp[i+1][j][2] = min(dp[i+1][j][2], dp[i][j][k]+max(0, a[i+1]-wys+1));
				else if(k==2)
					dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][k]);
			}
		}
	}

	for(int i = 1; i <= (n+1)/2; ++i)
	{
		int ans = inf;

		for(int k = 0; k < 3; ++k)
		{
			ans = min(ans, dp[n][i][k]);
		}

		cout << ans << " ";
	}

	cout << endl;
}