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
using namespace std;

ll f, T, t0, a1, t1, p1, a2, t2, p2, res = INF;

void solve()
{
	for(ll i = 0; i <= f && i*t1 <= T; ++i)
	{
		ll cost = p1*((i+a1-1)/a1), czas = T-i*t1, rozmiar = f-i;

		if(rozmiar>0)
		{
			if(t2<t0)
			{
				if(t0*rozmiar<=czas)
					res = min(res, cost);
				else
				{
					ll licz = -(czas-rozmiar*t0);
					ll mian = -(t2-t0);
					ll x = (licz+mian-1)/mian;

					if(x<=rozmiar)
						res = min(res, cost+((x+a2-1)/a2)*p2);
				}
			}
			else
			{
				if(t0*rozmiar<=czas)
					res = min(res, cost);
			}
		}
		else
			res = min(res, cost);	
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> f >> T >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;

	solve();
	swap(t1, t2);
	swap(a1, a2);
	swap(p1, p2);
	solve();

	if(res==INF)
		cout << -1;
	else
		cout << res;
}