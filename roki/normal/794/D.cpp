#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n, m;
const int N = 600 * 1000 + 5;

vector<int> g[N];
set<pt> edge;

inline bool read() {
	scanf("%d%d", &n, &m);
	forn (i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		edge.insert(mp(a, b));
		edge.insert(mp(b, a));
	}
	return true;
}
  
bool can[N];
bool used[N];
int color[N];
bool ok = true;

void dfs(int v) {
	used[v] = true;
	
	if (v == 0) {
	
		int sw = -1, su = -1;
		forn (i, sz(g[v])) {
			if (sw == -1)
			forn (j, i) {
				int w = g[v][i], u = g[v][j];
				if (!edge.count(mp(w, u))) {
					sw = w, su = u; 
					break;
				}
			}
		}
		if (sw == -1) {
			for (int to : g[v]) {
				if (sz(g[to]) == sz(g[v]))
					color[to] = color[v];
				else
					color[to] = color[v] + 1;
			}	
		} else {
			color[sw] = color[v] - 1;
			color[su] = color[v] + 1;
			for (int to : g[v]) {
				if (to == sw || to == su)
					continue;
				bool esw = edge.count(mp(to, sw)), esu = edge.count(mp(to, su));
				if (!esw && !esu) {
					ok = false;
				}
				if (esw && esu)
					color[to] = color[v];
				if (esw && !esu)
					color[to] = color[v] - 1;
				if (esu && !esw)
					color[to] = color[v] + 1;
			}
		}
		can[color[v]] = can[color[v] + 1] = can[color[v] - 1] = false;
		for (int to : g[v])
			dfs(to);
		return;
	}

	if (can[color[v] - 1]) {
		for (int to : g[v])
			if (color[to] == -1)
				color[to] = color[v] - 1;
		can[color[v] - 1] = false;
		for (int to : g[v])
			if (!used[to])
				dfs(to);		
	} else {
		for (int to : g[v]) {
			if (color[to] == -1)
				color[to] = color[v] + 1;
		}
		can[color[v] + 1] = false;
		for (int to : g[v])
			if (!used[to])
				dfs(to);
	}
}

inline void solve() {
	

	forn (i, n)
		color[i] = -1;
	
	memset(can, true, sizeof can);
	color[0] = n;
	dfs(0);
	vector<pt> v;
	forn (i, n)
		v.pb(mp(color[i], i));
	sort(all(v));
	m *= 2;
	
	forn (i, n) {
		if (!ok)
			break;
		int j = i + 1;
		while(ok && j < n && abs(v[j].x - v[i].x) <= 1) {
			ok &= edge.count(mp(v[i].y, v[j].y));
			m--;
			j++;
		}
		j = i - 1;
		while(ok && j >= 0 && abs(v[j].x - v[i].x) <= 1) {
			ok &= edge.count(mp(v[i].y, v[j].y));
			m--;
			j--;
		}
	}
	if (ok && m == 0) {
		puts("YES");
		forn (i, n)
			printf("%d ", color[i]);
	} else {
		puts("NO");
	}
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}