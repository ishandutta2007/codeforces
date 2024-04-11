#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 2e5+7;

int n, r;

int p[N];

VI G[N];

bitset<N> vis;

int deg[N];
int cnt[N];
int w_gore[N];

VI D[N];

queue<int> Q;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);

			if(w_gore[it])
			{
				D[v].pb(it);
				++cnt[v];
			}
			else
				D[it].pb(v);
		}
	}

	if(cnt[v]%2==0)
		w_gore[v] = 1;
	else
		++cnt[v];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	if(n==1)
	{
		cout << "YES" << endl << 1 << endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];

		if(p[i])
		{
			G[p[i]].pb(i);
			G[i].pb(p[i]);
		}
	}

	r = -1;

	for(int i = 1; i <= n; ++i)
	{
		if(G[i].size()%2==0)
			r = i;
	}	

	if(r==-1)
	{
		cout << "NO" << endl;
		return 0;
	}

	dfs(r);

	if(!w_gore[r])
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for(int i = 1; i <= n; ++i)
	{
		deg[i] = G[i].size();

		if(cnt[i]==deg[i])
			Q.push(i);
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		cout << v << endl;

		for(auto it:D[v])
		{
			--deg[it];

			if(deg[it]==cnt[it])
				Q.push(it);
		}
	}
}