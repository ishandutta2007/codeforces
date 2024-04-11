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

const int N = 2e5+7;

int n;

ll res;

int a[N];

int maxi[N];

bitset<2*N> ok;

int ile[2*N];

VI len[N];

void solve(int d)
{
	memset(maxi, 0, sizeof maxi);

	for(int i = 0; i < n; ++i)
	{
		maxi[i%d] = max(maxi[i%d], a[i]);
	}

	ok.set();

	for(int i = 0; i < n; ++i)
	{
		if(maxi[i%d]>a[i])
			ok[i] = ok[i+n] = 0;
	}

	for(int i = 2*n-1; i >= 0; --i)
	{
		if(ok[i])
			ile[i] = ile[i+1]+1;
		else
			ile[i] = 0;
	}

	for(int i = 0; i < n; ++i)
	{
		ile[i] = min(ile[i], n-1);
		res += upper_bound(ALL(len[d]), ile[i])-len[d].begin();
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i < n; ++i)
	{
		len[__gcd(n, i)].pb(i);
	}

	for(int i = 1; i < n; ++i)
	{
		if(n%i==0)
			solve(i);
	}

	cout << res;
}