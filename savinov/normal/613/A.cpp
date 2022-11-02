#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
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



void pre() { }

void read() { }

void test() { }


double dist(double ax, double ay, double bx, double by) {
    double l = 0, r = 1;
    double it = 200;
    while (it--) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;

        double x1 = ax * m1 + bx * (1 - m1);
        double y1 = ay * m1 + by * (1 - m1);


        double x2 = ax * m2 + bx * (1 - m2);
        double y2 = ay * m2 + by * (1 - m2);

        double d1 = sqr(x1) + sqr(y1);
        double d2 = sqr(x2) + sqr(y2);

        if (d1 < d2) {
            r = m2;
        } else {
            l = m1;
        }
    }

    double m = (l + r) / 2;

    double x1 = ax * m + bx * (1 - m);
    double y1 = ay * m + by * (1 - m);

    return sqr(x1) + sqr(y1);
}

void solve() {
    int n = nxt();
    long long x = nxt();
    long long y = nxt();

    double ax[n], ay[n];

    double minr = LLONG_MAX, maxr = LLONG_MIN;

    for (int i = 0; i < n; ++i) {
        ax[i] = nxt(), ay[i] = nxt();
        minr = min(minr, sqr(ax[i] - x) + sqr(ay[i] - y));
        maxr = max(maxr, sqr(ax[i] - x) + sqr(ay[i] - y));
    }

    for (int i = 0; i < n; ++i) {
        double x1 = ax[i] - x;
        double y1 = ay[i] - y;

        double x2 = ax[(i + 1) % n] - x;
        double y2 = ay[(i + 1) % n] - y;

        minr = min(minr, dist(x1, y1, x2, y2));
    }



    cout << setprecision(20) << fixed;
    cout << PI * (maxr - minr) << endl;
}


void solve2() { }


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
    test();
#endif
    while (t--) {
        read();
//        gen();
//        gen2();
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}