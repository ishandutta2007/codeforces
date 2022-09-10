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

#define N 107

int n, w, sum;

int vol[N];

VI v;

bool comp(int a, int b)
{
	return vol[a]<vol[b];
}

int res[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> w;

	for(int i = 1; i <= n; ++i)
	{
		cin >> vol[i];
		v.pb(i);
	}

	sort(ALL(v), comp);

	for(auto it:v)
	{
		res[it] = (vol[it]+1)/2;
		sum += res[it];
	}	

	if(sum>w)
	{
		cout << -1;
		return 0;
	}

	w -= sum;

	while(w)
	{
		for(int i = n-1; i >= 0 && w; --i)
		{
			if(res[v[i]]<vol[v[i]])
			{
				++res[v[i]];
				--w;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}