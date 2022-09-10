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

#define N 107

ll n, k;

ll sum_ile, cost, curr = 1, ans = 1;

int a[N];
int ile[N];

map<ll, VI> M;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		ile[i] = a[i];
		sum_ile += ile[i];

		int last = -1, last_div = 0;

		for(int j = 1; j*j <= a[i]; ++j)
		{
			M[j].pb(i);
			last_div = j;
			last = (a[i]+j-1)/j;
		}

		while(last!=1)
		{
			int l = last_div+1, r = a[i];

			while(l<r)
			{
				int m = (l+r)/2;

				if(r==m)
					--m;

				if((a[i]+m-1)/m!=last)
					r = m;
				else
					l = m+1;
			}

			last_div = l;
			last = (a[i]+l-1)/l;

			if(last_div!=1)
				M[last_div].pb(i);
		}
	}

	M[1e12].pb(-1);
	M[1e12].pop_back();

	for(auto itm:M)
	{
		ll l = curr, r = itm.st-1;

		while(l<r)
		{
			ll m = (l+r)/2;

			if(m==l)
				++m;

			if(cost+sum_ile*(m-curr)<=k)
				l = m;
			else
				r = m-1;
		}

		if(cost+sum_ile*(l-curr)<=k)
			ans = max(ans, l);

		cost += (itm.st-curr)*sum_ile;

		curr = itm.st;

		for(auto it:itm.nd)
		{
			cost -= curr*ile[it]-a[it];
			sum_ile -= ile[it];
			ile[it] = (a[it]+curr-1)/curr;
			sum_ile += ile[it];
			cost += curr*ile[it]-a[it];
		}
	}	

	cout << ans;
}