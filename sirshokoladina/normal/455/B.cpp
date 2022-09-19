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

const int N = 100000;

struct Input {
	int n, k;
	string s[N];
	
	bool read () {
		if (!(cin >> n >> k)) {
			return 0;
		}
		string t;
		getline(cin, t);
		forn (i, n) {
			getline(cin, s[i]);
		}
		return 1;
	}
	
	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans;

	void write () {
		puts(ans ? "First" : "Second");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

typedef pii mat;

mat operator * (mat a, mat b) {
	mat res = mp(0, 0);
	if (a.fs) {
		res.fs |= b.fs;
		res.sc |= b.sc;
	}
	if (a.sc) {
		res.fs |= !b.fs;
		res.sc |= !b.sc;
	}
	return res;
}

struct Solution: Data {
	vi nx[N];
	mat w[N];
	
	void calc (int i) {
		w[i] = mp(0, 0);
		for (int j: nx[i]) {
			calc(j);
			w[i].fs |= !w[j].fs;
			w[i].sc |= !w[j].sc;
		}
		if (!sz(nx[i])) {
			w[i] = mp(1, 0);
		}
		debug(mp(i, w[i]));
	}
	
	void solve () {
		sort(s, s + n);
		n = unique(s, s + n) - s;
		int t = 1;
		vi q(1, 0);
		string cur = "";
		forn (i, n) {
			int j = 0;
			while (j < sz(cur) && j < sz(s[i]) && cur[j] == s[i][j]) {
				++j;
			}
			q.resize(j + 1);
			while (j < sz(s[i])) {
				nx[q.back()].pb(t);
				q.pb(t);
				++t;
				++j;
			}
			cur = s[i];
		}
		calc(0);
		mat a = w[0];
		debug(w[0]);
		mat pw = mp(1, 0);
		while (k) {
			if (k & 1) {
				pw = pw * a;
			}
			a = a * a;
			k >>= 1;
		}
		debug(pw);
		ans = pw.sc;
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