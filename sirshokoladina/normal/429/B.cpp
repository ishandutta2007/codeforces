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

const int N = 1000;

struct Input {
	int n, m;
	int a[N][N];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			forn (j, m) {
				scanf("%d", &a[i][j]);
			}
		}
		return 1;
	}

	int ans;
	
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

struct Solution: Data {
	int s00[N][N], s01[N][N], s10[N][N], s11[N][N];

	void sym0 (int x[N][N]) {
		forn (i, n / 2) {
			forn (j, m) {
				swap(x[i][j], x[n - 1 - i][j]);
			}
		}
	}

	void sym1 (int x[N][N]) {
		forn (i, n) {
			forn (j, m / 2) {
				swap(x[i][j], x[i][m - 1 - j]);
			}
		}
	}

	void make (int x[N][N]) {
		forn (i, n) {
			forn (j, m) {
				x[i][j] = 0;
				if (i > 0) {
					x[i][j] = max(x[i][j], x[i - 1][j]);
				}
				if (j > 0) {
					x[i][j] = max(x[i][j], x[i][j - 1]);
				}
				x[i][j] += a[i][j];
			}
		}
	}

	void solve () {
		make(s00);
		
		sym1(a);
		make(s01);
		sym1(a);
		sym1(s01);

		sym0(a);
		make(s10);
		sym0(a);
		sym0(s10);
		
		sym0(a);
		sym1(a);
		make(s11);
		sym0(a);
		sym1(a);
		sym0(s11);
		sym1(s11);

		ans = 0;
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				ans = max(ans, s00[i - 1][j] + s01[i][j + 1] + s10[i][j - 1] + s11[i + 1][j]);
				ans = max(ans, s00[i][j - 1] + s01[i - 1][j] + s10[i + 1][j] + s11[i][j + 1]);
			}
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