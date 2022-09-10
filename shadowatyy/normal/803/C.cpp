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

ll n, k, res = -1;

bool check(ll g)
{
	if(n%g==0 && n/g>=k*(k+1)/2 && res<g)
		res = g;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	if(k>10e8)
	{
		cout << -1;
		return 0;
	}

	for(ll i = 1; i*i <= n; ++i)
	{
		if(n%i==0)
			check(i);

		if(n%i==0)
			check(n/i);
	}

	if(res==-1)
		cout << res;
	else
	{
		for(int i = 1; i < k; ++i)
		{
			cout << i*res << " ";
		}

		cout << (n/res-k*(k-1)/2)*res;
	}
}