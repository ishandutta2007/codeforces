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

const int N = 500000;

struct Input {
	int n;
	int a[N];

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
			scanf("%d", &a[i]);
		}
		return 1;
	}

	ll ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	list<pii>::iterator fnd[N];
	bool u[N];
	ve<pii> v;
	list<pii> l;

	void make (int i) {
		if (u[i]) {
			return;
		}
		u[i] = 1;
		auto it1 = fnd[i], it2 = fnd[i];
		--it1;
		++it2;
		ans += min(it1->fs, it2->fs);
	}
	
	void solve () {
		forn (i, n) {
			v.pb(mp(a[i], i));
		}
		l = list<pii>(all(v));
		sort(all(v));
		{
			auto it = l.begin();
			forn (i, n) {
				fnd[i] = it;
				++it;
			}
		}
		memset(u, 0, sizeof u);
		u[0] = u[n - 1] = 1;
		ans = 0;
		debug(v);
		forn (i, sz(v)) {
			debug(l);
			debug(v[i]);
			if (u[v[i].sc]) {
				auto it = fnd[v[i].sc];
				if (it != l.begin()) {
					--it;
					make(it->sc);
					++it;
				}
				++it;
				if (it != l.end()) {
					make(it->sc);
				}
				--it;
			} else {
				make(v[i].sc);
				l.erase(fnd[v[i].sc]);
			}
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