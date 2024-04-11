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

int n;

int Q, W;

int getX(int l, int r) {
    cerr << "X " << endl;
    cout << "? " << l + 1 << " " << Q + 1 << " " << r << " " << W << endl;
    int res;
    cin >> res;
    return res;
}

int getY(int l, int r) {
    cerr << "Y " << endl;
    cout << "? " << Q + 1 << " " << l + 1 << " " << W << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

struct Rect {
    int x1, y1;
    int x2, y2;
};

template <class T>
pii find(int L, int R, T f) {
    int l = 1, r = R - L;
    while (l < r) {
        int m = (l + r) / 2;
        if (f(L, L + m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int hi = L + l;
    l = 1, r = R - L;
    while (l < r) {
        int m = (l + r) / 2;
        if (f(R - m, R)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int lo = R - l;
    assert(lo < hi);
    return mp(lo, hi);
}

vector <Rect> ans;

void find (int lx, int rx, int ly, int ry) {
    Q = ly, W = ry;
    pii px = find(lx, rx, getX);
    Q = lx, W = rx;
    pii py = find(ly, ry, getY);
    ans.push_back(Rect{px.x + 1, py.x + 1, px.y, py.y});
}

template <class T>
pii solve(T f) {
    int l = 1, r = n;

    while (l < r) {
        int m = (l + r) / 2;
        if (f(0, m) > 0) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    int R1 = l;


    l = 1, r = n;

    while (l < r) {
        int m = (l + r) / 2;
        if (f(n - m, n) > 0) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    int L1 = n - l;

    return {L1, R1};
}

void solve(int test) {
    cin >> n;
    Q = 0, W = n;
    pii X = solve(getX);
    pii Y = solve(getY);

    if (X.x >= X.y) {
        find(0, X.x, 0, n);
        find(X.x, n, 0, n);
    } else if (Y.x >= Y.y) {
        find(0, n, 0, Y.x);
        find(0, n, Y.x, n);
    } else {
        assert(false);
    }

    cout << "! " << ans[0].x1 << " " << ans[0].y1 << " " << ans[0].x2 << " " << ans[0].y2 << " ";
    cout << ans[1].x1 << " " << ans[1].y1 << " " << ans[1].x2 << " " << ans[1].y2 << endl;
}



int main(int argc, char **argv) {

#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
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