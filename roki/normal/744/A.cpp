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

int n, m, k;
const int N = 5005;
vector<int> g[N];

int c[N];

inline bool read() {
	cin >> n >> m >> k;
	
	forn (i, k) {
		cin >> c[i];
		c[i]--;
	}
	
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

vector<int> comp;

bool used[N];

void dfs(int v) {
	comp.pb(v);
	used[v] = true;
	for (int to : g[v])
		if (!used[to])
			dfs(to);
}
   
vector<vector<int> > comps;

void inc(vector<int> &comp, int &ans) {
		int curans = sz(comp) * (sz(comp) - 1) / 2;
		int sub = 0;
		for (int v : comp)
			sub += sz(g[v]);
		sub /= 2;
		curans -= sub;
		ans += curans;
}

inline void solve() {   
	int ans = 0;
	forn (i, k) {
		comp.clear();
		dfs(c[i]);
		comps.pb(comp);
	}
	
	int big = 0;
	forn (i, sz(comps))
		if (sz(comps[i]) > sz(comps[big]))
			big = i;
	
	forn (i, n)
		if (!used[i])
			comps[big].pb(i);
	
	forn (i, sz(comps))
		inc(comps[i], ans);
			
	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}