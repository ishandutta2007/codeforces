#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{ cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

VVI graph;
VI match;
V<bool> vis;

int mx = -1;
bool DFS(int v)
{
	vis[v] = true;
	for(int x : graph[v])
	{
		if(x >= mx) continue;
		int u = match[x];
		if(u == -1 || (!vis[u] && DFS(u)))
		{
			match[v] = x;
			match[x] = v;
			return true;
		}
	}
	return false;
}

int matching(int n)
{
	mx = n;
	match.clear();
	match.RS(n, -1);
	vis.RS(n);
	bool improved = true;
	int size = 0;
	while(improved)
	{
		improved = false;
		fill(ALL(vis), false);
		REP(i, n)
		{
			if(match[i] == -1 && !vis[i] && DFS(i))
			{
				improved = true;
				size++;
			}
		}
	}
	DB(n, size);
	return size;
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;
	VI p(n), c(n);
	REP(i, n) cin >> p[i];
	REP(i, n) cin >> c[i], c[i]--;
	DB(p, c);
	graph.RS(n + 5002);
	REP(i, n)
	{
		int a = c[i], b = n + p[i];
		DB(i, a, b);
		graph[a].EB(b);
		graph[b].EB(a);
	}

	int ans = 0;
	while(matching(n + ans + 1) == ans + 1) ans++;

	int d;
	cin >> d;
	REP(i, d)
	{
		int x;
		cin >> x;
		x--;
		int a = c[x];
		int b = n + p[x];
	
		VVI &g = graph;
		int q = S(g[a]);
		REP(j, q)
		{
			if(g[a][j] == b)
			{
				g[a].erase(g[a].begin() + j);
				break;
			}
		}

		q = S(g[b]);
		REP(j, q)
		{
			if(g[b][j] == a)
			{
				g[b].erase(g[b].begin() + j);
				break;
			}
		}

		while(matching(n + ans) != ans) ans--;
		cout << ans << "\n";
	}
}