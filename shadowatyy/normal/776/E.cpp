#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define MOD 1000000007

ll f(ll n)
{
	ll res = n;
 
	for(ll i = 2; i*i <= n; ++i)
	{
		if(n%i==0)
			res -= res/i;
 
		while(n%i==0)
			n /= i;
	}
 
	if(n>1)
		res -= res/n;
 
	return res;
}

ll g(ll n)
{
	ll res = 0;

	for(ll i = 1; i*i <= n; ++i)
	{
		if(n%i==0)
		{
			res += f(i);

			if(i!=n/i)
				res += f(n/i);
		}
	}

	return res;
}

ll F(ll k, ll n)
{
	if(k==1)
		return f(g(n));

	if(k%2==0)
		return g(F(k-1, n));
	else
		return f(F(k-1, n));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	ll n, k;

	cin >> n >> k;

	if(k>85)
		cout << 1;
	else	
		cout << F(k, n)%MOD;
}