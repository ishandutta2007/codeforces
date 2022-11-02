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

long long mod = 1000000007;

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

long long submod(const long long &a, const long long &b) {
    long long res = a - b;
    while (res < mod) {
        res += mod;
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

long long solve(long long a, long long b, long long s) {
    if (s < 0) {
        return 0;
    }
    if (s == 0) {
        return 1;
    }
    if (a < b) {
        swap(a, b);
    }
    if (s >= a + b) {
        return (a + 1) * (b + 1);
    }

    if (s <= b) {
        return (s + 1) * (s + 2) / 2;
    }
    if (s <= a) {
        return (b + 1) * (s - b) + (b + 1) * (b + 2) / 2;
    } else {
        long long delta = a + b - s;
        return (a + 1) * (b + 1) - (delta) * (delta + 1) / 2;
    }
}

long long solve2(long long a, long long b, long long s) {
    long long res = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i + j <= s) {
                ++res;
            }
        }
    }
    return res;
}



long long solve(long long a, long long b, long long c, long long s) {
    if (a + b + c < s) {
        return 0;
    }
    return solve(a, b, s) - solve(a, b, s - c - 1);
}

long long solve2(long long a, long long b, long long c, long long s) {
    long long res = 0;
    for (int x = 0; x <= a; ++x) {
        for (int y = 0; y <= b; ++y) {
            for (int z = 0; z <= c; ++z) {
                if (x + y + z == s) {
                    ++res;
                }
            }
        }
    }
    return res;
}

void stress() {
    for (int a = 0; a <= 15; ++a) {
        for (int b = 0; b <= 15; ++b) {
            for (int c = 0; c <= 15; ++c) {
                assert(solve(a, b, c) == solve2(a, b, c));
                for (int s = 0; s <= 15; ++s) {
                    cout << a << " " << b << " " << c << " " << s << "\n";
                    cout << solve(a, b, c, s) << " " << solve2(a, b, c, s) << "\n";
                    assert(solve(a, b, c, s) == solve2(a, b, c, s));
                }
            }
        }
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

//    stress();
//    return 0;

//    int n = nxt();
//    int a[n];
//    for (int i = 0; i < n; ++i) {
//        a[i] = nxt();
//    }

    int a = nxt();
    int b = nxt();
    int c = nxt();


    int l = nxt();

    long long ans = 0;

    for (int sum = 0; sum <= l; ++sum) {
        int mx = (b + c + sum - a - 1);
        int my = (a + c + sum - b - 1);
        int mz = (a + b + sum - c - 1);

        if (mx < 0 || my < 0 || mz < 0) {
            continue;
        }

        mx /= 2, my /= 2, mz /= 2;

        ans += solve(mx, my, mz, sum);

    }

    cout << ans << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}