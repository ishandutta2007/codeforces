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

const int N = 100000;
const int M = 100000;
const int K = 100;

const ll mod = 1000000007;

struct Input {
	int n, m;
	ll a[N];
	int l[M], r[M], k[M];
};

struct Data: Input {
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			int x;
			scanf("%d", &x);
			a[i] = x;
		}
		forn (i, m) {
			scanf("%d%d%d", &l[i], &r[i], &k[i]);
			l[i]--;
		}
		return 1;
	}

	ll ans[N];
	
	void write () const {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", int(ans[i]));
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	vector<int> nums[K + 1];
	ll s[2][N + 1];
	ll c[K + 1][N];
	
	void solve () {
		forn (i, K + 1) {
			forn (j, N) {
				if (!i || !j) {
					c[i][j] = 1;
					continue;
				}
				c[i][j] = (c[i - 1][j] + c[i][j - 1]) % mod;
			}
		}
		memset(s, 0, sizeof s);
		ford (i, K + 1) {
			memset(s[i & 1], 0, sizeof s[i & 1]);
			forn (j, m) {
				if (k[j] >= i) {
					if (k[j] == i) {
						(s[i & 1][l[j]] += 1) %= mod;
					}
					(s[i & 1][r[j]] += mod - c[k[j] - i][r[j] - l[j] - 1]) %= mod;
				}
			}
			forn (j, n) {
				if (j) {
					(s[i & 1][j] += s[i & 1][j - 1]) %= mod;
				}
				(s[i & 1][j] += s[(i + 1) & 1][j]) %= mod;
			}
		}
		forn (i, n) {
			ans[i] = (s[K & 1][i] + a[i]) % mod;
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