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

const int N = 100000;
const int Q = 100000;

const int C = 7;
const string cmd[C + 2] = {"red", "orange", "yellow", "green", "blue", "indigo", "violet", "unlock", "lock"};
const int INIT = 4;

struct Input {
	int n;
	int s[N];
	int q;
	int q_i[Q];
	int q_s[Q];

	void read(int &x) {
		string t;
		cin >> t;
		x = 0;
		while (cmd[x] != t) {
			++x;
		}
	}

	bool read() {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			read(s[i]);
		}
		cin >> q;
		forn (i, q) {
			cin >> q_i[i];
			read(q_s[i]);
			--q_i[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[Q + 1];

	void write() {
		forn (i, q + 1) {
			puts(cmd[ans[i]].c_str());
		}
	}
};


namespace Main {
	const int M = 2 * N;
	
	struct Solution: Data {
		int m;

		pii t[2 * M][2];

		int get_or(int x, int y) {
			return (x == -1) ? y : x;
		}

		void set(int p, int val) {
			p += m;
			if (val < C) {
				t[p][0] = mp(val, 0);
				t[p][1] = mp(-1, 1);
			} else {
				t[p][0] = mp(-1, val - C);
				t[p][1] = mp(-1, val - C);
			}
			while (p > 1) {
				p /= 2;
				int l = 2 * p;
				int r = 2 * p + 1;
				forn (x, 2) {
					t[p][x] = mp(get_or(t[r][t[l][x].sc].fs, t[l][x].fs), t[r][t[l][x].sc].sc);
				}
			}
		}

		int get() {
			return get_or(t[1][0].fs, INIT);
		}
		
		void solve() {
			debug(n);
			debug(s, s + n);
			debug(q);
			debug(q_i, q_i + q);
			debug(q_s, q_s + q);
			m = 1;
			while (m < n) {
				m *= 2;
			}
			forn (i, m) {
				if (i < n) {
					set(i, s[i]);
				} else {
					set(i, C);
				}
			}
			ans[0] = get();
			forn (i, q) {
				set(q_i[i], q_s[i]);
				ans[i + 1] = get();
			}
		}
		
		void clear() {
			*this = Solution();
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
		while (sol.read()) {
			sol.solve();
			sol.write();
			sol.clear();
			puts("");
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