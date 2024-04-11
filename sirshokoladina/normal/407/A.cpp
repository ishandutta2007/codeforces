#pragma comment(linker, "/STACK:268435456")

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>

#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>

#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = (v).begin(); i != (v).end(); ++i)
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
template <typename T> inline T abs (T x) {return x > 0 ? x : -x;}

template <typename It>
void outSeq (ostream & out, It begin, It end) {
	out << "[";
	while (begin != end) {
		out << *begin;
		++begin;
		if (begin != end) {
			out << ", ";
		}
	}
	
	out << "]";
}

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	outSeq(out, all(a));
	return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

struct Input {
	int a, b;
};

struct Data: Input {
	bool read () {
		return cin >> a >> b;
	}

	bool res;
	int x1, y1, x2, y2, x3, y3;
	
	void write () const {
		puts(res ? "YES" : "NO");
		if (res) {
			cout << x1 << ' ' << y1 << endl;
			cout << x2 << ' ' << y2 << endl;
			cout << x3 << ' ' << y3 << endl;
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int gcd (int a, int b) {
		if (!a) {
			return b;
		}
		return gcd(b % a, a);
	}

	void solve () {
		int d = gcd(a, b);
		res = 0;
		forn (x, d + 1) {
			int y = int(sqrtl(d * d - x * x));
			while (x * x + y * y < d * d) {
				++y;
			}
			if (x * x + y * y != d * d) {
				continue;
			}
			x1 = 0;
			y1 = 0;
			x2 = x * a / d;
			y2 = y * a / d;
			x3 = -y * b / d;
			y3 = x * b / d;
			if (x1 == x2 || x1 == x3 || x2 == x3) {
				continue;
			}
			if (y1 == y2 || y1 == y3 || y2 == y3) {
				continue;
			}
			res = 1;
			return;
		}
	}
	
	Solution (const Data &data = Data()): Data(data) {
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
#endif
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}