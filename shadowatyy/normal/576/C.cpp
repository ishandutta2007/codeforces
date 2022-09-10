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

#define N 1000007
#define S 850

int n;

int x[N];
int y[N];

VI res;

bool comp(int a, int b)
{
	if(x[a]/S==x[b]/S)
	{
		if((x[a]/S)%2)
			return y[a]<y[b];
		else
			return y[a]>y[b];
	}
	else
		return x[a]/S<x[b]/S;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
		res.pb(i);
	}

	sort(ALL(res), comp);

	for(auto it:res)
		cout << it << " ";
}