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

const int N = 5000;

struct Input {
	int n;
	int a, b, c, d;
	int p[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		cin >> a >> b >> c >> d;
		--a;
		--b;
		--c;
		--d;
		forn (i, 1, n) {
			scanf("%d", &p[i]);
			--p[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;
	
	void write () {
		puts(ans ? "YES" : "NO");
	}
};


namespace Main {
	
	struct Solution: Data {
		bool isl[N];
		
		int gr[N];
		int cnt[N];
		
		int m;
		int s[N];
		
		int sum;
		int sum1;
		
		bool dyn[N + 1];
		
		void solve () {
			forn (i, n) {
				isl[i] = 1;
			}
			forn (i, 1, n) {
				isl[p[i]] = 0;
			}
			
			sum = 0;
			
			memset(cnt, 0, sizeof cnt);
			forn (i, 1, n) {
				if (isl[i]) {
					gr[i] = i;
					while (p[gr[i]] != 0) {
						gr[i] = p[gr[i]];
					}
					cnt[gr[i]]++;
					sum++;
				}
			}
			
			debug(isl, isl + n);
			debug(gr, gr + n);
			
			if (sum & 1) {
				ans = 0;
				return;
			}
			
			a = gr[a];
			b = gr[b];
			c = gr[c];
			d = gr[d];
			
			debug(mt(a, b, c, d));
			
			sum1 = sum - cnt[a] - cnt[b] - cnt[c] - cnt[d];
			
			m = 0;
			forn (i, 1, n) {
				if (p[i] == 0 && i != a && i != b && i != c && i != d) {
					s[m++] = cnt[i];
				}
			}
			
			debug(mt(cnt[a], cnt[b], cnt[c], cnt[d]));
			debug(s, s + m);
			debug(mt(sum1, sum));
			
			memset(dyn, 0, sizeof dyn);
			dyn[0] = 1;
			forn (i, m) {
				ford (j, N + 1 - s[i]) {
					dyn[j + s[i]] |= dyn[j];
				}
			}
			
			debug(dyn, dyn + n + 1);
			
			bool ok1 = 0;
			bool ok2 = 0;
			
			forn (i, N + 1) {
				if (dyn[i]) {
					if (i + cnt[a] < sum / 2 && sum1 - i + cnt[b] < sum / 2) {
						ok1 = 1;
					}
					if (i + cnt[c] < sum / 2 && sum1 - i + cnt[d] < sum / 2) {
						ok2 = 1;
					}
				}
			}
			
			ans = ok1 && ok2;
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