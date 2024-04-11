#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
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
const long double PI = 3.1415926535897932384626433832795L;

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

long long mod = 1000000000000000003ll;

long long mulmod(const long long &a, const long long &b) {
    long long ratio = (long double)a * b / mod;

    long long res = a * b - ratio * mod;

    while (res < 0) {
        res += mod;
    }
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

long long addmod(const long long &a, const long long &b) {
    long long res = a + b;
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

void fib(long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y = addmod(x, y);
    } else {
        long long a, b;
        fib(n / 2, a, b);
        long long u = mulmod(a, a);
        long long v = mulmod(a, b);
        long long w = mulmod(b, b);
        x = addmod(u, w);
        y = addmod(2 * v, w);
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = mulmod(res, a);
        }
        a = mulmod(a, a);
        n >>= 1;
    }
    return res;
}

long long pw(long long a, long long n, long long m) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}
char s[1000000];

long long p[1000000];

long long get(int l, int r) {
    int d = r - l;
    if (d % 2 == 0) {
        int m = (l + r) / 2;
        long long a = get(l, m);
        long long b = get(m, r);
        if (a < b) {
            swap(a, b);
        }
        return addmod(mulmod(a, p[(r - l) / 2]), b);
    } else {
        long long res = 0;
        for (int i = l; i < r; ++i) {
            res = addmod(mulmod(res, p[1]), s[i]);
        }
        return res;
    }
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "carpet"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    scanf("%s", s);

    int n = strlen(s);

    p[0] = 1;

    for (int i = 0; i < n; ++i) {
        p[i + 1] = mulmod(p[i], 137);
    }

    long long v = get(0, n);

    scanf("%s", s);

    long long w = get(0, n);

    puts(v == w ? "YES" : "NO");


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}