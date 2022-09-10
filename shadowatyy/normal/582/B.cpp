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

#define dec efhiwofkew

int n, t;

int inc[207][207];
int dec[207][207];

int a[207];
int rev[207];

int ile[307];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> t;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i+n] = a[i];
		++ile[a[i]];
	}

	for(int i = 1; i <= 2*n; ++i)
		rev[i] = a[i];

	reverse(rev+1, rev+1+2*n);

	for(int i = 1; i <= min(2*n, t); ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			inc[i][j] = 1;
			dec[i][j] = 1;

			for(int k = 1; k <= n; ++k)
			{
				if(a[k]<=a[j])
				{
					if(k<j)
						inc[i][j] = max(inc[i][j], inc[i][k]+1);
					else
						inc[i][j] = max(inc[i][j], inc[i-1][k]+1);

				}

				if(rev[k]>=rev[j])
				{
					if(k<j)
						dec[i][j] = max(dec[i][j], dec[i][k]+1);
					else
						dec[i][j] = max(dec[i][j], dec[i-1][k]+1);
				}
			}
		}
	}

	if(t<=2*n)
	{
		int res = 0;

		for(int i = 1; i <= n; ++i)
			res = max(res, inc[t][i]);

		cout << res;
	}
	else
	{
		int res = 0;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				for(int v = 1; v <= 300; ++v)
				{
					if(a[i]<=v && v<=a[j])
						res = max(res, inc[n][i]+dec[n][n-j+1]+ile[v]*(t-2*n));
				}
			}
		}

		cout << res;
	}
}