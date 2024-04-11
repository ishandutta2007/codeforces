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

const int N = 3e5+7;

int n, m;

int d[N];	
int a[N];
int b[N];
int nr[N];

VI np;

VPII G[N];

int p[N];
int ans[N];

VI res;

void dfs(int v)
{
	for(auto it:G[v])
	{
		if(!p[it.st])
		{
			nr[it.st] = it.nd;
			p[it.st] = v;
			dfs(it.st);
		}
	}
}

void licz(int v)
{
	for(auto it:G[v])
	{
		if(p[it.st]==v && nr[it.st]==it.nd)
		{
			licz(it.st);
			ans[v] += ans[it.st];
		}
	}

	if(ans[v]%2)
		res.pb(nr[v]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> d[i];

		if(d[i]==1)
			np.pb(i);
	}

	if(np.size()%2)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(d[i]==-1)
			{
				np.pb(i);
				break;
			}
		}

		if(np.size()%2)
		{
			cout << -1;
			return 0;
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
		G[a[i]].eb(b[i], i);
		G[b[i]].eb(a[i], i);
	}

	p[1] = 1;
	dfs(1);

	for(int i = 0; i < np.size(); i += 2)
	{
		++ans[np[i]];
		++ans[np[i+1]];
	}

	licz(1);

	sort(ALL(res));

	cout << res.size() << endl;

	for(auto it:res)
		cout << it << endl;
}