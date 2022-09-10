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

#define int long long
#define N 107

int n, k, sum;

int a[N];

bool check(int ile)
{
	return 2*sum+2*ile*k>=(2*k-1)*(n+ile);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	int l = 0, r = 1e9;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--r;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	cout << l;
}