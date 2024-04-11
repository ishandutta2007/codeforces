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

#define N 50007

int n;

int a[N];

VI t[N];

int res[N];

set<int> S;

bool check(int k)
{
	S.clear();

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < t[i].size(); ++j)
		{
			if(S.find(t[i][j])==S.end() && t[i][j]<=k)
			{
				S.insert(t[i][j]);
				break;
			}
			else if(j==t[i].size()-1)
				return 0;
		}
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)																																										
	{
		cin >> a[i];																																																																																																																																																																												
	}

	sort(a+1, a+n+1, greater<int>());

	for(int i = 1; i <= n; ++i)
	{
		t[i].pb(a[i]);

		while(t[i].back()>1)
			t[i].pb(t[i].back()/2);
	}

	int l = 1, r = 1e9;

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

	check(l);

	for(auto it:S)
	{
		cout << it << " ";
	}
}