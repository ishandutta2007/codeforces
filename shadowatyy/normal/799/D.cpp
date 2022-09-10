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

#define N 32000007ll
#define y1 xd

int a, b, h, w, n, res = inf, x1, y1, x2, y2;

bitset<N> ok;

int ext[N+7];

ll ilo;

bool check(int k)
{
	for(ll j = min(ilo, N); j >= 1; --j)
	{
		if(ok[j] && j*ext[k]<N)
			ok[j*ext[k]] = 1;
	}

	if(log10(ilo)+log10(ext[k])>15)
		return 1;

	ilo *= ext[k];

	for(int i = 1; i <= min(ilo, N); ++i)
	{
		if(ok[i])
		{
			if(i>=x1 && ilo/i>=y1)
				return 1;

			if(i>=y1 && ilo/i>=x1)
				return 1;
				
			if(i>=x2 && ilo/i>=y2)
				return 1;

			if(i>=y2 && ilo/i>=x2)
				return 1;
		}
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> h >> w >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> ext[i];
	}

	sort(ext, ext+n, greater<int>());

	if(a%h==0)
		x1 = a/h;
	else
		x1 = a/h+1;

	if(b%w==0)
		y1 = b/w;
	else
		y1 = b/w+1;

	swap(a, b);

	if(a%h==0)
		x2 = a/h;
	else
		x2 = a/h+1;

	if(b%w==0)
		y2 = b/w;
	else
		y2 = b/w+1;

	ilo = 1;
	ok[1] = 1;

	for(int i = 1; i <= min(ilo, N); ++i)
	{
		if(ok[i])
		{
			if(i>=x1 && ilo/i>=y1)
				res = 0;

			if(i>=y1 && ilo/i>=x1)
				res = 0;

			if(i>=x2 && ilo/i>=y2)
				res = 0;

			if(i>=y2 && ilo/i>=x2)
				res = 0;
		}
	}

	for(int i = 0; i < min(34, n); ++i)
	{
		if(check(i))
		{
			res = min(res, i+1);
			break;
		}
	}

	if(res==inf)
		cout << -1;
	else
		cout << res;
}