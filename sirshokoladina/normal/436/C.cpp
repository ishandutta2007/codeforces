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
#define mt make_tuple
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
ostream & outSeq (ostream & out, It begin, It end) {
	out << "[";
	while (begin != end) {
		out << *begin;
		++begin;
		if (begin != end) {
			out << ", ";
		}
	}
	return out << "]";
}

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	return outSeq(out, all(a));
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	return out << "(" << p.first << ", " << p.second << ")";
}

namespace aux {
	template<typename Tuple, size_t Size = tuple_size<Tuple>::value> struct print_tuple;
	
	template<typename Tuple> struct print_tuple<Tuple, 0> {
		ostream & operator () (ostream & out, Tuple t) {
			return out;
		}
	};
	
	template<typename Tuple, size_t Size> struct print_tuple: private print_tuple<Tuple, Size - 1> {
		ostream & operator () (ostream & out, Tuple t) {
			print_tuple<Tuple, Size - 1>::operator()(out, t);
			if (Size > 1) {
				out << ", ";
			}
			return out << get<Size - 1>(t);
		}
	};
}

template<typename... Args>
ostream & operator << (ostream & out, tuple<Args...> const & t) {
	out << "(";
	aux::print_tuple<tuple<Args...> >()(out, t);
	return out << ")";
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

const int K = 1000;
const int N = 10;

struct Input {
	int n, m, k, w;
	string s[K][N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m >> k >> w)) {
			return 0;
		}
		getline(cin, s[0][0]);
		forn (i, k) {
			forn (j, n) {
				getline(cin, s[i][j]);
			}
		}
		return 1;
	}

	int res;
	vector<pii> ans;
	
	void write () {
		cout << res << endl;
		forn (i, ans.size()) {
	    	cout << ans[i].fs + 1 << ' ' << ans[i].sc + 1 << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int p[K + 1];

	int P (int v) {
		return (p[v] == v) ? v : (p[v] = P(p[v]));
	}

	int rnd = 0;

	bool uni (int u, int v) {
		u = P(u);
		v = P(v);
		if (u == v) {
			return 0;
		}
		if (rnd ^= 1) {
			swap(u, v);
		}
		p[u] = v;
		return 1;
	}

	vector<int> g[K + 1];

	void dfs (int v, int pr) {
		if (pr != -1) {
			ans.pb(mp(v, (pr == k) ? -1 : pr));
		}
		forn (i, g[v].size()) {
			if (g[v][i] != pr) {
				dfs(g[v][i], v);
			}
		}
	}

	void solve () {
		forn (i, k + 1) {
			p[i] = i;
		}
		vector<pair<int, pii> > e;
		forn (i, k) {
			e.pb(mp(n * m, mp(i, k)));
		}
		forn (i, k) {
			forn (j, i) {
				int cnt = 0;
				forn (x, n) {
					forn (y, m) {
						cnt += s[i][x][y] != s[j][x][y]; 
					}
				}
				e.pb(mp(cnt * w, mp(i, j)));
			}
		}
		sort(all(e));
		res = 0;
		forn (i, e.size()) {
			if (uni(e[i].sc.fs, e[i].sc.sc)) {
				res += e[i].fs;
				g[e[i].sc.fs].pb(e[i].sc.sc);
				g[e[i].sc.sc].pb(e[i].sc.fs);
			}
		}
		dfs(k, -1);
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