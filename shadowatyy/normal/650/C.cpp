#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

const int N = 1e6+7;

int n, m;

int val[N];

VI wie[N];
VI kol[N];

int rep[N];

VI G[N];

int deg[N];
int dp[N];

queue<int> Q;

int Find(int a)
{
	if(rep[a]!=a)
		rep[a] = Find(rep[a]);

	return rep[a];
}

void Union(int a, int b)
{
	rep[Find(a)] = Find(b);
}

int nr(int y, int x)
{
	return (y-1)*m+x;
}

bool comp(int a, int b)
{
	return val[a]<val[b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int ind = nr(i, j);
			cin >> val[ind];
			wie[i].pb(ind);
			kol[j].pb(ind);
			rep[ind] = ind;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		sort(ALL(wie[i]), comp);

		for(int j = 0; j+1 < wie[i].size(); ++j)
		{
			if(val[wie[i][j]]==val[wie[i][j+1]])
				Union(wie[i][j], wie[i][j+1]);
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		sort(ALL(kol[i]), comp);

		for(int j = 0; j+1 < kol[i].size(); ++j)
		{
			if(val[kol[i][j]]==val[kol[i][j+1]])
				Union(kol[i][j], kol[i][j+1]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j+1 < wie[i].size(); ++j)
		{
			if(Find(wie[i][j])!=Find(wie[i][j+1]))
			{
				G[Find(wie[i][j])].pb(Find(wie[i][j+1]));
				++deg[Find(wie[i][j+1])];
				//cerr << Find(wie[i][j]) << " " << Find(wie[i][j+1]) << endl;
			}
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		for(int j = 0; j+1 < kol[i].size(); ++j)
		{
			if(Find(kol[i][j])!=Find(kol[i][j+1]))
			{
				G[Find(kol[i][j])].pb(Find(kol[i][j+1]));
				++deg[Find(kol[i][j+1])];
				//cerr << Find(kol[i][j]) << " " << Find(kol[i][j+1]) << endl;
			}
		}
	}

	for(int i = 1; i <= n*m; ++i)
	{
		if(!deg[i])
			Q.push(i);
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			dp[it] = max(dp[it], dp[v]+1);

			if(--deg[it]==0)
				Q.push(it);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cout << dp[Find(nr(i, j))]+1 << " ";
		}

		cout << endl;
	}
}