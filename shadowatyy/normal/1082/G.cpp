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

#define int ll
const int N = 4007;

int n, m, cnt, t, sum;

int a[N];
int b[N];
int u[N];
int v[N];

int cap[N][N];

VI G[N];

int dist[N];

queue<int> Q;

bool bfs()
{
	for(int i = 0; i <= t; ++i)
	{
		dist[i] = inf;
	}

	dist[0] = 0;
	Q.push(0);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(auto it:G[v])
		{
			if(cap[v][it]>0 && dist[it]==inf)
			{	
				dist[it] = dist[v]+1;
				Q.push(it);
			}
		}
	}

	return dist[t]!=inf;
}

int dfs(int v = 0, int mc = INF)
{
	if(!mc || v==t)
		return mc;

	int res = 0;

	for(auto it:G[v])
	{
		if(dist[it]==dist[v]+1 && cap[v][it]>0)
		{
			int f = dfs(it, min(mc, cap[v][it]));
			cap[v][it] -= f;
			cap[it][v] += f;
			res += f;
			mc -= f;
		}

		if(!mc)
			break;
	}

	return res;
}

int flow()
{
	int ans = 0;

	while(bfs())
		ans += dfs();

	return ans;
}

void addEdge(int a, int b, int c)
{
	cap[a][b] += c;
	G[a].pb(b);
	G[b].pb(a);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> u[i] >> v[i] >> b[i];
		sum += b[i];
	}

	t = m+n+1;

	for(int i = 1; i <= m; ++i)
	{
		addEdge(0, i, b[i]);
		addEdge(i, m+v[i], INF);
		addEdge(i, m+u[i], INF);
	}

	for(int i = 1; i <= n; ++i)
	{
		addEdge(m+i, t, a[i]);
	}

	cout << sum-flow() << endl;
}