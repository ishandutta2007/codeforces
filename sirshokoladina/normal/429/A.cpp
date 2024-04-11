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
void outSeq (ostream & out, It begin, It end, bool el = true) {
	out << "[";
	while (begin != end) {
		out << *begin;
		++begin;
		if (begin != end) {
			out << ", ";
		}
	}

	out << "]";
	if (el) {
		out << "\n";
	}
}

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	outSeq(out, all(a), false);
	return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
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

const int N = 100000;

struct Input {
	int n;
	vector<int> e[N];
	int st[N], fn[N];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		forn (i, n) {
			scanf("%d", &st[i]);
		}
		forn (i, n) {
			scanf("%d", &fn[i]);
		}
	}

	vector<int> ans;
	
	void write () const {
		cout << ans.size() << endl;
		for (auto v: ans) {
			cout << v + 1 << endl;
		}
	}
	
	void init (const Input &input) {
		static_cast<Input&>(*this) = input;
	}
	
	void run () {
		Input &curr = static_cast<Input&>(*this);
		Input input = curr;
		solve();
		curr = input;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void dfs (int v, int p, int a1, int a2) {
		if (st[v] ^ a1 != fn[v]) {
			a1 ^= 1;
			ans.pb(v);
		}
		for (auto to: e[v]) if (to != p) {
			dfs(to, v, a2, a1);
		}
	}
	
	void solve () {
		dfs(0, -1, 0, 0);
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
		sol.run();
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