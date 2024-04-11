#include<bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i < int(n); ++i)
#define fork(i, k, n) for(int i = int(k); i <= int(n); ++i)
#define forft(i, from, to) for(int i = int(from); i < int(to); ++i)
#define forr(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define mnp(a, b) make_pair((a) < (b) ? (a) : (b), (a) < (b) ? (b) : (a))
#define sz(d) int(d.size())
#define all(a) a.begin(), a.end()
#define ms(a, v) memset(a, v, sizeof(a))
#define msn(a, v, n) memset(a, v, n * sizeof(a[0]))
#define mcn(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define correct(x, y, xmax, ymax) ((x) >= 0 && (x) < (xmax) && (y) >= 0 && (y) < (ymax))

template<typename T> T sqr(const T &x) {
	return x * x;
}

template<typename T> T my_abs(const T &x) {
	return x < 0 ? -x : x;
}

typedef long long li;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long uli;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<li,li> pli;
typedef pair<ld,ld> pd;

const int INF = (int)1e9;
const li LINF = (li)6e18;
const li INF64 = LINF;
const li INFLL = LINF;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 606;

int f[N][N];
int cnt[N];

int n, k;

bool read() {
	forn (i, N) {
		forn (j, N)
			f[i][j] = INF;
		f[i][i] = 0;
	}
	
	int m, team;
	
	cin >> n >> m >> team >> k;

	forn (i, team) {
		int pos;
		cin >> pos;
		pos--;
		cnt[pos]++;
	}
	forn (i, m) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		f[a][b] = min(f[a][b], w);
		f[b][a] = min(f[b][a], w);
	}	
	
	return true;
}

struct edge {
	int a, b, cap, flow;
};

const int M = 3 * N;
 
int s, t, d[M], ptr[M], q[M];
vector<edge> e;
vector<int> g[M];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

bool ok(int mid) {
		
	e.clear();
	forn (i, M)
		g[i].clear();

	s = M - 2, t = M - 1;

	forn (i, n)
		if (cnt[i])
			add_edge(s, i, cnt[i]);	

	forn (i, n)
		add_edge(n + i, t, 1);
			
	forn (i, n)
		forn (j, n) {
			if (f[i][j] <= mid) {
				add_edge(i, n + j, INF);
			}
		}
	return dinic() >= k;
}

void solve() {
	forn (k, n)
		forn (i, n)
			forn (j, n)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	int l = -1, r = INF - 1;
	while(r - l > 1) {
		int mid = (l + r) >> 1;
		if (ok(mid))
			r = mid;
		else
			l = mid;	
	}
	if (ok(r))
		cout << r << endl;
	else
		cout << -1 << endl;
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef SU2_PROJ
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#ifdef FILES	
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
#endif
	
	srand((unsigned int)time(NULL));

	cout << setprecision(15) << fixed;

	read();
	solve();
	
#ifdef SU2_PROJ
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}