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

int n, m, curr;

VPII G[N];

int c[N];

int ktora[N];
int x[N];
int pre[N];
 	
VI g;

void add(int val)
{
	for(auto it:g)
	{
		int b = 31-__builtin_clz(it);

		if(val&(1<<b))
			val ^= it;
	}

	if(!val)
		return;

	int b = 31-__builtin_clz(val);

	for(auto &it:g)
	{
		if(it&(1<<b))
			it ^= val;
	}

	g.pb(val);
}

void dfs(int v)
{
	pre[v] = ++curr;

	for(auto it:G[v])
	{
		if(!pre[it.st])
		{
			ktora[it.st] = it.nd;
			x[it.st] = x[v]^c[it.nd];
			dfs(it.st);
		}
		else if(it.nd!=ktora[v])
			add(c[it.nd]^x[v]^x[it.st]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b >> c[i];
		G[a].eb(b, i);
		G[b].eb(a, i);
	}

	dfs(1);

	int curr = x[n];

	sort(ALL(g));

	for(auto it:g)
	{
		curr = min(curr, curr^it);
	}

	cout << curr;
}