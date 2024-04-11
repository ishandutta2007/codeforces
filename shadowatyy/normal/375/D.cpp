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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	
const int N = 1e5+7;

int n, m;

VI G[N];

int c[N];
int u[N];
int k[N];
int ans[N];
int sub[N];
int p[N];

VI Q[N];

map<int, int> M[N];
ordered_set<PII> S[N];

void dfs(int v)
{
	sub[v] = 1;
	PII h = mp(-1, -1);

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			p[it] = v;
			dfs(it);
			sub[v] += sub[it];
			h = max(h, mp(sub[it], it));
		}
	}

	if(h.nd!=-1)
	{
		M[v].swap(M[h.nd]);
		S[v].swap(S[h.nd]);

		for(auto it:G[v])
		{
			if(it!=p[v] && it!=h.nd)
			{
				for(auto ite:M[it])
				{
					if(M[v].find(ite.st)!=M[v].end())
						S[v].erase(mp(M[v][ite.st], ite.st));

					M[v][ite.st] += ite.nd;
					S[v].insert(mp(M[v][ite.st], ite.st));
				}
					
			}
		}
	}

	if(M[v].find(c[v])!=M[v].end())
		S[v].erase(mp(M[v][c[v]], c[v]));

	M[v][c[v]]++;
	S[v].insert(mp(M[v][c[v]], c[v]));

	for(auto i:Q[v])
	{
		auto it = S[v].lower_bound(mp(k[i], 0));

		if(it!=S[v].end())
			ans[i] = S[v].size()-S[v].order_of_key(*it);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> u[i] >> k[i];
		Q[u[i]].pb(i);
	}

	dfs(1);

	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << endl;
	}
}