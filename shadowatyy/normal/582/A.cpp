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

const int N = 507;

int n, a;

map<int, int> ile;
map<int, int, greater<int> > res;

int pierw[N*N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		pierw[i*i] = i;
	}

	for(int i = 1; i <= n*n; ++i)
	{
		cin >> a;
		++ile[a];
		res[a] = 0;
	}

	for(auto it1:ile)
	{
		for(auto it2:ile)
		{
			if(it2.st>it1.st && it2.st%it1.st==0)
				ile[it1.st] += ile[it2.st];
		}
	}

	for(auto it1:res)
	{
		res[it1.st] = pierw[ile[it1.st]];

		for(auto it2:res)
		{
			if(it2.st>it1.st && it2.st%it1.st==0)
				res[it1.st] -= res[it2.st];
		}
	}

	for(auto it:res)
	{
		int curr = it.nd;

		while(curr--)
			cout << it.st << " ";
	}


}