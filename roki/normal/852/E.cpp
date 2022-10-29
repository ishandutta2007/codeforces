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

const int N = 100 * 1000 + 5;
vector<int> g[N];
int n;

bool gen() {
	n = 1;
	for (int i = 1; i < n; ++i) {
		int j = rand() % i;
		g[i].pb(j);
		g[j].pb(i);
		cerr << i + 1 << ' ' << j + 1 << endl;
	}
	return true;
}

bool read() {
//	r//eturn gen();
	
	cin >> n;
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return li(a) * b % MOD;
}

int add(int a, int b) {
	a += b;
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

int bp(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1)
			res = mul(res, a);
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}

int modinverse(int a) {
	return bp(a, MOD - 2);
}

int dv(int a, int b) {
	return mul(a, modinverse(b));
}

int ans = 0;

int dp[N];

void calc(int v, int p = -1) {
	bool any = false;
	dp[v] = 1;
	for (int to : g[v]) {
		if (to == p)
			continue;
		any = true;
		calc(to, v);
		dp[v] = mul(dp[v], dp[to]);
	}
	if (any)
		dp[v] = mul(dp[v], 2);
}

void dfs(int v, int p, int m) {
	
//	cerr << "DFS " << v << ' ' << m << endl;

	m = mul(m, 2);
	
	for (int to : g[v])
		if (to != p)
			m = mul(m, dp[to]);
			
	ans = add(ans, m);

	if (p == -1) {
		if (sz(g[v]) == 1)
			m = dv(m, 2);
	}
	
	for (int to : g[v]) 
		if (to != p)
			dfs(to, v, dv(m, dp[to]));
}

int naive() {
	int res = 0;
	forn (i, n) {
		calc(i, -1);
		res = add(res, dp[i]);
	}
	return res;
}

void solve() {
	calc(0, -1);
	ans = 0;
	dfs(0, -1, 1);	
	if (n == 1)
		ans = 1;
	cout << ans << endl;
//	cerr << naive() << endl;
//	assert(ans == naive());
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