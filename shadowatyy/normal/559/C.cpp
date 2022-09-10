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

#define N 2007
#define M 1000000007
#define int long long

int h, w, n, x, y;
 
int dp[N];

int f[100*N];

VPII c;

int pot(int a, int w)
{
	if(w==0)
		return 1;

	if(w==1)
		return a%M;

	if(w%2)
		return (a*pot(a, w-1))%M;
	else
	{
		int q = pot(a, w/2);

		return (q*q)%M;
	}
}

int dziel(int a, int b)
{
	a %= M;
	b %= M;

	return (a*pot(b, M-2))%M;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	f[0] = 1;

	for(int i = 1; i < 100*N; ++i)
	{
		f[i] = (i*f[i-1])%M;
	}

	cin >> h >> w >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> y >> x;
		c.eb(y, x);
	}		

	++n;
	c.eb(h, w);

	sort(ALL(c));

	for(int i = 0; i < n; ++i)
	{
		dp[i] = dziel(f[c[i].st-1+c[i].nd-1], f[c[i].st-1]*f[c[i].nd-1]);

		for(int j = i-1; j >= 0; --j)
		{
			if(c[i].st>=c[j].st && c[i].nd>=c[j].nd)
			{
				dp[i] = ((dp[i]-dp[j]*dziel(f[c[i].st-c[j].st+c[i].nd-c[j].nd], f[c[i].st-c[j].st]*f[c[i].nd-c[j].nd]))%M+M)%M;
			}
		}
	}

	cout << dp[n-1];
}