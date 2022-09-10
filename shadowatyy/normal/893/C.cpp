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

const int N = 1e5+7;

int n, m;

ll res;

int p[N];
int mini[N];

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

	p[a] = b;
	mini[b] = min(mini[b], mini[a]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> mini[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		p[i] = i;
	}

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for(int i = 1; i <= n; ++i)
	{
		int r = Find(i);

		if(r==i)
			res += mini[r];
	}

	cout << res;
}