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


ll mod = 1000000007;


struct M {
    ll a[2][2];


    M operator*(const M &r) const {
        M res;
        clr(res.a);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res.a[i][j] = (a[i][0] * r.a[0][j] + a[i][1] * r.a[1][j]) % mod;

            }
        }
        return res;
    }

    M operator+(const M &r) const {
        M res;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res.a[i][j] = (a[i][j] + r.a[i][j]) % mod;
            }
        }
        return res;
    }
};

M E() {
    M res;
    clr(res.a);
    res.a[0][0] = res.a[1][1] = 1;
    return res;
}

M O() {
    M res;
    clr(res.a);
    return res;
}

M pw(M a, int n) {
    M res = E();
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}

M mul[1 << 20];
M sum[1 << 20];

void update(int v, int tl, int tr, int l, int r, const M &x) {
    if (l >= r) return;
    if (tl == l && tr == r) {
        mul[v] = mul[v] * x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(v + v, tl, tm, l, min(tm, r), x);
    update(v + v + 1, tm, tr, max(l, tm), r, x);
    sum[v] = mul[v + v + 1] * sum[v + v + 1] + mul[v + v] * sum[v + v];
}

M get(int v, int tl, int tr, int l, int r, M m) {
    if (l >= r) {
        return O();
    }
    if (tl == l && tr == r) {
        return m * sum[v];
    }

    int tm = (tl + tr) / 2;
    return get(v + v, tl, tm, l, min(r, tm), m * mul[v + v]) +

            get(v + v + 1, tm, tr, max(tm, l), r, m * mul[v + v + 1]);
}

M F;

void init(int v, int tl, int tr, int * x) {
    mul[v] = E();
    if (tr - tl == 1) {
        sum[v] = pw(F, x[tl]);
    } else {
        int tm = (tl + tr) / 2;
        init(v + v, tl, tm, x);
        init(v + v + 1, tm, tr, x);
        sum[v] = sum[v + v] + sum[v + v + 1];
    }
}

void solve(int test) {
    int n = nxt();
    int m = nxt();

    F.a[0][0] = 1;
    F.a[0][1] = 1;
    F.a[1][0] = 1;
    F.a[1][1] = 0;

    int a[n];
    forn(i, n) {
        a[i] = nxt();
    }

    init(1, 0, n, a);


    forn(i, m) {
        int t = nxt();
        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt();
            int x = nxt();
            update(1, 0, n, l, r, pw(F, x));
        } else {
            int l = nxt() - 1;
            int r = nxt();
            M z = get(1, 0, n, l, r, mul[1]);

//            for (int p = l; p < r; ++p) {
//                cout << p << endl;
//                forn(i, 2) forn(j, 2) cout << get(1, 0, n, p, p + 1, mul[1]).a[i][j] << " ";
//                cout << endl;
//            }

            ll ans = (z.a[0][1]) % mod;
            cout << ans << "\n";
        }
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