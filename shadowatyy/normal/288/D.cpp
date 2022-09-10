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

#define N 80007

int n, r;

ll res;

VI G[N];

int p[N];
ll sub[N];
ll sum[N];
ll dp1[N];
ll dp2[N];
ll dp1_syn[N];

void dfs1(int v)
{
	sub[v] = 1; 

	for(auto it:G[v])
	{
		if(!sub[it])
		{
			p[it] = v;
			dfs1(it);
			sub[v] += sub[it];
			sum[v] += sub[it]*(sub[it]-1)/2;
		}
	}

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			dp1_syn[v] += dp1[it];

			dp1[v] += dp1[it];
			dp1[v] -= (sub[it]-1)*(n-sub[it])*(n-sub[it]-1)/2;
			dp1[v] += (sub[it]-1)*(sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2);
			dp1[v] += sum[it]+sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2;	
		}
	}
}

void dfs2(int v, ll curr)
{
	dp2[v] = curr;

	for(auto it:G[v])
	{
		if(it!=p[v])
		{
			curr -= (n-sub[v])*sub[it]*(sub[it]-1)/2;
			curr += (n-sub[v])*sum[it];
			curr += sum[it]+sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2;

			curr += dp1[v];
			curr -= dp1[it];
			curr += (sub[it]-1)*(n-sub[it])*(n-sub[it]-1)/2;
			curr -= (sub[it]-1)*(sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2);
			curr -= sum[it]+sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2;	
			curr -= (sub[v]-sub[it]-1)*sub[it]*(sub[it]-1)/2;
			curr += (sub[v]-sub[it]-1)*sum[it];

			dfs2(it, curr);

			curr += (n-sub[v])*sub[it]*(sub[it]-1)/2;
			curr -= (n-sub[v])*sum[it];
			curr -= sum[it]+sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2;

			curr -= dp1[v];
			curr += dp1[it];
			curr -= (sub[it]-1)*(n-sub[it])*(n-sub[it]-1)/2;
			curr += (sub[it]-1)*(sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2);
			curr += sum[it]+sum[v]-sub[it]*(sub[it]-1)/2+(n-sub[v])*(n-sub[v]-1)/2;	
			curr += (sub[v]-sub[it]-1)*sub[it]*(sub[it]-1)/2;
			curr -= (sub[v]-sub[it]-1)*sum[it];

		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs1(1);
	dfs2(1, 0);
	
	for(int i = 1; i <= n; ++i)
	{
		res += dp1[i]+dp2[i];
	}

	cout << res/2;
}