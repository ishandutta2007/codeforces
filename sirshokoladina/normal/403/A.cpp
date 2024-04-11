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

const int N = 24;

struct Input {
	int n, p;
};

struct Data: Input {
	bool read () {
		return cin >> n >> p;
	}
	
	bool a[N][N];
	
	void write () const {
		forn (i, n) {
			forn (j, i) {
				if (a[i][j]) {
					cout << j + 1 << ' ' << i + 1 << endl;
				}
			}
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		memset(a, 0, sizeof a);
		forn (i, n) {
			a[i][(i + 1) % n] = a[(i + 1) % n][i] = 1;
			a[i][(i + 2) % n] = a[(i + 2) % n][i] = 1;
		}
		int k = 0;
		forn (i, n) {
			forn (j, i) {
				if (k < p && !a[i][j]) {
					a[i][j] = a[j][i] = 1;
					++k;
				}
			}
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
	int n;
	cin >> n;
	forn (i, n) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}