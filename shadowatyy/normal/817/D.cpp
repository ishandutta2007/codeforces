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
#define flush fflush(stdout)
using namespace std;

#define N 1000007
#define int long long

int n, res;

int a[N];

int l[N];
int r[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	r[n] = n+1;

	for(int i = n-1; i >= 1; --i)
	{
		int j = i+1;

		while(j<=n && mp(a[j], j)<=mp(a[i], i))
			j = r[j];

		r[i] = j;
	}

	l[1] = 0;

	for(int i = 2; i <= n; ++i)
	{
		int j = i-1;

		while(j>=1 && mp(a[j], j)<=mp(a[i], i))
			j = l[j];

		l[i] = j;
	}

	for(int i = 1; i <= n; ++i)
	{
		res += a[i]*(i-l[i])*(r[i]-i);
	}

	r[n] = n+1;

	for(int i = n-1; i >= 1; --i)
	{
		int j = i+1;

		while(j<=n && mp(a[j], j)>=mp(a[i], i))
			j = r[j];

		r[i] = j;
	}

	l[1] = 0;

	for(int i = 2; i <= n; ++i)
	{
		int j = i-1;

		while(j>=1 && mp(a[j], j)>=mp(a[i], i))
			j = l[j];

		l[i] = j;
	}

	for(int i = 1; i <= n; ++i)
	{
		res -= a[i]*(i-l[i])*(r[i]-i);
	}

	cout << res;
}