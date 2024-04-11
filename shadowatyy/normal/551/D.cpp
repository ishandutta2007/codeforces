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

ll n, k;

int l, m;

struct mat
{
	ll t[2][2];

	mat()
	{
		t[0][0] = t[1][0] = t[0][1] = t[1][1] = 0;
	}
};

mat operator*(mat &a, mat &b)
{
	mat res;

	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				res.t[i][j] += a.t[i][k]*b.t[k][j];
			}

			res.t[i][j] %= m;
		}
	}

	return res;
}

mat pot(mat a, ll p)
{
	mat res;

	res.t[0][0] = res.t[1][1] = 1;

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
		return a%m;

	if(b%2)
		return a*fpow(a, b-1)%m;
	else
	{
		ll q = fpow(a, b/2);
		return q*q%m;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> l >> m;

	for(int i = l; i < 60; ++i)
	{
		if(k&(1ll<<i))
		{
			cout << 0;
			return 0;
		}
	}

	mat q;

	q.t[0][0] = q.t[0][1] = q.t[1][0] = 1;

	q = pot(q, n-1);

	ll ile = (q.t[0][0]+q.t[0][1]+q.t[1][0]+q.t[1][1])%m, pot = fpow(2, n), ans = 1;	

	for(int i = 0; i < min(60, l); ++i)
	{
		if(k&(1ll<<i))
			ans *= (pot-ile+m)%m;
		else
			ans *= ile;

		ans %= m;
	}

	for(int i = 60; i < l; ++i)
	{
		ans *= ile;
		ans %= m;
	}

	cout << ans%m;
}