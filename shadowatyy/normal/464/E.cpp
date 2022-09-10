//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

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

const int mod = 1e9+7;
const int N = 1<<17;

int n, m, s, t;

VPII G[N];

ll pot[N];

struct node
{
	node* L = NULL;
	node* R = NULL;
	int hasz = 0;
	int zero = inf;

	/*node(){};

	node(node *u)
	{
		L = u->L;
		R = u->R;
		hasz = u->hasz;
	}*/
};

node* j[2*N];
node* z[2*N];
node* dist[N];
int skad[N];

void build(int ind = 1, int l = 0, int r = N-1)
{	
	z[ind] = new node();
	j[ind] = new node();

	if(l==r)
	{
		z[ind]->zero = l;
		j[ind]->hasz = 1;
		return;
	}

	build(ind<<1, l, (l+r)/2);
	build((ind<<1)+1, (l+r)/2+1, r);
	z[ind]->L = z[ind<<1];
	z[ind]->R = z[(ind<<1)+1];
	j[ind]->L = j[ind<<1];
	j[ind]->R = j[(ind<<1)+1];
	j[ind]->hasz = (j[ind<<1]->hasz + j[(ind<<1)+1]->hasz * pot[(r-l+1)>>1]) % mod;
	z[ind]->zero = min(z[ind<<1]->zero, z[(ind<<1)+1]->zero);
}

node* insert(int a, int b, int c, node* v, int ind = 1, int l = 0, int r = N-1)
{
	if(a>r || l>b)
		return v;

	if(a<=l && r<=b)
	{
		if(c)
			return j[ind];
		else
			return z[ind];
	}

	node* u = new node();
	u->L = insert(a, b, c, v->L, ind<<1, l, (l+r)>>1);
	u->R = insert(a, b, c, v->R, (ind<<1)+1, ((l+r)>>1)+1, r);
	u->hasz = (u->L->hasz + u->R->hasz * pot[(r-l+1)>>1]) % mod;
	u->zero = min(u->L->zero, u->R->zero);
	return u;
}

inline int lower_bound(int a, node* v, int l = 0, int r = N-1)
{
	if(r<a)
		return inf;

	if(a<=l)
		return v->zero;

	return min(lower_bound(a, v->L, l, (l+r)>>1), lower_bound(a, v->R, ((l+r)>>1)+1, r));
}

inline int comp(node* u, node* v, int l = 0, int r = N-1)
{	
	if(u->hasz == v->hasz)
		return 0;

	if(l==r)
	{
		if(u->hasz < v->hasz)
			return -1;
		else
			return 1;
	}

	if(u->R->hasz == v->R->hasz)
		return comp(u->L, v->L, l, (l+r)>>1);
	else
		return comp(u->R, v->R, ((l+r)>>1)+1, r);
}

struct cmp
{
	inline bool operator()(const int &a, const int &b)
	{
		int x = comp(dist[a], dist[b]);

		if(x==-1)
			return 1;
		else if(x==1)
			return 0;
		else
			return a<b;
	}	
};

set<int, cmp> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	pot[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		pot[i] = 2*pot[i-1]%mod;
	}

	build();

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		int u, v, x;
		cin >> u >> v >> x;
		G[u].eb(v, x);
		G[v].eb(u, x);
	}

	cin >> s >> t;

	for(int i = 1; i <= n; ++i)
	{
		dist[i] = j[1];
	}

	dist[s] = z[1];
	S.insert(s);

	while(!S.empty())
	{
		int v = *S.begin();
		S.erase(S.begin());

		for(auto it:G[v])
		{
			int l = lower_bound(it.nd, dist[v]);
			node* foo = insert(it.nd, l-1, 0, dist[v]);
			foo = insert(l, l, 1, foo);

			if(comp(foo, dist[it.st])==-1)
			{
				skad[it.st] = v;
				S.erase(it.st);
				dist[it.st] = foo;
				S.insert(it.st);
			}
		}
	}

	if(dist[t]==j[1])
		cout << -1 << endl;
	else
	{
		cout << dist[t]->hasz << endl;

		int curr = t;
		VI path;

		while(curr)
		{
			path.pb(curr);
			curr = skad[curr];
		}

		reverse(ALL(path));
		cout << path.size() << endl;

		for(auto it:path)
			cout << it << " ";

		cout << endl;
	}
}