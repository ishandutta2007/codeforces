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

ll a, b, res;

vector<ll> divs;

ll gcd(ll a, ll b)
{
	if(a>b)
		swap(a, b);

	if(a==0)
		return b;

	return gcd(a, b%a);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b;

	for(ll i = 1; i*i <= a; ++i)
	{
		if(a%i==0)
		{
			divs.pb(i);
			divs.pb(a/i);
		}
	}

	sort(ALL(divs));
	divs.erase(unique(ALL(divs)), divs.end());

	ll g = gcd(a, b);

	int curr = -1;

	for(int i = 0; i < divs.size(); ++i)
	{
		if(divs[i]==g)
			curr = i;
	}

	while(b)
	{
		int nast = -1;

		for(int i = (int)divs.size()-1; i > curr; --i)
		{
			if((b%divs[i])%divs[curr]==0 && (nast==-1 || (b%divs[i])/divs[curr]<(b%divs[nast])/divs[curr]))
			{
				nast = i;
			}
		}

		if(nast==-1)
		{
			res += b/divs[curr];
			b = 0;
		}
		else
		{
			res += (b%divs[nast])/divs[curr];
			b -= b%divs[nast];
			curr = nast;
		}
	}

	cout << res;
}