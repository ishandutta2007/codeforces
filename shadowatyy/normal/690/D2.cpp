#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define MOD 1000003

ll n, k, res;

ll fact[10000007];

ll pot(ll P, ll W)
{
	if(W==0)
		return 1;

	if(W==1)
		return P%MOD;

	if(W%2)
		return (P*pot(P, W-1))%MOD;

	ll X = pot(P, W/2);

	return (X*X)%MOD;
}

ll newton(ll N, ll K)
{
	ll RES = fact[N];

	RES = (RES*pot(fact[K], MOD-2))%MOD;

	RES = (RES*pot(fact[N-K], MOD-2))%MOD;

	return RES;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i <= 1000000; ++i)
	{
		fact[i] = (fact[i-1]*i)%MOD;
	}

	cin >> n >> k;

	for(int i = 1; i <= k; ++i)
	{
		res = (res+newton(n+i-1, i))%MOD;
	}

	cout << res;
}