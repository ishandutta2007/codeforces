#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
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

template<typename T = int>
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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

double dist(double ax, double ay, double bx, double by) {
    return sqrt(sqr(ax - bx) + sqr(ay - by));
}

void solve(int test) {
    double ax = nxt();
    double ay = nxt();
    double bx = nxt();
    double by = nxt();
    double tx = nxt();
    double ty = nxt();

    int n = nxt();

    double x[n], y[n];

    forn (i, n) {
        x[i] = nxt();
        y[i] = nxt();
    }

    double sum = 0;

    forn(i, n) sum += 2 * dist(tx, ty, x[i], y[i]);

    double ans = DBL_MAX;

    forn(i, n) ans = min(ans, dist(ax, ay, x[i], y[i]) + sum - dist(tx, ty, x[i], y[i]));
    forn(i, n) ans = min(ans, dist(bx, by, x[i], y[i]) + sum - dist(tx, ty, x[i], y[i]));

    cout << setprecision(10) << fixed;
    if (n == 1) {
        cout << ans << "\n";
        return;
    }

    double delta1[n];
    double delta2[n];

    forn(i, n) delta1[i] = dist(ax, ay, x[i], y[i]) - dist(tx, ty, x[i], y[i]);
    forn(i, n) delta2[i] = dist(bx, by, x[i], y[i]) - dist(tx, ty, x[i], y[i]);

    int o[n];
    iota(o, o + n, 0);

    sort(o, o + n, [&](int u, int v) {
        return delta2[u] < delta2[v];
    });

    forn (i, n) {
        double r = sum + delta1[i];
        if (i == o[0]) {
            r += delta2[o[1]];
        } else {
            r += delta2[o[0]];
        }
        ans = min(ans, r);
    }

    cout << ans << "\n";
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    pre();
//    exit(0);
    int t = 1;

#ifdef LOCAL
#else
#endif
    int c = 0;

    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}