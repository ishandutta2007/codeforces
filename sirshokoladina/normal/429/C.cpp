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

const int N = 24;

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
	
	bool ans;
	
	void write () const {
		puts(ans ? "YES" : "NO");
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
	static const int M = 10;

	int m, k;

	bool d[1 << M][N];
	
	void solve () {
		sort(a, a + n);
		if (a[n - 1] != n) {
			ans = 0;
			return;
		}
		if (n == 1) {
			ans = 1;
			return;
		}
		if (a[n - 2] == n - 1) {
			ans = 0;
			return;
		}
		--n;
		reverse(a, a + n);
		int m = 0;
		while (m < n && a[m] > 1) {
			++m;
		}
		if (2 * m + 2 > n) {
			ans = 0;
			return;
		}
		k = n - m;
		forn (msk, 1 << m) {
			forn (j, k + 1) {
				if (!msk) {
					d[msk][j] = 1;
					continue;
				}
				int cnt = 0;
				int fs = -1;
				forn (i, m) {
					if (msk & (1 << i)) {
						++cnt;
						if (fs == -1) {
							fs = i;
						}
					}
				}
				d[msk][j] = 0;
				if (2 * cnt + 1 > cnt + j) {
					continue;
				}
				
				for (int msk1 = (1 << m) - 1; msk1 >= 0; --msk1) {
					msk1 &= msk - (1 << fs);
					
					int cnt1 = 0;
					int fs1 = -1;
					forn (i, m) {
						if (msk1 & (1 << i)) {
							++cnt1;
							if (fs1 == -1) {
								fs1 = i;
							}
						}
					}
					if (((fs1 == -1) ? 1 : a[fs1]) + 1 == a[fs]) {
						continue;
					}
					int j1 = a[fs] - 1 - cnt1;
					if (j1 < 0 || j1 > j) {
						continue;
					}
					if (d[msk1][j1] && d[msk - (1 << fs) - msk1][j - j1]) {
						d[msk][j] = 1;
						break;
					}
				}
			}
		}/*
		forn (i, 1 << m) {
			debug(mp(i, vector<int>(d[i], d[i] + k + 1)));
		}*/
		ans = d[(1 << m) - 1][k];
	}
	
	void clear () {
		*this = Solution();
	}
};

struct Accepted: Data {
	bool f[30];

	void solve () {
		ans = 0;
		sort(a, a + n);
		forn (i, n) {
			int k = 1, j = i;
			while (k < a[i] && j--) {
				if (!f[j] && a[j] <= a[i] - 2 && k + a[j] <= a[i]) {
					k += a[j];
					f[j] = 1;
				}
			}
			if (j < 0) {
				return;
			}
		}
		forn (i, n - 1) {
			if (!f[i]) {
				return;
			}
		}
		ans = 1;
	}
	
	void clear () {
		*this = Accepted();
	}
};

Input gen () {
	Input res;
	res.n = rand() % 20 + 1;
	memset(res.a, 0, sizeof res.a);
	forn (i, res.n) {
		++res.a[i];
		if (i < res.n - 1) {
			res.a[rand() % (res.n - i - 1) + i + 1] += res.a[i];
		}
	}
	sort(res.a, res.a + res.n, greater<int>());
	return res;
}

Solution sol;

int main () {/*
	Accepted ac;
	while (1) {
		Input in = gen();
		sol.init(in);
		sol.solve();
		ac.init(in);
		ac.solve();
		if (ac.ans) {
			debug(in.n);
			debug(vector<int>(in.a, in.a + in.n));
			debug(sol.ans);
			debug(ac.ans);
		}
		if (ac.ans != sol.ans) {
			debug(in.n);
			debug(vector<int>(in.a, in.a + in.n));
			debug(sol.ans);
			debug(ac.ans);
			return 0;
		}
		sol.clear();
		ac.clear();
	}
	return 0;*/
	
	
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