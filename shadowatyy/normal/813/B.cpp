#include <bits/stdc++.h>
#include <unistd.h>
#define int long long
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
#define flush fflush(stdout)
using namespace std;

int x, y, l, r, res;

VI v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> x >> y >> l >> r;

	for(int i = 1; i <= r; i *= x)
	{
		for(int j = 1; j <= r; j *= y)
		{
			v.pb(i+j);

			if(j>r/y+1)
				break;
		}

		if(i>r/x+1)
			break;
	}

	v.pb(l-1);
	v.pb(r+1);
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());

	for(int i = 0; i < v.size()-1; ++i)
	{
		int a = v[i]+1;
		int b = v[i+1]-1;

		a = max(a, l);
		b = min(b, r);

		res = max(res, b-a+1);
	}

	cout << res;
}