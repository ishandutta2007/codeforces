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

const int N = 1e6+7;
#define double long double

int n;

VI wyst[N];

double res;

ll licz(ll len)
{
	if(len==0)
		return 0;

	ll res = len*(len+1)/2;
	res -= len;
	res *= 2;
	res += len;
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		wyst[a].pb(i);
	}

	for(int i = 1; i < N; ++i)
	{
		if(wyst[i].empty())
			continue;

		ll ile = 0;
		ile += licz(wyst[i][0]-1);
		ile += licz(n-wyst[i].back());

		for(int j = 0; j+1 < wyst[i].size(); ++j)
		{
			ile += licz(wyst[i][j+1]-wyst[i][j]-1);
		}

		res += 1-(double)ile/n/n;
	}

	cout << fixed << setprecision(10) << res;
}