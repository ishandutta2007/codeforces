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

bool a[N];

int main() {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	int n;
	cin >> n;

	int k = 0;
	while (k * k < n) {
		k++;
	}

	int r = n + 1 - k - ((n + k - 1) / k);

	forn (i, 1, n + 1) {
		int t = n + 1 - i - ((n + i - 1) / i);
		assert(t <= r);
	}

	debug(mt(n, k, r));

	memset(a, 0, sizeof a);

	while (true) {
		debug(a, a + n);
		if (accumulate(a, a + n, 0) >= r) {
			break;
		}
		vi v;
		forn (i, n) {
			if (i % k == 0) {
				continue;
			}
			if (!a[i]) {
				v.pb(i);
				a[i] = 1;
			}
		}
		int s = sz(v);
		printf("%d", s);
		for (int x : v) {
			printf(" %d", x + 1);
		}
		puts("");
		fflush(stdout);

		int l;
		scanf("%d", &l);
		if (l <= 0) {
			return 0;
		}
		--l;

		forn (i, s) {
			a[(l + i) % n] = 0;
		}
	}

	puts("0");
	
	return 0;
}