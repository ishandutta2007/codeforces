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

#define N 107

int n, a, b, res;

int x[N];
int y[N];

bool miesci(int i, int a, int b)
{
	if(x[i]<=a && y[i]<=b)
		return 1;

	if(x[i]<=b && y[i]<=a)
		return 1;

	return 0;
}

bool check(int i, int j)
{
	if(!miesci(i, a, b))
		return 0;

	if(!miesci(j, a, b))
		return 0;

	if(y[i]<=b && miesci(j, a-x[i], b))
		return 1;

	if(x[i]<=b && miesci(j, a-y[i], b))
		return 1;

	if(y[i]<=a && miesci(j, a, b-x[i]))
		return 1;

	if(x[i]<=a && miesci(j, a, b-y[i]))
		return 1;

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];

		for(int j = i-1; j >= 1; --j)
		{
			if(check(i, j))
			{
				res = max(res, x[i]*y[i]+x[j]*y[j]);
			}
		}
	}

	cout << res;
}