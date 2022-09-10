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

int n, k, cnt;

int p[17];

VI v1, v2;

void go(ll curr, int ind, int tar, VI &v)
{
	if(ind==tar+1)
	{
		v.pb(curr);
		return;
	}
		
	go(curr, ind+1, tar, v);

	if(curr<=INF/p[ind])
		go(curr*p[ind], ind, tar, v);
}

int check(int x)
{
	int ans = 0;

	for(auto it:v1)
	{
		ans += upper_bound(ALL(v2), x/it)-v2.begin();
	}

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	cin >> k;

	go(1, 1, min(5ll, n), v1);
	
	if(n<=5)
		v2.pb(1);
	else
		go(1, 6, n, v2);
	
	sort(ALL(v1));
	sort(ALL(v2));

	int l = 1, r = 1e18;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--m;

		if(check(m)>=k)
			r = m;
		else
			l = m+1;
	}

	cout << l;
}