#include <bits/stdc++.h>

using namespace std;

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

#ifdef SG
	#include <E:\YandexDisk\Programming\SportProgramming\MyLibs\debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline void umx (T1& a, T2 b) {if (a < b) {a = b;}}
template<typename T1, typename T2> inline void umn (T1& a, T2 b) {if (b < a) {a = b;}}

const int N = 100;

struct Input {
	int n;
	ld p[N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			cin >> p[i];
		}
		return 1;
	}

	ld ans;
	
	void write () {
		cout.precision(20);
		cout.setf(ios::showpoint | ios::fixed);
		cout << (double)ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
		ans = 0;
		ld p0 = 1, p1 = 0;
		sort(p, p + n);
		ford (i, n) {
			p1 = p0 * p[i] + p1 * (1 - p[i]);
			p0 *= (1 - p[i]);
			ans = max(ans, p1);
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