#include <cstdio>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>

#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>

#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

#ifdef SG
	#define show(x) cerr << x
#else
	#define show(x)
#endif
#define debug(x) show(#x << ": " << (x) << endl)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template <typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template <typename T> inline T abs (T x) {return x > T() ? x : -x;}

template <typename It>
void outSeq (ostream & out, It begin, It end, bool el = true) {
	out << "[";
	while (begin != end) {
		out << *begin;
		++begin;
		if (begin != end) {
			out << ", ";
		}
	}

	out << "]";
	if (el) {
		out << "\n";
	}
}

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	outSeq(out, all(a), false);
	return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

void showTime () {
#ifdef SG
	static double prev;
	static bool first = true;

	double curr = (double)clock() / CLOCKS_PER_SEC;

	cerr.setf(ios::fixed);
	cerr.precision(3);
	cerr << "<";
	if (!first) {
		cerr << curr - prev << "s, ";
	}
	cerr << curr << "s>\n";
	 
	first = false;
	prev = curr;
#endif
}

const int N = 100000;

struct Input {
	int n;
	int a[N];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
	}

	ll ans;
	
	void write () const {
		cout << ans << endl;
	}
	
	void init (const Input &input) {
		static_cast<Input&>(*this) = input;
	}
	
	void run () {
		Input &curr = static_cast<Input&>(*this);
		Input input = curr;
		solve();
		curr = input;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

typedef pair<ll, ll> pt;
#define x first
#define y second

inline pt operator - (const pt &a, const pt &b) {
	return pt(a.x - b.x, a.y - b.y);
}

inline ll operator * (const pt &a, const pt &b) {
	return a.x * b.x + a.y * b.y;
}

struct Solution: Data {
	vector<pt> p;

	ll calc (int l, int r) {
		if (r - l < 2) {
			return 2e18;
		}
		int m = (r + l) / 2;
		ll res = min(calc(l, m), calc(m, r));
		vector<pt> v, w;
		for (int i = l; i < m; ++i) {
			if (p[i].x + sqrtl(res) + 1 > p[m].x) {
				v.pb(pt(p[i].y, p[i].x));
			}
		}
		for (int i = m; i < r; ++i) {
			if (p[i].x - sqrtl(res) - 1 < p[m].x) {
				w.pb(pt(p[i].y, p[i].x));
			}
		}
		sort(all(v));
		sort(all(w));
		for (int i = 0, j = 0; i < sz(v); ++i) {
			while (j < sz(w) && w[j].x < v[i].x - sqrtl(res) - 1) {
				++j;
			}
			int k = j;
			while (k < sz(w) && w[k].x < v[i].x + sqrtl(res) + 1) {
				res = min(res, sqr(w[k] - v[i]));
				++k;
			}
		}
		return res;
	}

	void solve () {
		{
			ll s = 0;
			forn (i, n) {
				s += a[i];
				p.pb(pt(i, s));
			}
		}
		sort(all(p));
		ans = calc(0, p.size());
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
		sol.run();
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