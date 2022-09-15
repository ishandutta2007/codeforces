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
const int M = 100000;

struct Input {
	int n, m;
	int a[N][N];
	string s;
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			forn (j, n) {
				scanf("%d", &a[i][j]);
				--a[i][j];
			}
		}
		getline(cin, s);
		getline(cin, s);
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N][N];

	void write() {
		debug();
		forn (i, n) {
			forn (j, n) {
				if (j) {
					printf(" ");
				}
				printf("%d", ans[i][j] + 1);
			}
			puts("");
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		
		void solve() {
			int p[3] = {0, 1, 2};
			int q[3] = {0, 1, 2};
			int d[3] = {0, 0, 0};
			forn (i, m) {
				debug(s[i]);
				if (s[i] == 'R') {
					(d[p[1]] += 1) %= n;
				} else if (s[i] == 'L') {
					(d[p[1]] += n - 1) %= n;
				} else if (s[i] == 'D') {
					(d[p[0]] += 1) %= n;
				} else if (s[i] == 'U') {
					(d[p[0]] += n - 1) %= n;
				} else if (s[i] == 'I') {
					swap(q[p[1]], q[p[2]]);
					swap(p[1], p[2]);
				} else if (s[i] == 'C') {
					swap(q[p[0]], q[p[2]]);
					swap(p[0], p[2]);
				} else {
					assert(0);
				}
				debug(p, p + 3);
				debug(q, q + 3);
				debug(d, d + 3);
			}
			int t[3];
			forn (i, n) {
				forn (j, n) {
					t[0] = (i + d[0]) % n;
					t[1] = (j + d[1]) % n;
					t[2] = (a[i][j] + d[2]) % n;
					ans[t[p[0]]][t[p[1]]] = t[p[2]];
				}
			}
		}
		
		void clear() {
			
		}
	};
}


Main::Solution sol;

int main() {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
	#endif
	
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}