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

const int N = 2007;

int n, cnt, res = inf;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i]>1)
			++cnt;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==1)
			res = 1;

		int g = a[i];

		for(int j = i+1; j <= n; ++j)
		{
			g = __gcd(g, a[j]);

			if(g==1)
				res = min(res, j-i+1);
		}
	}

	if(res==inf)
		cout << -1;
	else if(res==1)
		cout << cnt;
	else
		cout << cnt+res-2;
}