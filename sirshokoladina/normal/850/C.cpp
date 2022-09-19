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

const int N = 100;

struct Input {
	int n;
	int a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
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
		puts(ans ? "Mojtaba" : "Arpa");
	}
};


namespace Main {
	const int D = 1 << 19;
	
	struct Solution: Data {
		int fst[D];
		map<int, int> mem;

		int get (int msk) {
			if (msk < D) {
				return fst[msk];
			}
			if (mem.count(msk)) {
				return mem[msk];
			}
			return mem[msk] = calc(msk);
		}

		int calc (int msk) {
			vi v;
			for (int i = 0; (1 << i) <= msk; ++i) {
				v.pb(get((msk & ((1 << i) - 1)) | (msk >> (i + 1))));
			}
			sort(all(v));
			v.erase(unique(all(v)), v.end());
			int res = 0;
			while (res < sz(v) && v[res] == res) {
				++res;
			}
			deepen(msk <= 10);
			debug(mt(msk, res));
			return res;
		}

		void precalc () {
			forn (i, D) {
				fst[i] = calc(i);
			}
		}
		
		void solve () {
			precalc();

			map<int, int> p;

			forn (i, n) {
				for (int j = 2; j * j <= a[i]; ++j) {
					int cnt = 0;
					while (a[i] % j == 0) {
						cnt++;
						a[i] /= j;
					}
					if (cnt) {
						p[j] |= 1 << (cnt - 1);
					}
				}
				if (a[i] > 1) {
					p[a[i]] |= 1;
				}
			}

			debug(p);

			int res = 0;
			for (const auto &q : p) {
				res ^= get(q.sc);
				debug(mt(q.sc, get(q.sc)));
			}
			ans = res;
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