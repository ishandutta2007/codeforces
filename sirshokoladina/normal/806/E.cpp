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

const int N = 500000;

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
	
	void gen () {
		n = rand() % 10 + 1;
		forn (i, n) {
			a[i] = rand() % 7 - 3;
		}
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write () {
		forn (i, n) {
			printf("%d\n", ans[i]);
		}
	}
};


namespace Main {

	const int inf = 1000000000;
	
	struct Solution: Data {
		int sgn_ (int x) {
			if (x < 0) {
				return -1;
			}
			return x > 0;
		}
		
		int b[N + 1];
		int pos[N];
		
		set<int> on;
		
		set<int> zero, posi, nega;
		
		int upd[4 * N];
		pii t_p[4 * N];
		pii t_n[4 * N];
		
		void push (int v, int lb, int rb) {
			if (rb - lb > 1) {
				upd[2 * v + 1] += upd[v];
				upd[2 * v + 2] += upd[v];
			}
			if (t_p[v].sc != -1) {
				t_p[v].fs += upd[v];
			}
			if (t_n[v].sc != -1) {
				t_n[v].fs -= upd[v];
			}
			upd[v] = 0;
		}
		
		void add (int v, int lb, int rb, int l, int r, int val) {
			if (rb <= l || lb >= r) {
				push(v, lb, rb);
				return;
			}
			if (rb <= r && lb >= l) {
				upd[v] += val;
				push(v, lb, rb);
				return;
			}
			push(v, lb, rb);
			add(2 * v + 1, lb, (lb + rb) / 2, l, r, val);
			add(2 * v + 2, (lb + rb) / 2, rb, l, r, val);
			t_p[v] = min(t_p[2 * v + 1], t_p[2 * v + 2]);
			t_n[v] = min(t_n[2 * v + 1], t_n[2 * v + 2]);
		}
		
		pii fnd_p (int v, int lb, int rb, int l, int r) {
			if (rb <= l || lb >= r) {
				return mp(inf, -1);
			}
			push(v, lb, rb);
			if (rb <= r && lb >= l) {
				return t_p[v];
			}
			return min(
				fnd_p(2 * v + 1, lb, (lb + rb) / 2, l, r),
				fnd_p(2 * v + 2, (lb + rb) / 2, rb, l, r)
			);
		}
		
		pii fnd_n (int v, int lb, int rb, int l, int r) {
			if (rb <= l || lb >= r) {
				return mp(inf, -1);
			}
			push(v, lb, rb);
			if (rb <= r && lb >= l) {
				return t_n[v];
			}
			return min(
				fnd_n(2 * v + 1, lb, (lb + rb) / 2, l, r),
				fnd_n(2 * v + 2, (lb + rb) / 2, rb, l, r)
			);
		}
		
		void put (int v, int lb, int rb, int i, int val) {
			push(v, lb, rb);
			if (rb <= i || lb > i) {
				return;
			}
			if (rb - lb == 1) {
				if (posi.count(i)) {
					if (val == inf) {
						t_p[v] = mp(inf, -1);
					} else {
						t_p[v] = mp(val, i);
					}
				}
				if (nega.count(i)) {
					if (val == inf) {
						t_n[v] = mp(inf, -1);
					} else {
						t_n[v] = mp(-val, i);
					}
				}
				return;
			}
			put(2 * v + 1, lb, (lb + rb) / 2, i, val);
			put(2 * v + 2, (lb + rb) / 2, rb, i, val);
			t_p[v] = min(t_p[2 * v + 1], t_p[2 * v + 2]);
			t_n[v] = min(t_n[2 * v + 1], t_n[2 * v + 2]);
		}
		
		int get (int i) {
			int v = 0;
			int lb = 0, rb = n;
			while (rb - lb > 1) {
				push(v, lb, rb);
				if (i < (lb + rb) / 2) {
					rb = (lb + rb) / 2;
					v = 2 * v + 1;
				} else {
					lb = (lb + rb) / 2;
					v = 2 * v + 2;
				}
			}
			push(v, lb, rb);
			if (posi.count(i)) {
				return t_p[v].fs;
			}
			if (nega.count(i)) {
				return -t_n[v].fs;
			}
			return 0;
		}
		
