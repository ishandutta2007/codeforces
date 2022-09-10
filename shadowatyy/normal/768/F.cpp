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

#define MOD inf
#define N 200007

ll f, w, h;

ll p, q;

ll fact[N];
ll inv[N];

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

ll dwumian(ll n, ll k)
{
	if(n<0)
		return 0;

	if(k<0)
		return 0;

	if(k>n)
		return 0;

	return fact[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
		inv[i] = fpow(fact[i], MOD-2);
	}

	cin >> f >> w >> h;

	++h;

	if(w==0)
	{
		cout << 1;
		return 0;
	}

	for(int i = 1; i <= w; ++i)
	{
		q += dwumian(i+w-i-1, w-i)*dwumian(i+1+f-i+1-1, f-i+1)%MOD;
		q %= MOD;
		p += dwumian(i+w-h*i-1, w-h*i)*dwumian(i+1+f-i+1-1, f-i+1)%MOD;
		p %= MOD;
	}

	cout << p*fpow(q, MOD-2)%MOD;
}