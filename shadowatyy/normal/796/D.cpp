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

int n, k, d, u, res;

int vis[N];

queue<int> Q;

int a[N];
int b[N];

VI G[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> d;

	for(int i = 1; i <= k; ++i)
	{	
		cin >> u;

		if(!vis[u])
		{
			vis[u] = u;
			Q.push(u);
		}
	}

	for(int i = 1; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(!vis[it])
			{
				vis[it] = vis[v];
				Q.push(it);
			}
		}
	}	

	for(int i = 1; i < n; ++i)
	{
		if(vis[a[i]]!=vis[b[i]])
			++res;
	}

	cout << res << endl;

	for(int i = 1; i < n; ++i)
	{
		if(vis[a[i]]!=vis[b[i]])
			cout << i << " ";
	}
}