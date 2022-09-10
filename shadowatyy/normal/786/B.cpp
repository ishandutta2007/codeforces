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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define M (1<<17)

int n, q, s, t, v, u, w, l, r;

VPII G[5*M];

ll dist[5*M];

void build()
{
	//2

	for(int i = 1; i < M; ++i)
	{
		G[M+i].eb(M+i*2, 0);
		G[M+i].eb(M+i*2+1, 0);
	}

	for(int i = M; i < 2*M; ++i)
	{
		G[M+i].eb(i-M, 0);
	}

	//3 

	for(int i = 1; i < M; ++i)
	{
		G[3*M+i*2].eb(3*M+i, 0);
		G[3*M+i*2+1].eb(3*M+i, 0);
	}

	for(int i = M; i < 2*M; ++i)
	{
		G[i-M].eb(3*M+i, 0);
	}
}

void add2(int v, int a, int b, int w)
{
	a += M;
	b += M;

	G[v].eb(M+a, w);

	if(a!=b)
		G[v].eb(M+b, w);

	while(a<b-1)
	{
		if(a%2==0)
			G[v].eb(M+a+1, w);
		
		if(b%2==1)
			G[v].eb(M+b-1, w);

		a /= 2;
		b /= 2;
	}
}

void add3(int v, int a, int b, int w)
{
	a += M;
	b += M;

	G[3*M+a].eb(v, w);

	if(a!=b)
		G[3*M+b].eb(v, w);

	while(a<b-1)
	{
		if(a%2==0)
			G[3*M+a+1].eb(v, w);
		
		if(b%2==1)
			G[3*M+b-1].eb(v, w);

		a /= 2;
		b /= 2;
	}
}

struct comp
{
	bool operator()(int a, int b)
	{
		if(dist[a]==dist[b])
			return a<b;

		return dist[a]<dist[b];
	}
};

set<int, comp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q >> s;

	while(q--)
	{
		cin >> t;

		if(t==1)
		{
			cin >> v >> u >> w;
			G[v].eb(u, w);
		}
		else if(t==2)
		{	
			cin >> v >> l >> r >> w;
			add2(v, l, r, w);	
		}
		else if(t==3)
		{
			cin >> v >> l >> r >> w;
			add3(v, l, r, w);
		}
	}

	build();

	for(int i = 1; i < 5*M; ++i)
	{
		dist[i] = INF;
	}

	dist[s] = 0;
	S.insert(s);

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(auto it:G[v])
		{
			if(dist[it.st]>dist[v]+it.nd)
			{
				dist[it.st] = dist[v]+it.nd;
				S.insert(it.st);
			}
		}
	}	

	for(int i = 1; i <= n; ++i)
	{
		if(dist[i]==INF)
			cout << -1 << " ";
		else
			cout << dist[i] << " ";
	}
}