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

int n;
const int N = 100 * 1000 + 5;
int c[N];
vector<int> g[N];

inline bool read() {
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn (i, n)
		cin >> c[i];
	return true;
}

bool dfs(int v, int p) {
	bool res = true;
	for (int to : g[v]) {
		if (to == p)
			continue;
		if (c[to] != c[v])
			return false;
		res &= dfs(to, v);
	}
	return res;
}

bool ok(int v) {
	bool res = true;
	for (int to : g[v]) {
		res &= dfs(to, v);
	}	
	return res;
}

void find_root(int v, int p) {
	for (int to : g[v]) {
		if (to == p)
			continue;
		find_root(to, v);
		if (c[to] != c[v]) {
			if (ok(v)) {
				cout << "YES" << endl;
				cout << v + 1 << endl;
			} else if (ok(to)) {
				cout << "YES" << endl;
				cout << to + 1 << endl;
			} else {
				cout << "NO" << endl;
			}
			exit(0);
		}
	}
	if (v == 0) {
		cout << "YES" << endl;
		cout << 1 << endl;
		exit(0);
	}
}

inline void solve() {   
	find_root(0, -1);	
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