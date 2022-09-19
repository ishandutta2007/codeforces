#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
#endif

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 15;

struct Input {
	vi d;
	
	bool read () {
		int n;
		if (!(cin >> n)) {
			return 0;
		}
		string s;
		getline(cin, s);
		getline(cin, s);
		forn (i, n) {
			d.pb(s[i] - '0');
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	string ans;
	
	void write () {
		puts(ans.c_str());
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	
	void solve () {
		forn (i, sz(d)) {
			if (d[i] == 0) {
				d.erase(d.begin() + i);
				--i;
			} else if (d[i] == 1) {
				d.erase(d.begin() + i);
				--i;
			} else if (d[i] == 4) {
				d.erase(d.begin() + i);
				d.pb(3);
				d.pb(2);
				d.pb(2);
				--i;
			} else if (d[i] == 6) {
				d.erase(d.begin() + i);
				d.pb(5);
				d.pb(3);
				--i;
			} else if (d[i] == 8) {
				d.erase(d.begin() + i);
				d.pb(7);
				d.pb(2);
				d.pb(2);
				d.pb(2);
				--i;
			} else if (d[i] == 9) {
				d.erase(d.begin() + i);
				d.pb(7);
				d.pb(3);
				d.pb(3);
				d.pb(2);
				--i;
			}
		}
		debug(d);
		sort(all(d));
		ford (i, sz(d)) {
			ans += '0' + d[i]; 
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
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