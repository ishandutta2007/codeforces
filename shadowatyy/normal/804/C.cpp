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

#define N 300007

int n, m, s, a, c, ans, b, Max = 1;

int res[N];

bitset<N> vis;

VI v[N], q;

VI G[N];

void solve()
{
	ans = 0;
	memset(res, 0, sizeof res);

	for(auto i:q)
	{
		for(auto it:v[i])
		{
			vis[res[it]] = 1;
		}

		c = 1;

		for(auto it:v[i])
		{
			if(res[it])
				continue;

			while(vis[c])
				++c;

			res[it] = c;
			vis[c] = 1;
		}

		for(auto it:v[i])
		{
			vis[res[it]] = 0;
		}

		ans = max(ans, c);
	}

	for(auto i:q)
	{
		for(auto it:v[i])
		{
			if(vis[res[it]])
				ans = inf;

			vis[res[it]] = 1;
		}

		for(auto it:v[i])
		{
			vis[res[it]] = 0;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s;
		Max = max(Max, s);

		while(s--)
		{
			cin >> a;
			v[i].pb(a);
		}

		q.pb(i);
	}

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	solve();

	srand(time(NULL));

	while(Max!=ans)
	{
		random_shuffle(ALL(q));
		solve();
	}

	cout << ans << endl;

	for(int i = 1; i <= m; ++i)
	{
		if(!res[i])
			res[i] = 1;

		cout << res[i] << " ";
	}
}