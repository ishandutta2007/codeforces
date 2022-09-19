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

const ll mod = 1000000007;
const int N = 1000;

struct Input {
	int n, k;
};

struct Data: Input {
	bool read () {
		return cin >> n >> k;
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
	ll r[N + 1][N + 1];
	
	void solve () {
		ans = r[n][k];
	}

	static const int M = 50;
	ll f[N + 1];
	ll c[N + 1][N + 1];
	ll t[N + 1][M];
	ll d[2][N + 1][N + 1];
	
	Solution (const Data &data = Data()): Data(data) {
		f[0] = 1;
		forn (i, N) {
			f[i + 1] = f[i] * (i + 1) % mod;
		}
		forn (i, N + 1) {
			forn (j, N + 1) {
				if (!i || !j) {
					c[i][j] = 1;
					continue;
				}
				c[i][j] = (c[i - 1][j] + c[i][j - 1]) % mod;
			}
		}
		memset(d, 0, sizeof d);
		debug("!");
		forn (i, M) {
			memset(d[i & 1], 0, sizeof d[i & 1]);
			forn (j, N + 1) {
				forn (k, N + 1) {
					if (i == 0) {
						d[i & 1][j][k] = (j == 0);
					} else {
						if (k == 0) {
							d[i & 1][j][k] = 0;
							continue;
						}
						d[i & 1][j][k] = d[i & 1][j][k - 1];
						if (j >= k) {
							(d[i & 1][j][k] += d[(i - 1) & 1][j - k][k - 1]) %= mod;
						}
					}
				}
				t[j][i] = d[i & 1][j][N];
			}
		}
		forn (i, 6) {
			debug(vector<ll>(t[i], t[i] + 5));
		}
		debug("!");
		memset(r, 0, sizeof r);
		forn (i, N + 1) {
			forn (j, M) {
				r[i][j] = 0;
				forn (s, i - j + 1) {
					(r[i][j] += c[j][i - j - s] * t[s + j][j] % mod * f[j]) %= mod;
				}

			}
		}
	}
	
	void clear () {
	}
};

Solution sol;

int main () {
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	forn (i, n) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	return 0;
}