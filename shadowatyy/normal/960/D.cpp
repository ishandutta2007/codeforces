#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

#define int long long

int q;

int ile[67];

void shift(int lvl, int k)
{
	for(int i = lvl; i <= 60; ++i)
	{
		k %= 1ll<<i;
		ile[i] += k;
		ile[i] %= 1ll<<i;
		k *= 2;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> q;

	while(q--)
	{
		int t;
		cin >> t;

		if(t==1)
		{
			int x, k;
			cin >> x >> k;
			int lvl = 63-__builtin_clzll(x);
			shift(lvl, k);
			shift(lvl+1, -2*k);
		}
		else if(t==2)
		{
			int x, k;
			cin >> x >> k;
			int lvl = 63-__builtin_clzll(x);
			shift(lvl, k);
		}
		else if(t==3)
		{
			int x;
			cin >> x;
			int lvl = 63-__builtin_clzll(x);

			while(x>1)
			{
				cout << x << " ";

				x += ile[lvl];

				while(x<(1ll<<lvl))
					x += 1ll<<lvl;

				while(x>=2*(1ll<<lvl))
					x -= 1ll<<lvl;

				x /= 2;
				--lvl;
				x -= ile[lvl];

				while(x<(1ll<<lvl))
					x += 1ll<<lvl;

				while(x>=2*(1ll<<lvl))
					x -= 1ll<<lvl;
			}

			cout << x << endl;
		}
	}
}