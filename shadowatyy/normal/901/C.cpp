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

#define int long long
const int M = 1<<19;
const int N = 3e5+7;

int n, m, q, c, x;

int Min[2*M];
int Max[2*M];

int gdzie[N];
int p[N];
int pre[N];

VI G[N];

VPII cykle;

int moge[N];

ll sum[2*M];
int cnt[2*M];

int l[N];
int r[N];
VI Q[N];

VI teraz[N];

ll res[N];

void insert(int a, int v)
{
	a += M;
	Min[a] = Max[a] = v;
	a /= 2;

	while(a)
	{
		Min[a] = min(Min[2*a], Min[2*a+1]);
		Max[a] = max(Max[2*a], Max[2*a+1]);
		a /= 2;
	}
}

PII query(int a, int b)
{
	a += M;
	b += M;

	int rMin = min(Min[a], Min[b]), rMax = max(Max[a], Max[b]);

	while(a<b-1)
	{
		if(a%2==0)
		{
			rMin = min(rMin, Min[a+1]);
			rMax = max(rMax, Max[a+1]);
		}

		if(b%2==1)
		{
			rMin = min(rMin, Min[b-1]);
			rMax = max(rMax, Max[b-1]);
		}

		a /= 2;
		b /= 2;
	}

	return mp(rMin, rMax);
}

void dodaj(int a, int v)
{		
	a += M;
	
	while(a)
	{
		sum[a] += v;
		++cnt[a];
		a /= 2;
	}
}

int pytaj(int a, int b)
{
	int chce = b-a+1, k = b;

	a += M;
	b += M;

	ll res = sum[a], ile = cnt[a];

	if(a!=b)
	{
		res += sum[b];
		ile += cnt[b];
	}

	while(a<b-1)
	{
		if(a%2==0)
		{
			res += sum[a+1];
			ile += cnt[a+1];
		}

		if(b%2==1)
		{
			res += sum[b-1];
			ile += cnt[b-1];
		}

		a /= 2;
		b /= 2;
	}

	return res+(chce-ile)*k;
}

void dfs(int v)
{
	pre[v] = ++c;
	gdzie[v] = ++x;
	insert(gdzie[v], v);

	for(auto it:G[v])
	{
		if(!pre[it])
		{
			p[it] = v;
			dfs(it);
		}
		else if(it!=p[v] && pre[it]<pre[v])
			cykle.pb(query(gdzie[it], gdzie[v]));
	}

	--x;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	cin >> q;

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> r[i];
		Q[r[i]].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!pre[i])
			dfs(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		moge[i] = n;
	}

	for(auto it:cykle)
	{
		moge[it.st] = min(moge[it.st], it.nd-1);
	}

	for(int i = n-1; i >= 1; --i)
	{
		moge[i] = min(moge[i], moge[i+1]);
	}

	for(int i = 1; i <= n; ++i)
	{
		teraz[moge[i]].pb(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:teraz[i])
			dodaj(it, i);
		
		for(auto it:Q[i])
			res[it] = pytaj(l[it], r[it]);
	}

	for(int i = 1; i <= q; ++i)
	{
		res[i] -= (ll)r[i]*(r[i]-1)/2;
		res[i] += (ll)(l[i]-1)*(l[i]-2)/2;

		cout << res[i] << endl;
	}
}