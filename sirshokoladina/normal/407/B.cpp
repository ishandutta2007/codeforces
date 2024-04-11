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

const int N = 1000;
const ll mod = 1000000007;

struct Input {
	int n;
	int p[N];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			cin >> p[i];
			p[i]--;
		}
		return 1;
	}

	ll ans;
	
	void write () const {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ll d[N], s[N + 1];
	
	void solve () {
		s[0] = 0;
		forn (i, n) {
			d[i] = (s[i] - s[p[i]] + 2 + mod) % mod;
			s[i + 1] = (s[i] + d[i]) % mod;
		}
		ans = s[n];
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