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

#define N 207
#define s 0
#define t (n+1)

int n, ans;

int a[N];

VI G[N];
VI sko[N];

bitset<N> vis;

VI res[N];

bool isPrime(int a)
{
	for(int i = 2; i*i <= a; ++i)
	{
		if(a%i==0)
			return 0;
	}

	return 1;
}

bool dfs(int v = s)
{
	if(v==t)
		return 1;

	vis[v] = 1;

	for(auto &it:G[v])
	{
		if(!vis[it] && dfs(it))
		{
			G[it].pb(v);
			swap(it, G[v].back());
			G[v].pop_back();
			return 1;
		}
	}

	return 0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]%2==0)
		{
			G[s].pb(i);
			G[s].pb(i);
		}
		else
		{		
			G[i].pb(t);
			G[i].pb(t);
		}

		for(int j = 1; j <= n; ++j)
		{
			if(a[i]%2==0 && isPrime(a[i]+a[j]))
				G[i].pb(j);
		}
	}

	int flow = 0;

	while(dfs())
	{
		++flow;
		vis.reset();
	}

	if(flow!=n)
	{
		cout << "Impossible";
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]%2==1)
		{
			for(auto it:G[i])
			{
				sko[it].pb(i);
				sko[i].pb(it);
			}
				
		}
	}

	vis.reset();

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			int curr = i;
			res[++ans].pb(curr);
			vis[curr] = 1;

			while(!vis[sko[curr][0]] || !vis[sko[curr][1]])
			{
				if(!vis[sko[curr][0]])
					curr = sko[curr][0];
				else
					curr = sko[curr][1];

				res[ans].pb(curr);
				vis[curr] = 1;
			}
		}
	}

	cout << ans << endl;

	for(int i = 1; i <= ans; ++i)
	{
		cout << res[i].size() << " ";

		for(auto it:res[i])
			cout << it << " ";

		cout << endl;
	}

}