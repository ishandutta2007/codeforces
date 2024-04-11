#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
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
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
	int c0, c1, k;
	
	bool read () {
		int n;
		if (!(cin >> n >> k)) {
			return 0;
		}
		forn (i, n) {
			int a;
			scanf("%d", &a);
			if (a & 1) {
				c1++;
			} else {
				c0++;
			}
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
		puts(ans ? "Stannis" : "Daenerys");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		int rest = c0 + c1 - k;
		if (rest == 0) {
			ans = c1 & 1;
			return;
		}
		bool minus_l = (rest & 1);
		bool minus_r = (k & 1) ^ (rest & 1);
		ve<pii> v;
		if (minus_l) {
			v.pb(mp(1, 0));
		}
		v.pb(mp(k + 2 - minus_l - minus_r, 1));
		if (minus_r) {
			v.pb(mp(1, 0));
		}
		debug(v);
		rest--;
		while (rest) {
			v.back().fs++;
			forn (i, sz(v) - 1) {
				if (v[i].sc == 0) {
					v[i].fs++;
					v[i + 1].fs--;
				}
			}
			forn (i, sz(v)) {
				v[i].sc ^= 1;
			}
			auto w = v;
			v.clear();
			forn (i, sz(w)) {
				if (!w[i].fs) {
					continue;
				}
				if (sz(v) && w[i].sc == v.back().sc) {
					v.back().fs += w[i].fs;
				} else {
					v.pb(w[i]);
				}
			}
			debug(v);
			--rest;
		}
		int q = c1;
		forn (i, sz(v)) {
			if (v[i].fs > q) {
				ans = v[i].sc;
				break;
			}
			q -= v[i].fs;
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	return 0;
}