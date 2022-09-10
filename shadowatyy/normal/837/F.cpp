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

#define N 200007

int n;

ll k;

int a[N];
bitset<N> any;

bool check(ll m)
{
	long double curr = 0, dwu = 1;
	ll cn = m;

	for(int i = n; i >= 1 && any[i]; --i)
	{
		if(a[i] && dwu>k/a[i]+1)
			return 1;

		curr += dwu*a[i];

		if(curr+0.5>=k)
			return 1;

		dwu /= cn-m+1;

		if(any[i-1] && dwu>k/(cn+1)+1)
			return 1;

		dwu *= cn+1;
		++cn;
	}

	return curr+0.5>=k;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i])
			any[i] = 1;

		if(any[i-1])
			any[i] = 1;

		if(a[i]>=k)
		{
			cout << 0;
			return 0;
		}
	}

	ll l = 0, r = 1e18;

	while(l<r)
	{
		ll m = (l+r)/2;

		if(r==m)
			--m;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	cout << l+1;
}