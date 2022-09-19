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

const int N = 2000;

struct Input {
	int n, x;
	int t[N], h[N], m[N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> x)) {
			return 0;
		}
		forn (i, n) {
			cin >> t[i] >> h[i] >> m[i];
		}
		return 1;
	}

	int ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	bool u[N];

	void solve () {
		ans = 0;
		forn (q0, 2) {
			int y = x;
			memset(u, 0, sizeof u);
			int q = q0;
			int cnt = 0;
			while (1) {
				int bst = -1;
				int mx = -1;
				forn (i, n) {
					if (t[i] == q && h[i] <= y && !u[i] && m[i] > mx) {
						bst = i;
						mx = m[i];
					}
				}
				if (bst == -1) {
					break;
				}
				cnt++;
				y += mx;
				u[bst] = 1;
				q ^= 1;
			}
			ans = max(ans, cnt);
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