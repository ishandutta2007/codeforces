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

#define K 2007
#define N 200007
#define MOD inf

int n, m, k, s, y, x;

ll P;

ll f[N];

ll dp[K][25];
ll dpc[K][25];

VPII c;

ll ile[K][K];

ll add[27];

ll pot(ll a, int w)
{
	ll res = 1;

	for(int i = 0; i < 31; ++i)
	{
		if(w&(1<<i))
			res = (res*a)%MOD;

		a = (a*a)%MOD;
	}

	return res;
}

ll dziel(ll a, ll b)
{
	return ((a%MOD)*pot(b%MOD, MOD-2))%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	f[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		f[i] = (f[i-1]*i)%MOD;
	}

	cin >> n >> m >> k >> s;

	add[0] = s;

	for(int i = 1; i <= 25; ++i)
	{
		add[i] = (add[i-1]+1)/2;
	}

	for(int i = 1; i <= k; ++i)
	{
		cin >> y >> x;
		c.eb(y, x);
	}

	k += 2;
	c.eb(1, 1);
	c.eb(n, m);

	sort(ALL(c));

	for(int i = 0; i < k; ++i)
	{
		for(int j = i+1; j < k; ++j)
		{
			if(c[j].nd>=c[i].nd)
				ile[i][j] = dziel(f[c[j].st-c[i].st+c[j].nd-c[i].nd], f[c[j].st-c[i].st]*f[c[j].nd-c[i].nd]);
		}
	}

	for(int i = 0; i < k; ++i)
	{
		dpc[i][1] = dziel(f[c[i].st-1+c[i].nd-1], f[c[i].st-1]*f[c[i].nd-1]);
	}

	for(int l = 2; l < 25; ++l)
	{
		for(int i = 0; i < k; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				dpc[i][l] = (dpc[i][l]+ile[j][i]*dp[j][l-1])%MOD;
			}

			dp[i][l-1] = (dpc[i][l-1]-dpc[i][l]+MOD)%MOD;
		}
	}

	for(int i = 2; i < 24; ++i)
	{
		P = (P+add[i-2]*dp[k-1][i])%MOD;
	}

	P = (P+add[22]*dpc[k-1][24])%MOD;

	cout << dziel(P, dziel(f[n-1+m-1], f[n-1]*f[m-1]));

}