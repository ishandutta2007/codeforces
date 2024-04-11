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

const int N = 1e6+7;
const int MOD = 1e9+7;
const int M = 107;

int n, l, m;

int s[N];
int t[N];
int c[N];
int ile[M];
int ile_s[M];
ll ile_sum[M];

struct mat
{
	ll t[M][M];

	mat()
	{
		for(int i = 0; i < M; ++i)
		{
			memset(t, 0, sizeof t);
		}
	}
};

mat operator*(const mat &a, const mat &b)
{
	mat c;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			for(int k = 0; k < m; ++k)
			{
				c.t[i][j] += a.t[i][k]*b.t[k][j]%MOD;
			}

			c.t[i][j] %= MOD;
		}
	}

	return c;
}

mat pot(mat a, int p)
{
	mat res;

	for(int i = 0; i < m; ++i)
	{
		res.t[i][i] = 1;
	}

	for(int i = 0; i < 30; ++i)
	{
		if(p&(1<<i))
			res = res*a;

		a = a*a;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> l >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		s[i] %= m;
		++ile_s[s[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
		c[i] %= m;
		++ile[c[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		t[i] += c[i];
		t[i] %= m;

		for(int j = 0; j < m; ++j)
		{
			if(j>=t[i])
			{
				ile_sum[j] += ile_s[j-t[i]];
				ile_sum[j] %= MOD;
			}	
			else
			{
				ile_sum[j] += ile_s[m+j-t[i]];
				ile_sum[j] %= MOD;
			}
		}
	}

	l -= 2;

	mat x;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(i>=j)
				x.t[i][j] = ile[i-j];
			else
				x.t[i][j] = ile[m+i-j];
		}
	}

	x = pot(x, l);

	ll ans = 0;

	for(int i = 0; i < m; ++i)
	{
		ans += x.t[i][0]*ile_sum[(m-i)%m]%MOD;
		ans %= MOD;
	}

	cout << ans;
}