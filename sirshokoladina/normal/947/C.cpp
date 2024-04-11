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

const int N = 300000;
const int L = 30;

struct Input {
	int n;
	int a[N], b[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, n) {
			scanf("%d", &b[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write () {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		puts("");
	}
};


namespace Main {
	const int M = (L + 1) * N;
	
	struct Solution: Data {
		int m;
		int to[M][2];
		int cnt[M];
		
		void solve () {
			m = 1;
			memset(to, -1, sizeof to);
			memset(cnt, 0, sizeof cnt);
			forn (i, n) {
				int cur = 0;
				cnt[cur]++;
				ford (j, L) {
					int t = bool(b[i] & (1 << j));
					if (to[cur][t] == -1) {
						to[cur][t] = m++;
					}
					cur = to[cur][t];
					cnt[cur]++;
				}
			}
			forn (i, n) {
				int cur = 0;
				int val = 0;
				cnt[cur]--;
				ford (j, L) {
					int t = bool(a[i] & (1 << j));
					if (to[cur][t] == -1 || cnt[to[cur][t]] == 0) {
						t = !t;
					}
//					debug(mt(j, t));
					val += t << j;
					cur = to[cur][t];
					cnt[cur]--;
				}
				ans[i] = a[i] ^ val;
			}
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
		while (sol.read()) {
			sol.solve();
			sol.write();
			sol.clear();
		}
	#else
		sol.read();
		sol.solve();
		sol.write();
	#endif
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}