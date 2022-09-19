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

struct Input {
	int msk;
	
	bool read () {
		string s;
		if (!getline(cin, s)) {
			return 0;
		}
		msk = 0;
		forn (i, sz(s)) {
			if (s[i] == '1') {
				msk += 1 << i;
			}
		}
		debug(msk);
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans;
	
	void write () {
		puts(ans.c_str());
	}
};


namespace Main {
	
	struct Solution: Data {
		pa<int, string> de[256], dt[256], df[256];
		
		Solution () {
			forn (i, 256) {
				de[i] = mp(1000000, "");
				dt[i] = mp(1000000, "");
				df[i] = mp(1000000, "");
			}
			df[255 / 3 * 2] = mp(1, "z");
			df[255 / 5 * 4] = mp(1, 'y');
			df[255 / 17 * 16] = mp(1, 'x');
			while (1) {
				bool done = 0;
				forn (i, 256) {
					if (umn(df[i], mp(de[i].fs + 2, "(" + de[i].sc + ")"))) {
						done = 1;
					}
					if (umn(df[255 - i], mp(df[i].fs + 1, "!" + df[i].sc))) {
						done = 1;
					}
					if (umn(dt[i], df[i])) {
						done = 1;
					}
					if (umn(de[i], dt[i])) {
						done = 1;
					}
				}
				forn (i, 256) {
					forn (j, 256) {
						if (umn(dt[i & j], mp(dt[i].fs + df[j].fs + 1, dt[i].sc + "&" + df[j].sc))) {
							done = 1;
						}
						if (umn(de[i | j], mp(de[i].fs + dt[j].fs + 1, de[i].sc + "|" + dt[j].sc))) {
							done = 1;
						}
					}
				}
				if (!done) {
					break;
				}
			}
		}
		
		void solve () {
			ans = de[msk].sc;
		}
		
		void clear () {
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
	#endif
	
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}