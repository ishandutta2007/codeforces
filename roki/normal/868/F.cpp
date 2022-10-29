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

const int N = 100 * 1000 + 5;

int a[N];
const int M = 22;
li dp[M][N];
int n, k;

bool read() {
    cin >> n >> k;
    forn (i, n)
    	cin >> a[i];
    return true;
}

int L = 0, R = 0;
li curans = 0;
int cnt[N];

void upd(int l, int r) {
	while (L < l) {
		cnt[a[L]]--;
		curans -= cnt[a[L]];
		L++;
	}
	while (L > l) {
		L--;
		curans += cnt[a[L]];
		cnt[a[L]]++;
	}
	while (R < r) {
		R++;
		curans += cnt[a[R]];
		cnt[a[R]]++;
	}
	while (R > r) {
		cnt[a[R]]--;
		curans -= cnt[a[R]];
		R--;	
	}
}

void calc(li dp[N], li prv[N], int l, int r, int lq, int rq) {
	if (l > r)
		return;
	int mid = (l + r) >> 1;
	dp[mid] = INF64;
	int from = -1;
	for (int i = lq; i <= min(mid - 1, rq); ++i) {
		upd(i, mid - 1);
		if (dp[mid] > prv[i] + curans) {
			dp[mid] = prv[i] + curans;
			from = i;
		}
	}
	calc(dp, prv, l, mid - 1, lq, from);
	calc(dp, prv, mid + 1, r, from, rq);
}

void solve() {
	cnt[a[0]] = 1;
	forn (i, N) 
		forn (j, 22)
			dp[j][i] = INF64;
	dp[0][0] = 0;
	forn (i, k) {
		dp[i][0] = 0;
		calc(dp[i + 1], dp[i], 1, n, 0, n - 1);	
	}
	cout << dp[k][n] << endl;
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