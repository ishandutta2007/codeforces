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

void solve() {
	int n;
	cin >> n;
	vi ans;
	int k = 1;
	while (k < n) {
		printf("? %d %d\n", k, 1);
		forn (i, k) {
			if (i) {
				printf(" ");
			}
			printf("%d", i + 1);
		}
		puts("");
		printf("%d\n", k + 1);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		if (res) {
			break;
		}
		k++;
	}
	assert(k < n);

	debug(k);

	int lb = 0, rb = k;
	while (lb + 1 < rb) {
		int md = (lb + rb) / 2;
		printf("? %d %d\n", md - lb, 1);
		forn (i, lb, md) {
			if (i != lb) {
				printf(" ");
			}
			printf("%d", i + 1);
		}
		puts("");
		printf("%d\n", k + 1);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		if (res) {
			rb = md;
		} else {
			lb = md;
		}
	}

	debug(lb);

	forn (i, k) {
		if (i != lb) {
			ans.pb(i);
		}
	}
	forn (i, k + 1, n) {
		printf("? 1 1\n");
		printf("%d\n", k + 1);
		printf("%d\n", i + 1);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		if (!res) {
			ans.pb(i);
		}
	}
	printf("! %d", sz(ans));
	forn (i, sz(ans)) {
		printf(" %d", ans[i] + 1);
	}
	puts("");
	fflush(stdout);
}

int main() {
	int t;
	cin >> t;
	forn (i, t) {
		solve();
	}
	
	return 0;
}