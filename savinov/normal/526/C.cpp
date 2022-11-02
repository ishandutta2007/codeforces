#include "bits/stdc++.h"

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

random_device device;
mt19937 generator(device());

unsigned int nextRandom() {
    return generator();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}




long long pw(long long a, long long n, long long mod) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long gcd (long long a, long long b, long long  & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (long long a, long long b, long long c, long long & x0, long long & y0, long long & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    return true;
}


long long c, h1, h2, w1, w2;

long long xbest;

long long solve2() {
    long long ans = 0;

    for (long long x = 0; x * w1 <= c; ++x) {
        long long y = (c - x * w1) / w2;
        if (x * h1 + y * h2 > ans) {
            ans = x * h1 + y * h2;
            xbest = x;
        }
    }
    return ans;
}

long long solve1() {
    long long ans = 0;

    if (w2 >= 100000) {
        for (long long y = 0; y * w2 <= c; ++y) {
            long long x = (c - y * w2) / w1;
            if (x * h1 + y * h2 > ans) {
                ans = x * h1 + y * h2;
                xbest = x;
            }
        }
        return ans;
    } else {
        for (long long m = 0; m < w2 && m * w1 <= c; ++m) {
            long long cc = c - w1 * m;
            cc /= w2;
            long long aa = w2 * h1;
            long long bb = h2;
            long long ww = h1 * m;

            long long x = cc / w1;
            long long y = (cc - x * w1) / bb;

            ans = max(ans, aa * x + bb * y + ww);

            y = cc;
            x = (cc - y) / aa;

            ans = max(ans, aa * x + bb * y + ww);
        }
    }

    swap(h1, h2);
    swap(w1, w2);

    if (w2 >= 100000) {
        for (long long y = 0; y * w2 <= c; ++y) {
            long long x = (c - y * w2) / w1;
            if (x * h1 + y * h2 > ans) {
                ans = x * h1 + y * h2;
                xbest = x;
            }
        }
        return ans;
    } else {
        for (long long m = 0; m < w2 && m * w1 <= c; ++m) {
            long long cc = c - w1 * m;
            cc /= w2;
            long long aa = w2 * h1;
            long long bb = h2;
            long long ww = h1 * m;

            long long x = cc / w1;
            long long y = (cc - x * w1) / bb;

            ans = max(ans, aa * x + bb * y + ww);

            y = cc;
            x = (cc - y) / aa;

            ans = max(ans, aa * x + bb * y + ww);
        }
    }

//    for (long long x = 0; x <= 2 && x * w1 <= c; ++x) {
//        long long y = (c - x * w1) / w2;
//        if (x * h1 + y * h2 > ans) {
//            ans = x * h1 + y * h2;
//            xbest = x;
//        }
//    }
//
//    for (long long x = c / w1, i = 0; i <= 2 && x >= 0; --x, ++i) {
//        long long y = (c - x * w1) / w2;
//        if (x * h1 + y * h2 > ans) {
//            ans = x * h1 + y * h2;
//            xbest = x;
//        }
//    }
//
//    swap(w1, w2);
//    swap(h1, h2);
//
//    for (long long x = 0; x <= 2 && x * w1 <= c; ++x) {
//        long long y = (c - x * w1) / w2;
//        if (x * h1 + y * h2 > ans) {
//            ans = x * h1 + y * h2;
//            xbest = y;
//        }
//    }
//
//    for (long long x = c / w1, i = 0; i <= 2 && x >= 0; --x, ++i) {
//        long long y = (c - x * w1) / w2;
//        if (x * h1 + y * h2 > ans) {
//            ans = x * h1 + y * h2;
//            xbest = y;
//        }
//    }
//
//    swap(w1, w2);
//    swap(h1, h2);
//
//    long long x, y, g;
//
//    if (find_any_solution(w1, w2, c, x, y, g)) {
//        long long bb = w2 / g;
//        long long aa = w1 / g;
//        if (x < 0) {
//            long long k1 = (-x + bb - 1) / bb;
//            x += k1 * bb;
//            y -= k1 * aa;
//            if (y >= 0) {
//                if (h1 * x + h2 * y > ans) {
//                    ans = h1 * x + h2 * y;
//                    xbest = x;
//                }
//            }
//        } else {
//            long long k1 = x / bb;
//            x -= k1 * bb;
//            y += k1 * aa;
//            if (y >= 0) {
//                if (h1 * x + h2 * y > ans) {
//                    ans = h1 * x + h2 * y;
//                    xbest = x;
//                }
//            }
//        }
//
//        swap(x, y);
//        swap(aa, bb);
//        swap(h1, h2);
//        swap(w1, w2);
//        if (x < 0) {
//            long long k1 = (-x + bb - 1) / bb;
//            x += k1 * bb;
//            y -= k1 * aa;
//            if (y >= 0) {
//                if (h1 * x + h2 * y > ans) {
//                    ans = h1 * x + h2 * y;
//                    xbest = y;
//                }
//            }
//        } else {
//            long long k1 = x / bb;
//            x -= k1 * bb;
//            y += k1 * aa;
//            if (y >= 0) {
//                if (h1 * x + h2 * y > ans) {
//                    ans = h1 * x + h2 * y;
//                    xbest = y;
//                }
//            }
//        }
//    }

    return ans;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    c = nxt();
    h1 = nxt();
    h2 = nxt();

    w1 = nxt();
    w2 = nxt();

    cout << solve1() << "\n";


//    int it = 1000000;
//
//    int M = 1000;
//
//    while (it--) {
//        c = rand() % M + 1;
//        h1 = rand() % M + 1;
//        h2 = rand() % M + 1;
//        w1 = rand() % M + 1;
//        w2 = rand() % M + 1;
//        long long r1 = solve1();
//        long long x1 = xbest;
//        long long r2 = solve2();
//        long long x2 = xbest;
//        if(r1 != r2) {
//            cout << h1 << " " << h2 << "\n";
//            cout << w1 << " " << w2 << "\n";
//            cout << c << "\n";
//            cout << r1 << " " << r2 << "\n";
//            cout << x1 << " " << x2 << "\n";
//            return 0;
//        }
//    }

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}