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
using namespace std;

int a[24];
int c[24];

bool check()
{
	for(int i = 0; i < 6; ++i)
	{
		if(c[4*i+0]!=c[4*i+1] || c[4*i+1]!=c[4*i+2] || c[4*i+2]!=c[4*i+3])
			return 0;
	}

	return 1;
}

int d[][8] =
{
	{22, 21, 18, 17, 6, 5, 14, 13},
	{3, 4, 17, 19, 10, 9, 16, 14},
	{7, 8, 19, 20, 23, 24, 15, 16},
	{1, 3, 5, 7, 9, 11, 24, 22},
	{4, 2, 21, 23, 12, 10, 8, 6},
	{2, 1, 13, 15, 11, 12, 20, 18}
};

bool solve(int k)
{
	for(int i = 0; i < 24; ++i)
	{
		c[i] = a[i];
	}

	VI curr;

	for(int i = 0; i < 8; ++i)
	{
		curr.pb(a[d[k][i]-1]);
	}

	curr.insert(curr.begin(), ALL(curr));

	for(int i = 0; i < 8; ++i)
	{
		c[d[k][i]-1] = curr[i+2];
	}

	if(check())
		return 1;

	curr.clear();

	for(int i = 0; i < 8; ++i)
	{
		curr.pb(a[d[k][i]-1]);
	}

	curr.insert(curr.begin(), ALL(curr));

	for(int i = 0; i < 8; ++i)
	{
		c[d[k][i]-1] = curr[i+6];
	}

	if(check())
		return 1;

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < 24; ++i)
	{
		cin >> a[i];
	}

	for(int i = 0; i < 6; ++i)
	{
		if(solve(i))
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}