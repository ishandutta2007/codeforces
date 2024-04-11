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
#define mcp(dst, src, n) memcpy(dst, src, n * sizeof(src[0]))
#define X first
#define Y second
#define x first
#define y second

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
const li INF64 = (li)4e18;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

int n, q;
const int N = 200;
bool can[N][N];

bool read() {
	cin >> n >> q;
	forn (i, n)
		forn (j, n)
			can[i][j] = true;
	forn (it, q) {
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		l--, r--, x--;
		for (int i = l; i <= r; ++i) {
			if (t == 1) {
				for (int j = x - 1; j >= 0; --j)
					can[i][j] = false;
			} else {
				for (int j = x + 1; j < n; ++j)
					can[i][j] = false;
			}
		}
	}
    return true;
}

struct edge {
	int to, flow, cap, cost, back;
};

vector<edge> g[N];

void add_edge(int v, int u, int cost) {
	edge f = {u, 0, 1, cost, sz(g[u])};
	edge b = {v, 0, 0, -cost, sz(g[v])};
	g[v].pb(f);
	g[u].pb(b);
}

int d[N];
int f[N];
bool inq[N];
pt p[N];

bool enlarge(int s, int t, int & cost) {
	forn (i, N)
		d[i] = INF;
	d[s] = 0;
	f[s] = INF;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		inq[v] = false;
		for (edge & e : g[v]) {
			if (e.cap - e.flow > 0) {
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					f[e.to] = min(f[v], e.cap - e.flow);
					if (!inq[e.to]) {
						q.push(e.to);
						inq[e.to] = true;
					}
					p[e.to] = pt(v, g[e.to][e.back].back);
				}
			}
		}
	}
	if (d[t] == INF)
		return false;
	cost += d[t] * f[t];
	int pushed = f[t];
	while(t != s) {
		int v = p[t].x, i = p[t].y;
		g[v][i].flow += pushed;
		g[t][g[v][i].back].flow -= pushed;
		t = v;
	}
	return true;
}

int maxflow(int s, int t) {
	int cost = 0;
	while(enlarge(s, t, cost));
	return cost;
}

void solve() {
	forn (i, n)
		forn (j, n)
			if (can[i][j])
				add_edge(i, n + j, 0);
	int s = 2 * n;
	int t = s + 1;
	forn (i, n)
		add_edge(s, i, 0);
	forn (i, n) {
		int x = 1;
		forn (j, n) {
			add_edge(n + i, t, sqr(x) - sqr(x - 1));
			x++;
		}
	}
	
	forn (i, n) {
		bool any = false;
		forn (j, n)
			any |= can[i][j];
		if (!any) {
			cout << -1 << endl;
			return;
		}
	}
	
	cout << maxflow(s, t) << endl;	
}

//#define FILES

#define TASK "taskname"

int main() {

#ifdef _DEBUG
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
	
#ifdef _DEBUG
	cerr << "time: " << clock() << " ms" << endl;
#endif

	return 0;
}