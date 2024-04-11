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
const int MOD = 1e9+7;

int n;

ll res = 1;

VI G[N];

VI curr;

bool to_samo[N];

bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;
	curr.pb(v);

	for(auto it:G[v])
	{
		if(!vis[it])
			dfs(it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);

		if(a==b)
			to_samo[a] = 1;
	}

	for(int i = 1; i <= 2*n; ++i)
	{
		if(!vis[i])
		{
			curr.clear();
			dfs(i);

			int e = 0;

			for(auto it:curr)
				e += G[it].size();

			e /= 2;

			if(e+1==curr.size())
				res = (res*curr.size())%MOD;
			else
			{
				bool petla = 0;

				for(auto it:curr)
				{
					if(to_samo[it])
						petla = 1;
				}

				if(!petla)
					res = (res*2)%MOD;
			}
		}	
	}

	cout << res;
}