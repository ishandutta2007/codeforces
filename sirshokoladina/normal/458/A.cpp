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

struct Input {
	string s1, s2;

	bool read () {
		return cin >> s1 >> s2;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		puts(ve<string>({"<", "=", ">"})[ans + 1].c_str());
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	string calc (string s) {
		reverse(all(s));
		s += string(sz(s), '0');
		forn (i, sz(s)) {
			int j = i;
			while (j < sz(s) && s[j] == '1') {
				++j;
			}
			while (j - i >= 2) {
				s[j] = '1';
				s[j - 1] = '0';
				s[j - 2] = '0';
				j -= 2;
			}
		}
		while(sz(s) && s.back() == '0') {
			s.resize(sz(s) - 1);
		}
		reverse(all(s));
		return s;
	}
	
	void solve () {
		s1 = calc(s1);
		s2 = calc(s2);
		debug(s1);
		debug(s2);
		if (sz(s1) != sz(s2)) {
			if (sz(s1) < sz(s2)) {
				ans = -1;
			} else {
				ans = 1;
			}
			return;
		}
		if (s1 != s2) {
			if (s1 < s2) {
				ans = -1;
			} else {
				ans = 1;
			}
			return;
		}
		ans = 0;
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