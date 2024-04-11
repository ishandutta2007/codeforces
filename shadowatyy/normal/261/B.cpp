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

#define N 57

int n, p, s;

double res;

int a[N];

double fact[N];

ll dp[N][N];
ll pref[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = log(1);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		fact[i] = fact[i-1]+log(i);
		s += a[i];
	}

	cin >> p;

	if(s<=p)
	{
		cout << fixed << setprecision(10) << n;
		return 0;
	}

	for(int b = 1; b <= n; ++b)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= p; ++j)
			{
				dp[i][j] = 0;
			}
		}

		dp[0][0] = 1;

		for(int i = 1; i <= n; ++i)
		{
			if(i==b)
				continue;

			for(int j = n-1; j >= 0; --j)
			{
				for(int k = 0; k+a[i] <= p; ++k)
				{
					dp[j+1][k+a[i]] += dp[j][k];
				}
			}
		}

		for(int j = 0; j <= n; ++j)
		{
			for(int k = p-a[b]+1; k <= p; ++k)
			{
				pref[j] += dp[j][k];
			}
				
		}
	}	

	for(int i = 0; i < n; ++i)
	{
		res += exp(log(i)+log(pref[i])+fact[i]+fact[n-i-1]-fact[n]);
	}

	cout << res;
}