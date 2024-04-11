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

double n, h;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> h;

	for(int i = 1; i < n; ++i)
	{
		double l = 0, r = h;

		for(int j = 1; j <= 100; ++j)
		{
			double x = (l+r)/2;
			double p = x*x/h;

			if(p*n/i>h)
				r = x;
			else
				l = x;
		}

		cout << setprecision(20) << fixed << l << " ";
	}
}