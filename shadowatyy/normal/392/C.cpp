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

const int K = 47;
const int MOD = 1e9+7;

ll n, ans;

int k;

ll dwumian[K][K];

VI vec;

struct mat
{
	ll m[2*K][2*K];

	mat()
	{
		for(int i = 0; i < 2*K; ++i)
			memset(m[i], 0, sizeof m[i]);
	}
};

mat operator*(mat &a, mat &b)
{
	mat res;

	for(int i = 0; i <= 2*k+2; ++i)
	{
		for(int j = 0; j <= 2*k+2; ++j)
		{
			for(int l = 0; l <= 2*k+2; ++l)
			{
				res.m[i][j] += (a.m[i][l]*b.m[l][j])%MOD;
			}

			res.m[i][j] %= MOD;
		}
	}

	return res;
}

mat pot(mat a, ll p)
{
	mat res;

	for(int i = 0; i <= 2*k+2; ++i)
	{
		res.m[i][i] = 1;
	}

	for(int i = 0; i < 60; ++i)
	{
		if(p&(1ll<<i))
			res = res*a;

		a = a*a;
	}

	return res;
}

ll fpow(ll a, ll b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%MOD;

	if(b%2)
		return a*fpow(a, b-1)%MOD;
	else
	{
		ll q = fpow(a, b/2);
		return q*q%MOD;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	if(n==1)
	{
		cout << 1;
		return 0;
	}

	for(int i = 0; i <= k; ++i)
	{
		dwumian[i][0] = 1;
	}

	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= k; ++j)
		{
			dwumian[i][j] = (dwumian[i-1][j-1]+dwumian[i-1][j])%MOD;
		}
	}

	mat f;

	for(int i = 0; i <= k; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			f.m[i][j] = dwumian[i][j];
			f.m[i][k+1+j] = (1ll<<(i-j))%MOD*dwumian[i][j]%MOD;
			f.m[k+1+i][i] = 1;
		}
	}

	for(int i = 0; i <= 2*k+2; ++i)
	{
		f.m[2*k+2][i] = f.m[k][i];
	}

	f.m[2*k+2][2*k+2] = 1;

	n -= 2;

	f = pot(f, n);

	for(int i = 0; i <= k; ++i)
	{
		vec.pb(2*fpow(2, i));
	}

	for(int i = 0; i <= k; ++i)
	{
		vec.pb(1*fpow(1, i));
	}

	vec.pb(vec[k]+vec[2*k+1]);

	for(int i = 0; i <= 2*k+2; ++i)
	{
		ans += f.m[2*k+2][i]*vec[i];
		ans %= MOD;
	}

	cout << ans;
}