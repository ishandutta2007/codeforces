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

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

void pre() {

}

ll ext_gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) { x = 0; y = 1; return b; }
    ll x1, y1, d = ext_gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1; y = x1;
    return d;
}


long long chinese(ll a1, ll m1, ll a2, ll m2) {
    ll x, y;
    ll g = gcd(m1, m2);

    if (a1 % g != a2 % g) {
        return LLONG_MAX;
    }

    ll M1 = m1 / g;
    ll M2 = m2 / g;

//    ll res =

//    if (M1 == 1 && M2 == 1) {
//        ll res = g
//    }

    ext_gcd(M1, M2, x, y);

    x = (x % M2 + M2) % M2;
//    cerr << m1 << " " << m2 << " " << g << endl;
//    cerr << M1 << " " << M2 << " " << x << " " << y << endl;
//    assert(M1 * x % M2 == 1);

    ll k = x * ((a2 - a1) / g) % M2;
    if (k < 0) k += M2;
//    assert((k * M1 + a1 % M1) % M2 == a2 % M2);

    ll res = k * M1 * g + a1;

//    cerr << res << " " << res % m1 << " " << res % m2 << " " << a1 << " " << a2 << endl;

    assert(res < M1 * M2 * g);
    assert(res % m1 == a1);
    assert(res % m2 == a2);

    return res;
}

void T() {
    while (true) {
        int n = rand() % 10 + 2;
        int m = rand() % 10 + 2;

        for1(i, n - 1) for1(j, m-1) {
                chinese(i, 2*n, j, 2*m);
                chinese(2*n-i, 2*n, j, 2*m);
                chinese(i, 2*n, 2*m-j, 2*m);
                chinese(2*n-i, 2*n, 2*m-j, 2*m);
            }
    }
}

void solve(int test) {
//    T();
    int n = nxt();
    int m = nxt();
    int k = nxt();
    forn(i, k) {
        int x = nxt();
        int y = nxt();

        ll res = LLONG_MAX;

        res = min(res, chinese(x, 2 * n, y, 2 * m));
        res = min(res, chinese(2*n - x, 2 * n, y, 2 * m));
        res = min(res, chinese(x, 2 * n, 2*m-y, 2 * m));
        res = min(res, chinese(2*n-x, 2 * n, 2*m-y, 2 * m));

        if (res == LLONG_MAX) {
            res = -1;
        }

        cout << res << "\n";
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
    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
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

template<typename T>
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

template<typename T>
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