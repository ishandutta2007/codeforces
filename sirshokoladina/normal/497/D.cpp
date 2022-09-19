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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

typedef pa<ld, ld> pt;
#define x first
#define y second

inline pt operator + (const pt &a, const pt &b) {
	return pt(a.x + b.x, a.y + b.y);
}

inline pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline pt operator * (const pt &a, ld b) {
	return pt(a.x * b, a.y * b);
}

inline ld operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

inline ld operator ^ (const pt &a, const pt &b) {
	return a.x * b.y - a.y * b.x;
}

ld len (const pt &a) {
	return sqrtl(sqr(a));
}

const int N = 1000;

struct Input {
	pt p;
	int n;
	pt a[N];
	pt q;
	int m;
	pt b[N];
	
	bool read () {
		if (!(cin >> p.x >> p.y)) {
			return 0;
		}
		cin >> n;
		forn (i, n) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = pt(x, y);
		}
		cin >> q.x >> q.y;
		cin >> m;
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			b[i] = pt(x, y);
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
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

const ld eps = 1e-9;

struct Solution: Data {
	ld r;
	
	bool check (pt a, pt b, pt c) {
		b = b - a;
		c = c - a;
		ld db = len(b);
		ld dc = len(c);
		ld mxd = max(db, dc);
		ld mnd = min(db, dc);
		if (b * (b - c) > 0 && c * (c - b) > 0) {
			mnd = fabsl(b ^ c) / len(c - b);
		}
		return r > mnd - eps && r < mxd + eps;
	}
	
	void solve () {
		r = len(p - q);
		ans = 0;
		forn (i, n) {
			forn (j, m) {
				if (check(a[i] - p + q, b[j], b[(j + 1) % m])) {
					ans = 1;
				}
				if (check(b[j] - q + p, a[i], a[(i + 1) % n])) {
					ans = 1;
				}
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