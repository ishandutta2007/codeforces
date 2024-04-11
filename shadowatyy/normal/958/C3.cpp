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

const int N = 5e5+7;
const int K = 107;

int n, k, p;

int a[N];
int pref[N];

int nast[N][K];
int dp[K][K][K];
int Min[K];
int late[K];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> p;

	Min[1] = inf;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		pref[i] %= p;
		Min[1] = min(Min[1], pref[i]);
		late[pref[i]] = i;
	}

	for(int i = 0; i < p; ++i)
	{
		nast[n+1][i] = n+1;
	}

	for(int i = n; i >= 1; --i)
	{
		for(int j = 0; j < p; ++j)
		{
			nast[i][j] = nast[i+1][j];
			nast[i][pref[i+1]] = i+1;
		}
	}

	for(int l = 0; l <= k; ++l)
	{
		for(int r = 0; r < p; ++r)
		{
			for(int w = 0; w < p; ++w)
			{
				dp[l][r][w] = n+1;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[1][pref[i]][pref[i]-Min[1]] = min(dp[1][pref[i]][pref[i]-Min[1]], i);
	}

	for(int l = 2; l <= k; ++l)
	{
		Min[l] = inf;

		for(int r = 0; r < p; ++r)
		{
			for(int s = 0; s < p; ++s)
			{
				for(int w = 0; w < p; ++w)
				{
					if(dp[l-1][s][w]<late[r])
					{
						Min[l] = min(Min[l], Min[l-1]+w+(r-s+p)%p);
					}
				}
			}
		}

		for(int r = 0; r < p; ++r)
		{
			for(int w = 0; w < p; ++w)
			{
				for(int s = 0; s < p; ++s)
				{
					int add = (r-s+p)%p;
					int real = Min[l]+w-add;

					if(0<=real-Min[l-1] && real-Min[l-1]<p)
					{	
						dp[l][r][w] = min(dp[l][r][w], nast[dp[l-1][s][real-Min[l-1]]][r]);
					}
				}
			}
		}
	}

	for(int i = 0; i < p; ++i)
	{
		if(dp[k][pref[n]][i]<=n)
		{
			cout << Min[k]+i << endl;
			return 0;
		}
	}
}