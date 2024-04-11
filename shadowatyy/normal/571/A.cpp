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

ll res;

ll a, b, c, l;

void odejmij()
{
	for(ll x = 0; x <= l; ++x)
	{
		ll y = min(l-x, c+x-a-b);

		if(y>=0)
			res -= (y+1)*(y+2)/2;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> c >> l;

	odejmij();
	swap(a, c);
	odejmij();
	swap(a, c);
	swap(b, c);
	odejmij();
	swap(b, c);

	for(ll i = 0; i <= l; ++i)
	{
		res += (i+2)*(i+1)/2;
	}

	cout << res;
}