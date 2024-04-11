#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template <typename T>
T pw(T a, T n, T p);

template <typename T>
T inv(T a, T p);

void pre() {

}

struct Rect {
    int xl;
    int xr;
    int yl;
    int yr;
};

int n;
int m;

int LOG_TABLE[1024];

void INIT() {
    for (int i = 2; i < 1024; i++)
        LOG_TABLE[i] = LOG_TABLE[i >> 1] + 1;
}



struct Sparse {
    int x[1024];
    int M[10][1024];

    void build() {
        for (int i = 0; i < m; ++i) {
            M[0][i] = x[i];
        }
        for (int i = 1; (1 << i) < m; ++i) {
            for (int j = 0; j + (1 << i) <= m; ++j) {
                M[i][j] = max(M[i - 1][j], M[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    void merge(const Sparse &l, const Sparse &r) {
        for (int i = 0; i < m; ++i) {
            x[i] = max(l.x[i], r.x[i]);
        }
        build();
    }

    int get(int k, int i, int j) {
        return max(M[k][i], M[k][j]);
    }
};

Sparse z[2 * 1024];

void solve(int test) {
    INIT();
    n = nxt();
    m = nxt();

    int s[n + 1][m + 1];

    clr(s);

    forn(i, n) forn(j, m) s[i + 1][j + 1] = nxt();

    forn(i, n) forn(j, m) s[i + 1][j + 1] += s[i + 1][j] + s[i][j + 1] - s[i][j];

    int v[n][m];

    forn(i, n) {
        forn(j, m) {
            int l = 0, r = min(n - i, m - j);
            while (l < r) {
//                cerr << l << " " << r << endl;
                int mid = (l + r + 1) / 2;
                int sum = s[i + mid][j + mid] - s[i][j + mid] - s[i + mid][j] + s[i][j];
                if (sum == mid * mid) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
//            cerr << l << " ";
            v[i][j] = l;
        }
//        cerr << "\n";

//        cerr << "OK\n";
        memcpy(z[n + i].x, v[i], m * sizeof(int));
        z[n + i].build();
    }



    for (int i = n - 1; i > 0; --i) {
        z[i].merge(z[i + i], z[i + i + 1]);
    }



    auto get = [&](int lx, int rx, int ly, int ry) {
        int k = LOG_TABLE[ry - ly];
        int i = ly;
        int j = ry - (1 << k) + 1;

        int res = 0;

        for (lx += n, rx += n; lx <= rx; lx = (lx + 1) >> 1, rx = (rx - 1) >> 1) {
            if (lx & 1) {
                res = max(res, z[lx].get(k, i, j));
            }
            if (!(rx & 1)) {
                res = max(res, z[rx].get(k, i, j));
            }
        }

        return res;
    };

    int q = nxt();
    for (int i = 0; i < q; ++i) {
        int lx = nxt() - 1;
        int ly = nxt() - 1;
        int rx = nxt() - 1;
        int ry = nxt() - 1;

        int W = min(rx - lx + 1, ry - ly + 1);

        int l = 0, r = W;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int LX = lx, LY = ly;
            int RX = rx - mid + 1;
            int RY = ry - mid + 1;
            if (get(LX, RX, LY, RY) >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
}



int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = long long>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
}

mt19937 generator;

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}
template <typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template <typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}