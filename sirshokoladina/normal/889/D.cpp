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

typedef pll pt;
#define x first
#define y second

pt operator + (const pt &a, const pt &b) {
	return pt(a.x + b.x, a.y + b.y);
}

pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

pt operator * (const pt &a, ll b) {
	return pt(a.x * b, a.y * b);
}

pt operator / (const pt &a, ll b) {
	return pt(a.x / b, a.y / b);
}

ll operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

ll operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

const int N = 2000;

struct Input {
	int n;
	pt a[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = pt(x, y);
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


namespace Main {
	
	struct Solution: Data {
	
		ll gcd (ll a_, ll b_) {
			if (a_ == 0) {
				return b_;
			}
			return gcd(b_ % a_, a_);
		}
		
		void solve () {
			pt sum(0, 0);
			forn (i, n) {
				sum = sum + a[i];
			}
			pt p;
			if (sum.x * 2 % n == 0 && sum.y * 2 % n == 0) {
				pt o = sum * 2 / n;
				sort(a, a + n);
				bool found = 0;
				forn (i, n) {
					if (a[i] + a[n - 1 - i] != o) {
						if (a[i] + a[n - 1 - i] < o) {
							p = a[i];
						} else {
							p = a[n - 1 - i];
						}
						found = 1;
						break;
					}
				}
				if (!found) {
					ans = -1;
					return;
				}
			} else {
				p = a[0];
			}
			
			ve<pt> qqq;
			forn (i, n) {
				pt v = (p + a[i]) * n - sum * 2;
				if (v == pt(0, 0)) {
					continue;
				}
				
				v = v / gcd(v.x, v.y);
				
				ve<ll> q;
				forn (j, n) {
					q.pb((a[j] * 2 - (p + a[i])) ^ v);
				}
				sort(all(q));
				debug(mt(p, a[i], sum, v, q));
				bool ok = 1;
				ll o = q.front() + q.back();
				forn (j, n) {
					ok &= (q[j] + q[n - 1 - j] == o);
				}
				if (ok) {
					qqq.pb(v);
				}
			}
			
			sort(all(qqq));
			ans = int(unique(all(qqq)) - qqq.begin());
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