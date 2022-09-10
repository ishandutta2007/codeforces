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

#define N 1000007

int n, c, a, b;

VI L[N];
VI R[N];
int Lans[N];
int Rans[N];

int max_l[N];
int min_r[N];
int max_v[N];
int min_v[N];

string s;

void dfs(int v)
{
	max_l[v] = -inf;
	min_r[v] = inf;
	max_v[v] = min_v[v] = v;

	for(auto it:L[v])
	{
		dfs(it);
		max_l[v] = max(max_l[v], max_v[it]);
		min_v[v] = min(min_v[v], min_v[it]);
	}

	for(auto it:R[v])
	{
		dfs(it);
		min_r[v] = min(min_r[v], min_v[it]);
		min_v[v] = min(min_v[v], min_v[it]);
	}
}

bool ok(int a, int k, int b)
{	
	for(int i = a; i <= k; ++i)
	{
		for(auto it:R[i])
		{
			if(it>k)
				return 0;
		}

		for(auto it:L[i])
		{
			if(it>k)
				return 0;
		}
	}

	for(int i = k+1; i <= b; ++i)
	{
		for(auto it:R[i])
		{
			if(it<=k)
				return 0;
		}

		for(auto it:L[i])
		{
			if(it<=k)
				return 0;
		}
	}

	return 1;
}

bool build(int v, int a, int b)
{
	max_l[v] = max(max_l[v], a);
	min_r[v] = min(min_r[v], b+1);

	if(a==b)
		return 1;

	if(max_l[v]>min_r[v])
		return 0;

	for(int k = max_l[v]; k < min_r[v]; ++k)
	{
		if(ok(a+1, k, b))
		{
			if(a+1<=k)
			{
				Lans[v] = a+1;

				if(!build(a+1, a+1, k))
					return 0;
			}

			if(k+1<=b)
			{
				Rans[v] = k+1;

				if(!build(k+1, k+1, b))
					return 0;
			}

			return 1;
		}
	}

	return 0;
}

void read(int v)
{
	if(Lans[v])
		read(Lans[v]);

	cout << v << " ";

	if(Rans[v])
		read(Rans[v]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> c;

	while(c--)
	{
		cin >> a >> b >> s;

		if(a>=b)
		{
			cout << "IMPOSSIBLE";
			return 0;
		}

		if(s[0]=='R')
			R[a].pb(b);
		else
			L[a].pb(b);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!min_v[i])
			dfs(i);
	}

	if(!build(1, 1, n))
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	read(1);

}