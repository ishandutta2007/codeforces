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

#define N 10007

int n, f = 1;

int a[7];
int b[7];
ll dp[7][N];

VI perm;

double res, mian;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		perm.pb(i);
		f *= i;
	}

	for(int c = 0; c < f; ++c)
	{
		next_permutation(ALL(perm));

		for(int i = 0; i <= n; ++i)
		{
			memset(dp[i], 0, sizeof dp[i]);
		}

		dp[1][a[perm[0]]] = 1;

		for(int i = 1; i < n; ++i)
		{
			for(int v = a[perm[i-1]]; v <= b[perm[i-1]]; ++v)
			{
				dp[i][v] += dp[i][v-1];

				if(perm[i]>perm[i-1])
				{
					if(b[perm[i]]>=max(v, a[perm[i]]))
						dp[i+1][max(v, a[perm[i]])] += dp[i][v];
				}
				else
				{
					if(b[perm[i]]>=max(v+1, a[perm[i]]))
						dp[i+1][max(v+1, a[perm[i]])] += dp[i][v];
				}
					
			}
		}

		for(int v = 1; v < N; ++v)
		{
			if(perm[n-1]>perm[n-2])
			{
				res += v*dp[n-1][v]*(max(0, b[perm[n-1]]-max(v, a[perm[n-1]])+1));
				mian += dp[n-1][v]*(max(0, b[perm[n-1]]-max(v, a[perm[n-1]])+1));
			}
			else
			{
				res += v*dp[n-1][v]*(max(0, b[perm[n-1]]-max(v+1, a[perm[n-1]])+1));
				mian += dp[n-1][v]*(max(0, b[perm[n-1]]-max(v+1, a[perm[n-1]])+1));
			}
		}
	}

	cout << setprecision(15) << fixed << res/mian;
}