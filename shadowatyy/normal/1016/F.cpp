#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 3e5+7;

int n, m, ans;

int dist1[N];
int distn[N];

VPII G[N];

map<int, VI> takie;

multiset<int, greater<int> > S;

bitset<N> vis;

void dfs(int v, int p, int* dep)
{
	for(auto it:G[v])
	{
		if(it.st!=p)
		{
			dep[it.st] = dep[v] + it.nd;
			dfs(it.st, v, dep);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	//dist(1, v)+dist(n, u)<=dist(1, u)+dist(n, v)
	//dist(1, v)-dist(n, v)<=dist(1, u)-dist(n, u)

	cin >> n >> m;

	for(int i = 1; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	dfs(1, -1, dist1);
	dfs(n, -1, distn);

	for(int i = 1; i <= n; ++i)
	{
		takie[dist1[i]-distn[i]].pb(i);
	}

	for(auto war:takie)
	{
		for(auto it:war.nd)
		{
			S.insert(dist1[it]);
			vis[it] = 1;
		}

		for(auto u:war.nd)
		{
			for(auto v:G[u])
			{
				if(vis[v.st])
					S.erase(S.find(dist1[v.st]));
			}

			S.erase(S.find(dist1[u]));

			ans = max(ans, S.empty()?-INF:*S.begin() + distn[u]);

			for(auto v:G[u])
			{
				if(vis[v.st])
					S.insert(dist1[v.st]);
			}

			S.insert(dist1[u]);
		}
	}

	while(m--)
	{
		int x;
		cin >> x;
		cout << min(ans+x, dist1[n]) << endl;
	}
}