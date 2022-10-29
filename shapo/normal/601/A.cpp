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

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

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

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
    int n, m;
    ve< pii > e;
	
	bool read () {
        if (scanf("%d%d", &n, &m) != 2) return 0;
        e.resize(m);
        forn (i, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            e[i] = mp(u, v);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    int ans;	
	void write () {
		printf("%d\n", ans);
	}
};

struct Solution: Data {

    int sm[500][500];

    int dist[1000][500];
    pii q[4 * 500 * 500];

	void solve () {
	    memset(sm, 0, sizeof(sm));
        forn (i, n) {
            sm[i][i] = 2;
        }
        forn (j, m) {
            int u, v;
            tie(u, v) = e[j];
            sm[u][v] = sm[v][u] = 1;
        }
        int qh = 2 * 500 * 500, qt = qh;
        forn (i, 2 * n) {
            forn (j, n) {
                dist[i][j] = -1;
            }
        }
        dist[0][0] = 0;
        q[qt++] = mp(0, 0);
        while (qh < qt) {
            int u, v;
            tie(u, v) = q[qh++];
            if (u >= n) {
                forn (j, n) {
                    if (sm[v][j] == 1 && (j + n != u || j == n - 1) && dist[u - n][j] == -1) {
                        dist[u - n][j] = dist[u][v] + 1;
                        q[qt++] = mp(u - n, j);
                    }
                }
            } else {
                if (u == n - 1) {
                    forn (j, n) {
                        if (sm[v][j] == 1 && dist[u][j] == -1) {
                            dist[u][j] = dist[u][v] + 1;
                            q[qt++] = mp(u, j);
                        }
                    }
                } else if (v == n - 1) {
                    forn (j, n) {
                        if (sm[u][j] == 0 && dist[j][v] == -1) {
                            dist[j][v] = dist[u][v] + 1;
                            q[qt++] = mp(j, v);
                        }
                    }
                } else {
                    forn (j, n) {
                        if (sm[u][j] == 0 && dist[j + n][v] == -1) {
                            dist[j + n][v] = dist[u][v];
                            q[--qh] = mp(j + n, v);
                        }
                    }
                }
            }
        }
        ans = dist[n - 1][n - 1];
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