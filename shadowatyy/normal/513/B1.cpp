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

ll n, m, p, s;

ll res[57];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;
	--m;
	p = 1;
	s = n;

	for(int i = 1; i <= n; ++i)
	{
		if(m-(1ll<<(n-i-1))>=0)
		{
			res[s--] = i;
			m -= (1ll<<(n-i-1));
		}
		else
			res[p++] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}

}