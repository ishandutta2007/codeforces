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

const int N = 1e5+7;

int n, ile;

int a[N];
int chce[N];

map<int, int> gdzie;

VI v;

VI res[N];

int p[N];

int Find(int a)
{
	if(p[a]!=a)
		p[a] = Find(p[a]);

	return p[a];
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a==b)
		return;

	p[a] = b;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		v.pb(a[i]);
		gdzie[a[i]] = i;
	}

	sort(ALL(v));

	for(int i = 0; i < n; ++i)
	{
		chce[gdzie[v[i]]] = i+1;
	}

	for(int i = 1; i <= n; ++i)
	{
		p[i] = i;
	}

	for(int i = 1; i <= n; ++i)
	{
		Union(i, chce[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		res[Find(i)].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!res[i].empty())
			++ile;
	}

	cout << ile << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(!res[i].empty())
		{
			cout << res[i].size() << " ";

			for(auto it:res[i])
				cout << it << " ";

			cout << endl;
		}
	}
}