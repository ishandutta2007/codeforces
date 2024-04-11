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

const int N = 2e5+7;

int m;

int a[N];
int b[N];

VI sb, val;

int res[N];

bool comp(int p, int q)
{
	return b[p]>b[q];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i];
		val.pb(a[i]);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		sb.pb(i);
	}

	sort(ALL(val));
	sort(ALL(sb), comp);

	for(int i = 0; i < m; ++i)
	{
		res[sb[i]] = val[i];
	}

	for(int i = 1; i <= m; ++i)
		cout << res[i] << " ";
}