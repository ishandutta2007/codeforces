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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;

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
	ll ans;
	
	void write () {
		cout << ans << endl;
	}
};

struct Solution: Data {
	vi eq[N + 1];
	int fs1[N + 1], fs2[N + 1], lt1[N + 1], lt2[N + 1];
	
	int rb;
	ll sum;
	set<pa<pii, int> > omg;
	
	void cut () {
		auto it = omg.end();
		--it;
		auto p = *it;
		sum -= (it->fs.sc - it->fs.fs) * 1ll * it->sc;
		omg.erase(it);
		rb--;
		p.fs.sc--;
		if (p.fs.fs != p.fs.sc) {
			sum += (p.fs.sc - p.fs.fs) * 1ll * p.sc;
			omg.insert(p);
		}
	}
	
	void upd (int lb, int val) {
		if (lb >= rb) {
			return;
		}
		auto it = omg.lower_bound(mp(mp(lb, N + 1), 0));
		--it;
		if (val <= it->sc) {
			return;
		}
		int llb = it->fs.fs;
		int lval = it->sc;
	 	int rrb = it->fs.sc;
		while (it != omg.end() && val > it->sc) {
		 	rrb = it->fs.sc;
			auto jt = it;
			++it;
			sum -= (jt->fs.sc - jt->fs.fs) * 1ll * jt->sc;
			omg.erase(jt);
		}
		if (lb != llb) {
			sum += (lb - llb) * 1ll * lval;
			omg.insert(mp(mp(llb, lb), lval));
		}
		sum += (rrb - lb) * 1ll * val;
		omg.insert(mp(mp(lb, rrb), val));
	}
	
	vi ltlt[N];
	ve<pii> ltfs[N];
	
	
	void solve () {
		forn (i, N + 1) {
			fs1[i] = fs2[i] = N;
			lt1[i] = lt2[i] = -1;
		}
		forn (i, n) {
			eq[a[i]].pb(i);
		}
		forn (i, 1, N + 1) {
			for (int j = i; j <= N + 1; j += i) {
				forn (k, sz(eq[j])) {
					if (k >= 2 && k < sz(eq[j]) - 2) {
						continue;
					}
					int pos = eq[j][k];
					if (pos < fs1[i]) {
						fs2[i] = fs1[i];
						fs1[i] = pos;
					} else {
						umn(fs2[i], pos);
					}
					if (pos > lt1[i]) {
						lt2[i] = lt1[i];
						lt1[i] = pos;
					} else {
						umx(lt2[i], pos);
					}
				}
			}
		}
		forn (i, N + 1) {
			if (lt2[i] != -1) {
				ltlt[lt2[i]].pb(i);
				ltfs[lt1[i]].pb(mp(fs1[i], i));
			}
		}
		
		rb = n + 1;
		sum = 0;
		omg.insert(mp(mp(0, rb), 0));
		
		forn (i, N + 1) {
			if (lt2[i] != -1) {
				debug(mt(i, fs2[i]));
				upd(fs2[i] + 1, i);
				debug(mt(rb, sum, omg));
			}
		}
		
		debug(fs1, fs1 + 10);
		debug(fs2, fs2 + 10);
		debug(lt1, lt1 + 10);
		debug(lt2, lt2 + 10);
		
		ans = 0;
		ford (i, n) {
			debug(i);
			deepen();
			debug(mt(rb, sum, omg));
			cut();
			debug(mt(rb, sum, omg));
			
			ans += sum;
			
			if (i == 0) {
				break;
			}
			
			for (int x : ltlt[i]) {
				debug(x);
				upd(0, x);
				debug(mt(rb, sum, omg));
			}
			for (pii x : ltfs[i]) {
				debug(x);
				upd(x.fs + 1, x.sc);
				debug(mt(rb, sum, omg));
			}
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
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}