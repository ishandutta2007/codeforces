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

#define N 100007

int n, l, x, y, okx, oky;

int d[N];

set<int> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> l >> x >> y;

	for(int i = 1; i <= n; ++i)
	{
		cin >> d[i];
		S.insert(d[i]);
	}

	for(auto it:S)
	{
		if(S.find(it-y)!=S.end())
			oky = 1;

		if(S.find(it-x)!=S.end())
			okx = 1;
	}

	if(oky && okx)
		cout << 0;
	else if(!oky && okx)
		cout << 1 << endl << y;
	else if(oky && !okx)
		cout << 1 << endl << x;
	else
	{
		for(auto it:S)
		{
			if((S.find(it-x-y)!=S.end() || S.find(it-x+y)!=S.end()) && it-x>=0)
			{
				cout << 1 << endl << it-x;
				return 0;
			}	

			if((S.find(it+x-y)!=S.end() || S.find(it+x+y)!=S.end()) && it+x<=l)
			{
				cout << 1 << endl << it+x;
				return 0;
			}

			swap(x, y);

			if((S.find(it-x-y)!=S.end() || S.find(it-x+y)!=S.end()) && it-x>=0)
			{
				cout << 1 << endl << it-x;
				return 0;
			}	

			if((S.find(it+x-y)!=S.end() || S.find(it+x+y)!=S.end()) && it+x<=l)
			{
				cout << 1 << endl << it+x;
				return 0;
			}
		}

		cout << 2 << endl << x << " " << y;
	}
}