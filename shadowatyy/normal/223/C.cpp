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

#define N 2007
#define MOD 1000000007

int n;

ll k;

ll a[N];

ll res[N];

ll bin[N];

ll fpow(ll a, int b)
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

ll inv(ll a)
{
	return fpow(a, MOD-2);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	if(k==0)
	{
		for(int i = 1; i <= n; ++i)
		{
			cout << a[i] << " ";
		}

		return 0;
	}

	--k;

	for(int i = 0; i < n; ++i)
	{
		ll curr = 1;

		for(int j = 0; j < i; ++j)
		{
			curr *= (k+i-j);
			curr %= MOD;
			curr *= inv(j+1);
			curr %= MOD;
		}

		bin[i] = curr;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			res[j] += a[i]*bin[j-i];
			res[j] %= MOD;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}