#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 200007
#define M (1<<18)

int n, a, c;

vector<PII> G[N];

ll dist[N];

int pre[N];

int maxpre[N];

int load[2*M];

int res[N];

int A[N];

VI odl; //sort po dist[v]
VI roz; //sort po dist[v]-a[v]

void insert(int a)
{	
	a += M;

	while(a>=1)
	{
		++load[a];
		a /= 2;
	}
}

int query(int a, int b)
{
	a += M;
	b += M;

	int res = 0;

	res += load[a];

	if(a!=b)
		res += load[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1];

		if(b%2==1)
			res += load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

void dfs(int v)
{
	pre[v] = maxpre[v] = ++c;

	for(int i = 0; i < G[v].size(); ++i)
	{
		dist[G[v][i].st] = dist[v]+G[v][i].nd;
		dfs(G[v][i].st);
		maxpre[v] = max(maxpre[v], maxpre[G[v][i].st]);
	}
}

bool compodl(int a, int b)
{
	return dist[a]<dist[b];
}

bool comproz(int a, int b)
{
	return dist[a]-A[a]<dist[b]-A[b];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> A[i];
	}

	for(int i = 2; i <= n; ++i)
	{
		cin >> a >> c;

		G[a].eb(i, c);
	}

	c = 0;

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		odl.pb(i);
		roz.pb(i);
	}

	sort(odl.begin(), odl.end(), compodl);
	sort(roz.begin(), roz.end(), comproz);

	for(int o = 0, r = 0; o < n; ++o)
	{
		while(r<n && dist[roz[r]]-A[roz[r]]<=dist[odl[o]])
		{
			insert(pre[roz[r]]);
			++r;
		}

		res[odl[o]] = query(pre[odl[o]], maxpre[odl[o]])-1;
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
	
}