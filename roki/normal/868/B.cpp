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

int h, m, s;
int t1, t2;

bool read() {
	cin >> h >> m >> s >> t1 >> t2;
    return true;
}


const int N = 65; 
bool used[N];

int d[] = {-1, 1};

ld hpos, mpos;

bool can[N][N];

void dfs(int v) {
	used[v] = true;
	if (v == t2 * 5) {
		cout << "YES" << endl;
		exit(0);
	}
	forn (i, 2) {
		int to = (v + d[i] + 60) % 60;
		if (can[v][to] && !used[to])
			dfs(to);	
	}
}

void solve() {
	//cerr << t1 << ' ' << t2 << endl;
	h %= 12;
	t1 %= 12, t2 %= 12;
	memset(can, true, sizeof can);
	
	forn (i, N)
		can[i][s] = false;
	
	if (s == 0) {
		forn (i, N)
			can[i][m] = false;
	} else {
		int nm = (m + 1) % 60;
		can[nm][m] = can[m][nm] = false;
	}
	
	int cpos = h * 5;
	int cd = m * 60 + s;
	if (cd % 720 == 0) {
		forn (i, N)
			can[i][cpos + cd / 720] = false;
	} else {
		cpos += cd / 720;
		int npos = (cpos + 1) % 60;
		can[cpos][npos] = can[npos][cpos] = false;
	}
	
	
	dfs(t1 * 5);
	cout << "NO" << endl;
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