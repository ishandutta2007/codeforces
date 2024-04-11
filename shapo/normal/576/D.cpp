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
    vi a, b, d;
	bool read () {
        if (!(cin >> n >> m)) return 0;
        a.resize(m);
        d = b = a;
        forn(i, m) {
            cin >> a[i] >> b[i] >> d[i];
            --a[i], --b[i];
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
		if (ans == -1) {
            cout << "Impossible" << '\n';
        } else {
            cout << ans << '\n';
        }
	}
};

const int BASE = 64;
const int MAXN = 150;
const int MAXK = 30;

struct Matrix
{
    ull arr[MAXN][3];
    Matrix() {
        memset(arr, 0, sizeof(arr));
    }
    Matrix(const Matrix &lhs)
    {
        memcpy(arr, lhs.arr, sizeof(arr));
    }
    void clear() {
        memset(arr, 0, sizeof(arr));
    }
    int get(int i, int j) const
    {
        return (arr[i][j / BASE] >> (j % BASE)) & 1;
    }
    void set(int i, int j)
    {
        arr[i][j / BASE] |= (1ull << (j % BASE));
    }
};

void transpose(const Matrix &tmp, Matrix &v)
{
    v.clear();
    forn(i, MAXN) {
        forn(j, MAXN) {
            if (tmp.get(i, j)) {
                v.set(j, i);
            }
        }
    }
}

struct Vector
{
    int arr[MAXN];
    Vector() {
        memset(arr, 0, sizeof(arr));
    }
    Vector(const Vector &lhs)
    {
        memcpy(arr, lhs.arr, sizeof(arr));
    }
    void clear() {
        memset(arr, 0, sizeof(arr));
    }
};

struct Solution: Data {
    Matrix edges[MAXK][MAXN + 1];
    Matrix wedges[MAXK][MAXN + 1];

    void mult(const Matrix &a, const Matrix &b, Matrix &res)
    {
        Matrix tp;
        transpose(b, tp);
        res.clear();
        forn(i, n) {
            forn(j, n) {
                if ((a.arr[i][0] & tp.arr[j][0]) |
                    (a.arr[i][1] & tp.arr[j][1]) |
                    (a.arr[i][2] & tp.arr[j][2])) {
                    res.set(i, j);
                }
            }
        }
    }

    void mult(const Matrix &a, Vector &b, Vector &c)
    {
        c.clear();
        forn(i, n) {
            c.arr[i] = 0;
            for (int j = 0; j < n && !(c.arr[i]); ++j) {
                c.arr[i] = b.arr[j] && a.get(j, i);
            }
        }
    }

    void propagate(const Vector &from, int id, int diff, Vector &to, bool sparse)
    {
        to = from;
        forn(it, MAXK) {
            if (diff & (1 << it)) {
                Vector tmp = to;
                if (sparse) {
                    mult(edges[it][id], tmp, to);
                } else {
                    mult(wedges[it][id], tmp, to);
                }
            }
        }
    }

	void solve () {
	    ans = -1;	
        ve< tu< int, int, int > > ev;
        vi un = {0};
        forn(i, m) {
            un.pb(d[i]);
            ev.pb(mt(d[i], a[i], b[i]));
        }
        sort(all(ev));
        sort(all(un));
        un.pb(un.back() + n + 1);
        un.erase(unique(all(un)), un.end());
        debug(un);
        int cnt = sz(un);
        forn(i, cnt - 1) {
            forn(j, n) {
                wedges[0][i].set(j, j);
            }
            forn(j, m) {
                int aa, bb, dd;
                tie(dd, aa, bb) = ev[j];
                if (dd <= un[i]) {
                    edges[0][i].set(aa, bb);
                    wedges[0][i].set(aa, bb);
                }
            }
        }
        forn(it, 1, MAXK) {
            forn(i, cnt - 1) {
                if ((1 << it) <= (un[i + 1] - un[i])) {
                    mult(edges[it - 1][i], edges[it - 1][i], edges[it][i]);
                    mult(wedges[it - 1][i], wedges[it - 1][i], wedges[it][i]);
                }
            }
        }
        Vector sm;
        sm.arr[0] = 1;
        forn(i, 1, cnt) {
            int diff = un[i] - un[i - 1];
            Vector tp = sm;
            propagate(sm, i - 1, diff, tp, false);
            if (!tp.arr[n - 1]) {
                tp = sm;
                propagate(tp, i - 1, diff, sm, true);
                continue;
            }
            int l = 0, r = diff + 1;
            while (l < r - 1) {
                int mid = (l + r) / 2;
                Vector tp;
                propagate(sm, i - 1, mid, tp, false);
                if (!tp.arr[n - 1]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            ans = un[i - 1] + r;
            break;
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