#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

const int N = 1e5+7;

int n, q;

ll maxW, last;

int a[N];
int b[N];
ll weight[N];

vector<pair<int, ll> > G[N];

VI curr;

bitset<N> ban, vis;
int sub[N];
int maxSub[N];
multiset<ll, greater<ll> > maxFromSubs[N], maxFromCentros;
set<PII> chooseSon[N];
ll dep[N];
VI centroSons[N];
int centroOnLvl[N];
int par[N];

struct tree
{	
	int s;
	VI nodes;
	vector<ll> load, sub;
	unordered_map<int, int> pre, post;

	void build()
	{
		while(__builtin_popcount(siz(nodes))>1)
			nodes.pb(-1);

		s = siz(nodes);
		load.assign(2*s, 0);
		sub.assign(2*s, 0);
	}

	ll query(int a, int b, int v, int l, int r)
	{
		if(a>r || l>b)
			return -INF;

		if(a<=l && r<=b)
			return sub[v];

		return load[v] + max(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
	}

	void insert(int a, int b, ll war, int v, int l, int r)
	{
		if(a>r || l>b)
			return;

		if(a<=l && r<=b)
		{
			sub[v] += war;
			load[v] += war;
			return;
		}

		insert(a, b, war, 2*v, l, (l+r)/2);
		insert(a, b, war, 2*v+1, (l+r)/2+1, r);
		sub[v] = load[v] + max(sub[2*v], sub[2*v+1]);
	}
};

tree itsTree[N];

void dfs1(int v)
{
	vis[v] = 1;
	sub[v] = 1;
	maxSub[v] = 0;
	curr.pb(v);

	for(auto it:G[v])
	{
		int u = it.st;

		if(!vis[u] && !ban[u])
		{
			dfs1(u);
			sub[v] += sub[u];
			maxi(maxSub[v], sub[u]);
		}
	}
}

void clearVis()
{
	for(auto it:curr)
		vis[it] = 0;
}

void clearCurr()
{
	for(auto it:curr)
	{
		vis[it] = 0;
		dep[it] = 0;
	}

	curr.clear();
}

void dfs2(int v, int centro)
{
	auto drze = &itsTree[centro];
	drze->pre[v] = siz(drze->nodes);
	drze->nodes.pb(v);
	vis[v] = 1;

	for(auto it:G[v])
	{
		int u = it.st;
		ll w = it.nd;

		if(!vis[u] && !ban[u])
		{
			dep[u] = dep[v] + w;
			dfs2(u, centro);
		}
	}

	drze->post[v] = siz(drze->nodes)-1;
}

int decompo(int v, int lvl = 0)
{
	dfs1(v);

	for(auto &it:curr)
	{
		maxi(maxSub[it], siz(curr) - sub[it]);

		if(maxSub[it]<maxSub[curr[0]])
			swap(it, curr[0]);
	}

	int centro = curr[0];
	centroOnLvl[centro] = lvl;
	ban[centro] = 1;
	clearVis();
	dfs2(centro, centro);
	auto drze = &itsTree[centro];
	drze->build();	

	for(auto v:curr)
		drze->insert(drze->pre[v], drze->pre[v], dep[v], 1, 0, drze->s - 1);

	for(auto it:G[centro])
	{
		int u = it.st;

		if(!ban[u])
		{
			centroSons[centro].pb(u);
			int preU = drze->pre[u];
			int postU = drze->post[u];
			maxFromSubs[centro].insert(drze->query(preU, postU, 1, 0, drze->s - 1));
			//debug(preU, postU, drze->query(preU, postU, 1, 0, drze->s - 1), dep[u]);
			chooseSon[centro].emplace(drze->post[u], u);
		}
	}

	maxFromSubs[centro].insert(0);
	maxFromSubs[centro].insert(0);
	ll currTwo = *maxFromSubs[centro].begin() + *next(maxFromSubs[centro].begin());
	maxFromCentros.insert(currTwo);
	clearCurr();

	for(auto u:centroSons[centro])
	{
		par[decompo(u, lvl+1)] = centro;
	}

	return centro;
}

void updateCentro(int centro, int a, int b, ll change)
{	
	ll currTwo = *maxFromSubs[centro].begin() + *next(maxFromSubs[centro].begin());
	maxFromCentros.erase(maxFromCentros.find(currTwo));

	auto drze = &itsTree[centro];

	if(drze->pre[a]>drze->pre[b])
		swap(a, b);

	int son = (*chooseSon[centro].lower_bound(mp(drze->post[b], -inf))).nd;
	int pre = drze->pre[son];
	int post = drze->post[son];
	ll curr = drze->query(pre, post, 1, 0, drze->s - 1);
	maxFromSubs[centro].erase(maxFromSubs[centro].find(curr));
	drze->insert(drze->pre[b], drze->post[b], change, 1, 0, drze->s - 1);
	curr = drze->query(pre, post, 1, 0, drze->s - 1);
	maxFromSubs[centro].insert(curr);

	//assert(siz(maxFromSubs[centro])>=2);
	currTwo = *maxFromSubs[centro].begin() + *next(maxFromSubs[centro].begin());
	maxFromCentros.insert(currTwo);
}

void update(int d, ll newWeight)
{
	int x = a[d];
	int y = b[d];
	int curr = -1;

	if(centroOnLvl[x]<centroOnLvl[y])
		curr = x;
	else
		curr = y;

	while(curr)
	{
		updateCentro(curr, x, y, newWeight - weight[d]);
		curr = par[curr];
	}

	weight[d] = newWeight;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q >> maxW;

	for(int i = 1; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> weight[i];
		G[a[i]].eb(b[i], weight[i]);
		G[b[i]].eb(a[i], weight[i]);
	}

	decompo(1);

	while(q--)
	{
		int d;
		ll e;
		cin >> d >> e;
		d = (d+last)%(n-1)+1;
		e = (e+last)%maxW;
		update(d, e);
		cout << (last = *maxFromCentros.begin()) << endl;
	}
}