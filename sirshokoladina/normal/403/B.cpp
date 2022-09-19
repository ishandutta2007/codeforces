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

const int N = 5000;

struct Input {
	int n, m;
	int a[N], b[N];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			cin >> a[i];
		}
		forn (i, m) {
			cin >> b[i];
		}
		return 1;
	}

	int ans = 0;
	
	void write () const {
		cout << ans << endl;
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

	int val (int p) {
		int *it = lower_bound(b, b + m, p);
		if (it < b + m && *it == p) {
			return -1;
		}
		return 1;
	}

	int calc (int k) {
		int ans = 0;
		for (int j = 2; j * j <= k; ++j) {
			while (k % j == 0) {
				k /= j;
				ans += val(j);
			}
		}
		if (k > 1) {
			ans += val(k);
		}
		return ans;
	}
	
	int d[N + 1];
	
	void solve () {
		sort(b, b + m);
		ans = 0;
		d[0] = 0;
		forn (i, n) {
			d[i + 1] = gcd(d[i], a[i]);
			ans += calc(a[i]);
		}
		int cur = 1;
		ford (i, n + 1) {
			int s = calc(d[i] / cur);
			if (s < 0) {
				ans -= s * i;
				cur = d[i];
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
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}