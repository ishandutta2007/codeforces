#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

#ifdef SG
	#include <E:\YandexDisk\Programming\SportProgramming\MyLibs\debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline void umx (T1& a, T2 b) {if (a < b) {a = b;}}
template<typename T1, typename T2> inline void umn (T1& a, T2 b) {if (b < a) {a = b;}}

typedef pa<ld, ld> pt;
#define x first
#define y second

pt operator + (const pt &a, const pt &b) {
	return mp(a.x + b.x, a.y + b.y);
}

pt operator - (const pt &a, const pt &b) {
	return mp(a.x - b.x, a.y - b.y);
}

pt operator * (const pt &a, ld b) {
	return mp(a.x * b, a.y * b);
}

pt operator / (const pt &a, ld b) {
	return mp(a.x / b, a.y / b);
}

ld operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

ld operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

const int N = 1000;

struct Input {
	ld w, h;
	int n;
	pt a[N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> w >> h >> n)) {
			return 0;
		}
		forn (i, n) {
			cin >> a[i].x >> a[i].y;
		}
		return 1;
	}

	ld ans;
	
	void write () {
		assert(isnormal(ans));
		assert(ans > sqrtl(0.5) - 0.01);
		assert(ans < sqrtl(w * w + h * h) + 0.01);
		cout.precision(20);
		cout.setf(ios::showpoint | ios::fixed);
		cout << 
#ifdef SG 
		(double)
#endif
		ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

const ld eps = 1e-13l;

struct Solution: Data {
	ve<pa<pt, int> > v;

	vi make (vi num, ld &res) {
		vi q;
		forn (i, sz(num)) {
			debug(q);
			while (sz(q) > 1 && ((v[q[sz(q) - 2]].fs - v[num[i]].fs) ^ (v[q[sz(q) - 1]].fs - v[num[i]].fs)) < 0) {
				debug(pa<double, double>(v[q[sz(q) - 2]].fs));
				debug(pa<double, double>(v[q[sz(q) - 1]].fs));
				debug(pa<double, double>(v[num[i]].fs));
				q.pop_back();
			}
			q.pb(num[i]);
		}
		debug(q);
		forn (i, sz(q) - 1) {
			res = min(res, (v[q[i]].fs ^ v[q[i + 1]].fs) / sqrtl(sqr(v[q[i]].fs - v[q[i + 1]].fs)));
		}
		debug(double(res));
		return q;
	}
	
	ld calc () {
		debug(ve<pa<pa<double, double>, int> >(all(v)));
		vi num;
		forn (i, sz(v)) {
			num.pb(i);
		}
		num.pb(0);
		ld res = 100;
		vi q = make(num, res);
		q.pop_back();
		debug(q);
		forn (i, 2) {
			q.pb(q[i]);
		}
		forn (i, sz(q) - 2) {
			if (v[q[i + 1]].sc == 1) {
				debug(q[i + 1]);
				deepen();
				num = vi();
				for (int j = q[i]; j != q[i + 2]; (++j) %= sz(v)) {
					if (j != q[i + 1]) {
						num.pb(j);
					}
				}
				num.pb(q[i + 2]);
				vi t = make(num, res);
			}
		}
		return res;
	}

	int m;
	pt b[N + 10];
	
	void solve () {
		//deepen(0);
		ans = 0;
		forn (i, n) {
		//	deepen(i == 0, "");
			m = 0;
			forn (j, n) {
				if (a[i] != a[j]) {
					b[m++] = a[j] - a[i];
				}
			}
			b[m++] = mp(-a[i].x * 2 - eps, 0);
			b[m++] = mp(-a[i].x * 2 - eps, 0);
			b[m++] = mp(0, -a[i].y * 2 - eps);
			b[m++] = mp(0, -a[i].y * 2 - eps);
			b[m++] = mp((w - a[i].x) * 2 + eps, 0);
			b[m++] = mp((w - a[i].x) * 2 + eps, 0);
			b[m++] = mp(0, (h - a[i].y) * 2 + eps);
			b[m++] = mp(0, (h - a[i].y) * 2 + eps);
			debug(ve<pa<double, double> >(b, b + m));
			map<pt, int> w;
			forn (j, m) {
				w[b[j]]++;
			}
			
			v = ve<pa<pt, int> >(all(w));
			sort(all(v), [] (const pa<pt, int> &a, const pa<pt, int> &b) {
			
				bool q1 = a.fs < mp(0.l, 0.l);
				bool q2 = b.fs < mp(0.l, 0.l);
				if (q1 ^ q2) {
					return q2;
				}
				ld s1 = sqr(a.fs);
				ld s2 = sqr(b.fs);
				ld w = (a.fs ^ b.fs);
				if (fabsl(w) < (s1 < 0.5l ? eps : 1) * (s2 < 0.5l ? eps : 1) * 0.5l) {
					return s1 > s2;
				}
				return w > 0;
			});
			forn (i, sz(v)) {
				v[i].fs = v[i].fs / sqr(v[i].fs);
			}
			int bst = 0;
			forn (i, sz(v)) {
				if (v[i].fs < v[bst].fs) {
					bst = i;
				}
			}
			rotate(v.begin(), v.begin() + bst, v.end());
			
			ans = max(ans, 0.5l / calc());
			debug((double)ans);
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
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