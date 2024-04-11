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

int n, k, d, a, res;

VI v[N];
int pos[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= k; ++i)
	{
		cin >> d;

		while(d--)
		{
			cin >> a;
			v[i].pb(a);
			pos[a] = i;
		}
	}

	for(int i = 1; i < v[pos[1]].size(); ++i)
	{
		if(v[pos[1]][i]==i+1)
			res -= 2;
		else
			break;
	}

	for(int i = 1; i <= k; ++i)
	{
		res += v[i].size()+v[i].size()-1;
	}

	cout << res-1;

}