		void solve () {
			deepen(0);
			forn (i, 4 * N) {
				upd[i] = 0;
				t_p[i] = mp(inf, -1);
				t_n[i] = mp(inf, -1);
			}
			{
				ve<pii> v;
				forn (i, n) {
					v.pb(mp(a[i], i));
				}
				sort(all(v));
				forn (i, n) {
					b[i] = v[i].fs;
					pos[v[i].sc] = i;
				}
			}
			b[n] = 0;
			on.insert(n);
			
			int cur_ans = 0;
			
			debug(b, b + n);
			
			forn (i, n) {
				int next = *on.lower_bound(pos[i]);
				debug(mt(zero, nega, posi));
				debug(upd, upd + 7);
				debug(t_n, t_n + 7);
				debug(t_p, t_p + 7);
				int val = (next == n) ? cur_ans : get(next);
				debug(mt(i, pos[i], next, val));
				val += b[next] - b[pos[i]];
				int sgn = sgn_(val);
				debug(mt(val, sgn));
				if (sgn == 1) {
					int rb = n;
					int rsgn = -2;
					
					{
						auto it = zero.lower_bound(pos[i]);
						if (it != zero.end() && umn(rb, *it)) {
							rsgn = 0;
						}
					}
					{
						pii res = fnd_p(0, 0, n, pos[i], n);
						if (res.sc != -1 && res.fs == 1 && umn(rb, res.sc)) {
							rsgn = 1;
						}
					}
					
					add(0, 0, n, pos[i], rb, -1);
					
					if (rsgn == 0) {
						zero.erase(rb);
						nega.insert(rb);
						put(0, 0, n, rb, -1);
					} else if (rsgn == 1) {
						put(0, 0, n, rb, inf);
						posi.erase(rb);
						zero.insert(rb);
					} else {
						cur_ans--;
					}
					
					posi.insert(pos[i]);
				} else if (sgn == -1) {
					int rb = n;
					int rsgn = -2;
					
					{
						auto it = zero.lower_bound(pos[i]);
						if (it != zero.end() && umn(rb, *it)) {
							rsgn = 0;
						}
					}
					{
						pii res = fnd_n(0, 0, n, pos[i], n);
						debug(res);
						if (res.sc != -1 && res.fs == 1 && umn(rb, res.sc)) {
							rsgn = -1;
						}
					}
					
					debug(mt(rb, rsgn));
					
					add(0, 0, n, pos[i], rb, 1);
					
					if (rsgn == 0) {
						zero.erase(rb);
						posi.insert(rb);
						put(0, 0, n, rb, 1);
					} else if (rsgn == -1) {
						put(0, 0, n, rb, inf);
						nega.erase(rb);
						zero.insert(rb);
					} else {
						cur_ans++;
					}
					
					nega.insert(pos[i]);
				} else {
					zero.insert(pos[i]);
				}
				
				on.insert(pos[i]);
				put(0, 0, n, pos[i], val);
				ans[i] = cur_ans;
			}
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


namespace Stupid {
	
	struct Solution: Data {
		
		void solve () {
			forn (i, n) {
				vi v(a, a + i + 1);
				sort(all(v));
				ans[i] = 0;
				forn (j, sz(v)) {
					if (ans[i] < v[j]) {
						++ans[i];
					} else if (ans[i] > v[j]) {
						--ans[i];
					}
				}
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
		
		Input in;
		Stupid::Solution stu;
		
		while (1) {
			in.gen();
			sol.init(in);
			stu.init(in);
			sol.solve();
			stu.solve();
			forn (i, memcmp(sol.ans, stu.ans, in.n * sizeof(int)) != 0) {
				debug(in.a, in.a + in.n);
				debug(sol.ans, sol.ans + in.n);
				debug(stu.ans, stu.ans + in.n);
			}
			sol.clear();
			stu.clear();
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