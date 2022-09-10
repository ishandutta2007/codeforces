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

#define N 107
#define abs(a) ((a)>0?(a):-(a))

int n;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int dp[N][1<<17];

PII p[N][1<<17];

int a[N];

int m[N];

VI ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= 59; ++i)
	{
		for(int j = 0; j < 17; ++j)
		{
			if(i%primes[j]==0)
				m[i] ^= (1<<j);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		fill(dp[i], dp[i]+(1<<17), inf);
	}

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j < (1<<17); ++j)
		{
			for(int k = 1; k <= 59; ++k)
			{
				if((j&m[k])==0)
				{
					if(dp[i+1][j^m[k]]>dp[i][j]+abs(a[i+1]-k))
					{
						dp[i+1][j^m[k]] = dp[i][j]+abs(a[i+1]-k);
						p[i+1][j^m[k]] = mp(j, k);
					}
				}
			}
		}
	}

	int op = 0;

	for(int j = 0; j < (1<<17); ++j)
	{
		if(dp[n][j]<dp[n][op])
			op = j;
	}

	for(int i = n; i >= 1; --i)
	{
		ans.pb(p[i][op].nd);
		op = p[i][op].st;
	}

	reverse(ALL(ans));

	for(auto it:ans)
	{
		cout << it << " ";
	}
}