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
#define flush fflush(stdout)
using namespace std;

#define N 1007
#define M 10007

int n, m, s, t, c;

ll l;

VI G[N];

ll w[N][N];

int a[M];
int b[M];

ll distS[N];
ll distT[N];

struct cmpS
{
	bool operator()(int a, int b)
	{
		return mp(distS[a], a)<mp(distS[b], b);
	}
};

struct cmpT
{
	bool operator()(int a, int b)
	{
		return mp(distT[a], a)<mp(distT[b], b);
	}
};

set<int, cmpS> S;
set<int, cmpT> T;

void relaksuj()
{
	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(auto it:G[v])
		{
			if(distS[it]>distS[v]+w[v][it])
			{
				distS[it] = distS[v]+w[v][it];
				S.insert(it);
			}
		}
	}

	while(!T.empty())
	{
		int v = *T.begin();
		T.erase(T.begin());

		for(auto it:G[v])
		{
			if(distT[it]>distT[v]+w[v][it])
			{
				distT[it] = distT[v]+w[v][it];
				T.insert(it);
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> l >> s >> t;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> c;

		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);

		w[a[i]][b[i]] = w[b[i]][a[i]] = (c?c:inf);
	}

	for(int i = 0; i < n; ++i)
	{
		distS[i] = distT[i] = INF;
	}

	distS[s] = 0;
	distT[t] = 0;

	S.insert(s);
	T.insert(t);

	relaksuj();

	for(int i = 1; i <= m; ++i)
	{
		if(w[a[i]][b[i]]==inf)
		{
			w[a[i]][b[i]] = w[b[i]][a[i]] = max(1ll, l-min(distS[a[i]]+distT[b[i]], distT[a[i]]+distS[b[i]]));
			S.insert(a[i]);
			S.insert(b[i]);
			T.insert(a[i]);
			T.insert(b[i]);
			relaksuj();
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		if(w[a[i]][b[i]]<1)
		{
			cout << "NO";
			return 0;
		}
	}

	if(distS[t]!=l)
	{
		cout << "NO";
		return 0;
	}
		
	cout << "YES" << endl;

	for(int i = 1; i <= m; ++i)
	{
		cout << a[i] << " " << b[i] << " " << w[a[i]][b[i]] << endl;
	}
}