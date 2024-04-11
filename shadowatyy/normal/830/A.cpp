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

#define int long long
#define N 2007

int n, k, p;

int a[N];
int b[N]; 

bitset<N> used;

bool check(int d)
{
	used.reset();

	for(int i = 1; i <= n; ++i)
	{
		bool ok = 0;

		for(int j = 1; j <= k; ++j)
		{
			if(!used[j] && max(a[i]-b[j], b[j]-a[i])+max(p-b[j], b[j]-p)<=d)
			{
				used[j] = 1;
				ok = 1;
				break;
			}
		}

		if(!ok)
			return 0;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> p;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= k; ++i)
	{
		cin >> b[i];
	}

	sort(a+1, a+1+n);
	sort(b+1, b+1+k);

	int l = 0, r = 2*inf;

	while(l<r)
	{
		int m = (l+r)/2;

		if(m==r)
			--m;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	cout << l;
}