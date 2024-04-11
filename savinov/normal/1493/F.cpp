//#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")  //Enable AVX

#include <memory>
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

#ifndef LOCAL
#define cerr while(0) cerr
#endif

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
//typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
typedef unsigned int uint;

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

template<typename T, typename N>
T pw(T a, N n, T m);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);

template<class T, class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, make_vec<T>(args...));
}

template<class... Args>
inline auto make_vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector(n, args...);
    else
        return vector(n, make_vec(args...));
}


int TTT;

void pre() {}

bool ask(int h, int w, int i1, int j1, int i2, int j2) {
    cout << "? " << h << " " << w << " " << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
    int res;
    cin >> res;
    return res;
}

vector <pii> factor(int n) {
    vector <pii> res;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            pii add = {i, 0};
            while (n % i == 0) {
                add.y += 1;
                n /= i;
            }
            res.push_back(add);
        }
    }
    return res;
}

vector <int> solveX(int n, const vector <pii>& fn, int m, int t) {
    vector <int> pn;

    auto ask2 = [&](int h, int w, int i1, int j1, int i2, int j2) {
        if (!t) {
            return ask(h, w, i1, j1, i2, j2);
        } else {
            return ask(w, h, j1, i1, j2, i2);
        }
    };

    for (auto pp : fn) {
        int okD;
        int p = pp.x;
        if (p == 2) {
            okD = ask2(n / 2, m, 0, 0, n / 2, 0);
        } else {
            int H = (p - 1) / 2;
            okD = ask2(H * (n / p), m, 0, 0, H * (n / p), 0) && ask2(H * (n / p), m, 0, 0, (H + 1) * (n / p), 0);
        }

        if (!okD) {
            continue;
        }

        int l = 1, r = pp.y;
        while (l < r) {
            cerr << l << " " << r << endl;
            int mid = (l + r + 1) / 2;
            int f = 1;
            forn(i, mid) f *= p;

            if (ask2(n / p - n / f, m, 0, 0, n - (n / p - n / f), 0)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        pn.push_back(l);
    }

    return pn;
}

void solve(int _) {
    int n, m;
    cin >> n >> m;

    auto fn = factor(n);
    auto fm = factor(m);

    vector <int> pn = solveX(n, fn, m, 0);
    vector <int> pm = solveX(m, fm, n, 1);

    long long ans = 1;
    for (int x : pn) {
        ans = ans * (x + 1);
    }

    for (int x : pm) {
        ans = ans * (x + 1);
    }

    cout << "! " << ans << endl;
}


int main(int argc, char **argv) {
    ::TTT = 1;
    pre();

    for (int test = 1; test <= ::TTT; ++test) {
        solve(test);
    }

    return 0;
}

#ifdef LOCAL

struct timer {
    clock_t init;

    timer() {
        init = clock();
    }

    clock_t time() const {
        return clock() - init;
    }

    ~timer() {
        cerr << "Time elapsed: " << (double) (time()) / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    }
};

#include <sys/resource.h>

struct init_str {
    timer t{};

    init_str() {
//        freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

        rlimit R{};
        getrlimit(RLIMIT_STACK, &R);
        R.rlim_cur = R.rlim_max;
        setrlimit(RLIMIT_STACK, &R);
    }

} init_global_;

#endif // LOCAL

//#define AUTO_MALLOC 0
#ifdef AUTO_MALLOC
namespace MALLOC {
    const size_t MAX_HEAP = 768 * 1000 * 1000;
    char buf[MAX_HEAP];
    size_t ptr;
}

void *operator new(size_t size) {
    void *result = MALLOC::buf + MALLOC::ptr;
    MALLOC::ptr += size;
    return result;
}

void operator delete(void *ptr) noexcept { /* DO NOTHING */ }

#endif //AUTO_MALLOC

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

template<typename T>
inline T nxt() {
    T res;
    input(res);
    return res;
}


//bool checkp(long long v) {
//    if (v < 2) return false;
//    for (long long i = 2; i * i <= v; ++i) {
//        if (v % i == 0) {
//            return false;
//        }
//    }
//    return true;
//}

template<typename T, typename N>
T pw(T a, N n, T m) {
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