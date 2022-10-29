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

const int N = 400 * 1000 + 5;
int n;

vector<int> g[N];

inline bool read() {
	scanf("%d", &n);
	forn (i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

int tsz[N];   
int dp[N];

int dfs(int v, int p = -1) {
	tsz[v] = 1;
	dp[v] = 0;
	for (int to : g[v]) {
		if (to != p) {
		 	tsz[v] += dfs(to, v);
			dp[v] = max(dp[v], dp[to]);
			if (tsz[to] * 2 <= n)
				dp[v] = max(dp[v], tsz[to]); 	
		}
	}
	return tsz[v];
}

int ans[N];
vector<int> sufdp[N];
vector<int> prefdp[N];

void calcans(int v, int p = -1) {
	int prevtsz = tsz[v];
	int prevdp = dp[v];
	tsz[v] = 1;
	dp[v] = 0;
	prefdp[v].resize(sz(g[v]));
	sufdp[v].resize(sz(g[v]));
	forn (i, sz(g[v])) {
		int to = g[v][i];
		tsz[v] += tsz[to];
		dp[v] = max(dp[v], dp[to]);
		prefdp[v][i] = dp[to];
		sufdp[v][i] = dp[to];
		if (tsz[to] * 2 <= n) {
			dp[v] = max(dp[v], tsz[to]);
			prefdp[v][i] = tsz[to];
			sufdp[v][i] = tsz[to];
		} 			
	}
	forn (i, sz(g[v]) - 1)
		prefdp[v][i + 1] = max(prefdp[v][i + 1], prefdp[v][i]);
	for (int i = sz(g[v]) - 1; i > 0; --i)
		sufdp[v][i - 1] = max(sufdp[v][i - 1], sufdp[v][i]);
	ans[v] = 1;
	for (int to : g[v])
		if ((tsz[to] - dp[to]) * 2 > n)
			ans[v] = 0;
	forn (i, sz(g[v])) {
		int to = g[v][i];
		if (to == p)
			continue;
		tsz[v] -= tsz[to];
		dp[v] = max((i > 0 ? prefdp[v][i - 1] : 0), (i + 1 < sz(g[v]) ? sufdp[v][i + 1] : 0));
		calcans(to, v);
		tsz[v] += tsz[to];
	}	
	dp[v] = prevdp;
	tsz[v] = prevtsz;
}

inline void solve() {
	dfs(0);   

	calcans(0);

	forn (i, n)
		printf("%d ", ans[i]);
	puts("");
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