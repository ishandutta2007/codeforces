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
const int M = 1<<18;

int n, m, cnt;

VI G[N];

int a[N];
int b[N];
int c[N];
int dp[N];
int pre[N];
int post[N];
int p[20][N];

VI que[N];

struct tree
{
	int load[2*M];

	void insert(int a, int b, int v)
	{
		a += M;
		b += M;

		load[a] += v;

		if(a!=b)
			load[b] += v;

		while(a<b-1)
		{
			if(a%2==0)
				load[a+1] += v;

			if(b%2==1)
				load[b-1] += v;

			a /= 2;
			b /= 2;
		}
	}

	int query(int a)
	{
		int res = 0;
		a += M;

		while(a)
		{
			res += load[a];
			a /= 2;
		}

		return res;
	}
};

tree dodaj, odejmij;

void dfs(int v)
{
	pre[v] = ++cnt;

	for(auto it:G[v])
	{
		p[0][it] = v;
		dfs(it);
	}

	post[v] = cnt;
}

int child(int a, int b)
{
	return pre[a]>=pre[b] && post[a]<=post[b]; 
}

int lca(int a, int b)
{
	if(child(a, b))
		return b;

	if(child(b, a))
		return a;

	int l = 19;

	while(l>=0)
	{
		if(child(a, p[l][b]))
			--l;
		else
			b = p[l][b];
	}

	return p[0][b];
}

void solve(int v)
{
	for(auto it:G[v])
	{
		solve(it);
		dp[v] += dp[it];
		dodaj.insert(pre[v], post[v], dp[it]);
	}

	for(auto i:que[v])
	{
		int curr = c[i]+dodaj.query(pre[a[i]])+dodaj.query(pre[b[i]])-dodaj.query(pre[v])-(v==1?0:dodaj.query(pre[p[0][v]]))
		-odejmij.query(pre[a[i]])-odejmij.query(pre[b[i]])+2*odejmij.query(pre[v]);
		dp[v] = max(dp[v], curr);
	}
			
	odejmij.insert(pre[v], post[v], dp[v]);
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		G[p].pb(i);
	}

	p[0][1] = 1;
	dfs(1);

	for(int l = 1; l < 20; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			p[l][i] = p[l-1][p[l-1][i]];
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		que[lca(a[i], b[i])].pb(i);
	}

	solve(1);
	cout << dp[1];
}