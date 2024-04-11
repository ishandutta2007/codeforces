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

const int N = 1e6+507;

ll n, m, a, q, p;

bitset<N> sito;
ll fact[N];
ll inv[N];
ll d[N];

ll fpow(ll a, ll b, ll mod)
{
	if(b==0)
		return 1;
	else if(b%2)
		return fpow(a, b-1, mod)*a%mod;
	else
	{
		ll f = fpow(a, b/2, mod);
		return f*f%mod;
	}
}

ll dwumian(ll n, ll k)
{
	return fact[n]*inv[n-k]%p*inv[k]%p;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); 

	cin >> n >> m >> a >> q;

	for(int i = 2; i < N; ++i)
	{
		if(!sito[i])
		{
			for(int j = 2*i; j < N; j += i)
			{
				sito[j] = 1;
			}
		}
	}

	for(int i = 2; i < N; ++i)
	{
		if(fpow(a, i, q)==1)
		{
			p = i;
			break;
		}
	}

	fact[0] = 1;
	inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%p;
		inv[i] = inv[i-1]*fpow(i, p-2, p)%p;
	}

	for(int i = n-1; i >= 0; --i)
	{
		d[i] = (d[i+1]+dwumian(m, n-i-1))%p;
	}

	for(int i = 0; i < n; ++i)
	{
		cout << fpow(a, d[i], q) << " ";
	}
}