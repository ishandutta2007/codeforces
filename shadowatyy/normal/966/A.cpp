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

int n, m, cl, ce, v, q;

VI L, E;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> cl >> ce >> v;

	for(int i = 1; i <= cl; ++i)
	{
		int x;
		cin >> x;
		L.pb(x);
	}

	for(int i = 1; i <= ce; ++i)
	{
		int x;
		cin >> x;
		E.pb(x);
	}

	cin >> q;

	while(q--)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		if(x1>x2)
			swap(x1, x2);

		if(y1>y2)
			swap(y1, y2);

		if(y1==y2)
		{
			cout << abs(x1-x2) << endl;
			continue;
		}

		int res = inf;

		auto it = lower_bound(ALL(L), x1);

		if(it!=L.end())
		{
			res = min(res, abs(x1-*it)+abs(x2-*it)+abs(y1-y2));
		}

		if(it!=L.begin())
		{
			--it;
			res = min(res, abs(x1-*it)+abs(x2-*it)+abs(y1-y2));
		}

		it = lower_bound(ALL(E), x1);

		if(it!=E.end())
		{
			res = min(res, abs(x1-*it)+abs(x2-*it)+(abs(y1-y2)+v-1)/v);
		}

		if(it!=E.begin())
		{
			--it;
			res = min(res, abs(x1-*it)+abs(x2-*it)+(abs(y1-y2)+v-1)/v);
		}

		cout << res << endl;
	}
}