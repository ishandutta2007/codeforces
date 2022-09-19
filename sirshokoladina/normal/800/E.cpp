#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000;

int p[2 * N - 1], el[2 * N - 1], er[2 * N - 1];
int numl[2 * N - 1];
int cnt[2 * N - 1];
bool isl[2 * N - 1];

void dfs (int v) {
	cnt[v] = 1;
	if (isl[v]) {
		return;
	}
	dfs(el[v]);
	cnt[v] += cnt[el[v]];
	dfs(er[v]);
	cnt[v] += cnt[er[v]];
}

void solve (int n) {
	int rt = -1;
	memset(isl, 0, sizeof isl);
	forn (i, 2 * n - 1) {
		if (p[i] == -1) {
			rt = i;
		}
		if (el[i] == -1) {
			isl[i] = 1;
		}
	}
	while (!isl[rt]) {
		dfs(rt);
		int v = rt;
		while (1) {
			if (!isl[el[v]] && 2 * cnt[el[v]] > cnt[rt]) {
				v = el[v];
				continue;
			}
			if (!isl[er[v]] && 2 * cnt[er[v]] > cnt[rt]) {
				v = er[v];
				continue;
			}
			break;
		}
		int v1 = numl[el[v]];
		int v2 = numl[er[v]];
		int v3 = n;
		printf("%d %d %d\n", v1 + 1, v2 + 1, v3 + 1);
		fflush(stdout);
		char res;
		scanf(" %c", &res);
		if (res == 'X') {
			isl[v] = 1;
			continue;
		} else if (res == 'Y') {
			rt = er[v];
			continue;
		} else if (res == 'Z') {
			rt = el[v];
			continue;
		} else {
			assert(0);
		}
	}
	
	p[2 * n - 1] = p[rt];
	if (p[rt] != -1) {
		int done = 0;
		if (el[p[rt]] == rt) {
			el[p[rt]] = 2 * n - 1;
			done++;
		}
		if (er[p[rt]] == rt) {
			er[p[rt]] = 2 * n - 1;
			done++;
		}
		assert(done == 1);
	}
	p[rt] = 2 * n - 1;
	el[2 * n - 1] = rt;
	p[2 * n] = 2 * n - 1;
	er[2 * n - 1] = 2 * n;
	numl[2 * n - 1] = numl[2 * n] = n;
}

int main () {
	int n;
	cin >> n;
	memset(p, -1, sizeof p);
	memset(el, -1, sizeof el);
	memset(er, -1, sizeof er);
	numl[0] = 0;
	forn (i, 1, n) {
		solve(i);
	}
	puts("-1");
	forn (i, 2 * n - 1) {
		if (i) {
			printf(" ");
		}
		printf("%d", p[i] + (p[i] != -1));
	}
	puts("");
	fflush(stdout);
	return 0;
}