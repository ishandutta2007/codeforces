#include <bits/stdc++.h>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
 
using namespace std;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

template <class T> inline bool inRange(T z, T a, T b){return a <= z && z <= b;}

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v3.0

struct Edge
{
	int from, to, cap, flow, backIdx;
	Edge(){}
	Edge(int from,int to,int cap,int flow,int backIdx):
		from(from),
		to(to),
		cap(cap),
		flow(flow),
		backIdx(backIdx){}
};

vi primes;

typedef pair<int,ii> i3;
typedef vector<i3> vi3;
#define mp3(_a,_b,_c) mp(_a,mp(_b,_c))

#define N 20000
#define SOURCE 19998
#define SINK 19999
int num[N], idx[N];
vi adj[N];
vi3 pr[N];
Edge edge[N];
bitset<N> used;
vii pairs;
int n,m,cntNode,cntEdge,adjIter[N];
int level[N];

inline void addEdge(int a,int b,int fr,int ba)
{
	edge[cntEdge] = Edge(a,b,fr,0,cntEdge^1);
	edge[cntEdge^1] = Edge(b,a,ba,0,cntEdge);
	adj[a].pb(cntEdge);
	adj[b].pb(cntEdge^1);
	cntEdge += 2;
}

inline void init(int x)
{
	int num = ::num[x];
	int now = idx[x] = cntNode++;
	int cnt = 0;

	if (!(num&1))
	{
		pr[now].pb(mp3(2,cntNode++,0));
		while (!(num&1))
		{
			num >>= 1;
			++cnt;
		}
		if (x&1)
			addEdge(now,pr[now].back().ss.ff,cnt,0);
		else
			addEdge(now,pr[now].back().ss.ff,0,cnt);
		pr[now].back().ss.ss = cnt;
	}
	for (int z = 3; z * z <= num; z += 2)
	{
		if (num % z == 0)
		{
			pr[now].pb(mp3(z,cntNode++,0));
			cnt = 0;
			while (num % z == 0)
			{
				num /= z;
				++cnt;
			}
			if (x&1)
				addEdge(now,pr[now].back().ss.ff,cnt,0);
			else
				addEdge(now,pr[now].back().ss.ff,0,cnt);
			pr[now].back().ss.ss = cnt;
		}
	}
	if (num > 1)
	{
		pr[now].pb(mp3(num,cntNode++,1));
		cnt = 1;
		if (x&1)
			addEdge(now,pr[now].back().ss.ff,cnt,0);
		else
			addEdge(now,pr[now].back().ss.ff,0,cnt);
	}
}

inline void pasang(int a,int b)
{
	if (a&1);
	else swap(a,b); // ganjil ke genap
	int ia = idx[a], ib = idx[b];
	int j = 0;
	FOR (i,0,SIZE(pr[ia]))
	{
		while (j < SIZE(pr[ib]) && pr[ib][j].ff < pr[ia][i].ff) ++j;
		if (j < SIZE(pr[ib]) && pr[ib][j].ff == pr[ia][i].ff) // pasang
		{
			int zz = max(pr[ia][i].ss.ss,pr[ib][j].ss.ss);
			addEdge(pr[ia][i].ss.ff, pr[ib][j].ss.ff, zz, 0);
			++j;
		}
	}
	return ;
}

inline bool bfs()
{
	FOR (i,0,cntNode) level[i] = 0;
	level[SOURCE] = 1;
	level[SINK] = 0;
	queue<int> Q;
	Q.push(SOURCE);
	while (!Q.empty() && level[SINK] == 0)
	{
		int now = take(Q);
		FOR (i,0,SIZE(adj[now]))
		{
			Edge &ne = edge[adj[now][i]];
			if (level[ne.to] == 0 && ne.cap - ne.flow > 0)
			{
				level[ne.to] = level[now] + 1;
				Q.push(ne.to);
			}
		}
	}
	return level[SINK] > 0;
}

void dfs(int u,int &currentFlow,int minFlow)
{
	if (u == SINK)
	{
		currentFlow = minFlow;
		return ;
	}
	for (;adjIter[u] < SIZE(adj[u]); ++adjIter[u])
	{
		Edge &ne = edge[adj[u][adjIter[u]]];
		if (level[ne.from] + 1 == level[ne.to] && ne.cap - ne.flow > 0)
		{
			dfs(ne.to, currentFlow, min(minFlow, ne.cap - ne.flow));
			if (currentFlow > 0)
			{
				ne.flow += currentFlow;
				Edge &neb = edge[adj[u][adjIter[u]] ^ 1];
				neb.flow -= currentFlow;
				return ;
			}
		}
	}
	return ;
}

bitset<N> vis;
int bef[N];

int dfss(int u)
{
	vis.set(u,1);
	if (u == SINK) return INF;
	FOR (i,0,SIZE(adj[u]))
	{
		Edge &ne = edge[adj[u][i]];
		if (!vis.test(ne.to) && ne.cap - ne.flow > 0)
		{
			bef[ne.to] = adj[u][i];
			int tmp;
			if ((tmp = dfss(ne.to)) > 0)
				return min(tmp, ne.cap - ne.flow);
		}
	}
	return 0;
}

void augment(int v, int flow)
{
	if (v == SOURCE) return ;
	// cerr << v << endl;
	Edge &ne = edge[bef[v]];
	Edge &neb = edge[bef[v] ^ 1];
	ne.flow += flow;
	neb.flow -= flow;
	augment(ne.from, flow);
	return ;
}

int dfss()
{
	vis.reset();
	return dfss(SOURCE);
}

int main(int argc, char const *argv[])
{
	__INIT_CC__;
	cin >> n >> m;
	FOR (i,0,n) cin >> num[i];
	FOR (i,0,m)
	{
		int a,b;
		cin >> a >> b;
		--a;--b;
		pairs.pb(mp(a,b));
		used.set(a,1);
		used.set(b,1);
	}
	cntNode = 0;
	cntEdge = 0;
	FOR (i,0,n)
		if (used.test(i))
		{
			init(i);
			if (i&1) // ganjil, source
				addEdge(SOURCE, idx[i], INF, 0);
			else
				addEdge(idx[i], SINK, INF, 0);
		}
	for (auto now : pairs)
		pasang(now.ff,now.ss);

	int ans = 0;
	// while (bfs())
	// {
	// 	int currentFlow = 0;
	// 	FOR (i,0,cntNode)
	// 		adjIter[i] = 0;
	// 	do
	// 	{
	// 		currentFlow = 0;
	// 		dfs(SOURCE, currentFlow, INF);
	// 		ans += currentFlow;
	// 	} while (currentFlow > 0);
	// }
	
	int cf = 0;
	while ((cf = dfss()))
	{
		ans += cf;
		augment(SINK,cf);
	}

	cout << ans << "\n";
	return 0;
}