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

const int N = 1000000;

struct Input {
	int n;
	int p[N];

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		++n;
		p[0] = -1;
		forn (i, n - 1) {
			scanf("%d", &p[i + 1]);
			--p[i + 1];
		}
		return 1;
	}

	int ans[N];
	
	void write () {
		forn (i, n - 1) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i + 1]);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int R[N];
	pii r[N];

	bool upd (int v) {
		int nw = r[v].fs + (!v || r[v].sc > 1);
		debug(v);
		debug(r[v]);
		debug(nw);
		if (R[v] < nw) {
			R[v] = nw;
			return 1;
		}
		return 0;
	}

	void solve () {
		forn (i, n) {
			R[i] = 0;
			r[i] = mp(-1, 0);
		}
		forn (i, n) {
			int v = i;
			while (v) {
				if (r[p[v]].fs < R[v]) {
					r[p[v]] = mp(R[v], 0);
				}
				if (r[p[v]].fs == R[v]) {
					r[p[v]].sc++;
				}
				if (!upd(p[v])) {
					break;
				}
				v = p[v];
			}
			ans[i] = R[0];
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