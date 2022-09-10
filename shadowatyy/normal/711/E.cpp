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

#define MOD 1000003

ll n, k;

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

	if(n<=60 && k>(1ll<<n))
	{
		cout << 1 << " " << 1;
		return 0;
	}

	ll t = 0;

	for(ll pot = 2; pot <= k-1; pot *= 2)
		t += (k-1)/pot;

	t += n;

	ll A = 1;

	if(k>MOD)
		A = 0;
	else
	{
		ll pot = fpow(2, n);

		for(int i = 0; i < k; ++i)
		{
			A *= (pot-i+MOD)%MOD;
			A %= MOD;
		}
	}

	ll B = fpow(fpow(2, n), k);
	A *= fpow(fpow(2, MOD-2), t);
	A %= MOD;
	B *= fpow(fpow(2, MOD-2), t);
	B %= MOD;

	cout << ((B-A)%MOD+MOD)%MOD << " " << B;
}