#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 200007

int n, m, k, a, b, d;

VI G[N];

VI eul;

bitset<N> vis;

void dfs(int v)
{
	eul.pb(v);

	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);
			eul.pb(v);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	while(d*k<eul.size())
		++d;

	int pos = 0, c = -1;

	for(int i = 1; i <= k; ++i)
	{
		c = min(d, (int)eul.size()-pos);

		if(c==0)
			cout << "1 1\n";
		else
		{
			cout << c << " ";

			while(c--)
				cout << eul[pos++] << " ";

			cout << endl;
		}
	}
}