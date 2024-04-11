#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

#ifdef LOCAL

#include <stdint.h>
#include <inttypes.h>
#include <sys/resource.h>

struct ___ {
    ___() {
        rlimit R{};
        getrlimit(RLIMIT_STACK, &R);
        R.rlim_cur = R.rlim_max;
        setrlimit(RLIMIT_STACK, &R);
    }
} ___;

#endif

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

#ifdef AUTO_MALLOC
namespace MALLOC {
    const size_t MAX_HEAP = 1024 * 1000 * 1000;
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

template<typename T>
T pw(T a, T n, T m);

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

void pre() {

}

int TTT;

// mask, prefix -> min

int a[16];

int dp[16][1 << 15][16];
int p[16][1 << 15][16];
int ppos[16][1 << 15][16];

int ss[1 << 15];

void solve(int _) {
    int n = nxt();
    forn(i, n) a[i] = nxt();

    forn(pos, n + 1) forn(mask, 1 << n) forn(cnt, n + 1) dp[pos][mask][cnt] = 0x3f3f3f3f;

    dp[0][0][0] = -1;

    ss[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int bit = __builtin_ctz(mask);
        ss[mask] = a[bit] + ss[mask ^ (1 << bit)];
    }

    for (uint pos = 0; pos < n; ++pos) {
        for (uint mask = 0; mask < (1 << n); ++mask) {
            for (uint nm = (mask + 1) | mask; nm < (1 << n); nm = (nm + 1) | mask) {
                uint delta = nm ^ mask;
                int k = (delta >> pos) << pos;
                if (k == 0) continue;
                int bit = __builtin_ctz(k) + 1;

                for (int cnt = 0; cnt < n; ++cnt) {
                    if (ss[delta] > dp[pos][mask][cnt]) {
                        if (uin(dp[bit][nm][cnt+1], ss[delta])) {
                            p[bit][nm][cnt+1] = delta;
                            ppos[bit][nm][cnt+1] = pos;
                        }
                    }
                }
            }
        }
    }
    int best_cnt = 0;

    int best_pos;

    for (int pos = 0; pos <= n; ++pos) for (int cnt = 1; cnt <= n; ++cnt) {
            if (dp[pos][(1 << n) - 1][cnt] < 0x3f3f3f3f) {
                if (uax(best_cnt, cnt)) {
                    best_pos = pos;
                }
            }
        }

    int pos = best_pos;
    int mask = (1 << n) - 1;
    int cnt = best_cnt;

    vector <pair <int, int> > steps;

    while (mask) {
        int delta = p[pos][mask][cnt];

        int npos = ppos[pos][mask][cnt];

        int k = (delta >> npos) << npos;
        int bit = __builtin_ctz(k);

        steps.emplace_back(delta, bit);

        pos = npos;
        mask ^= delta;
        cnt -= 1;
    }

    assert(cnt == 0);
    assert(pos == 0);

    cout << n - best_cnt << "\n";

    vector <int> positions(n);
    iota(all(positions), 0);

    auto mv = [&](int a, int b) {
        a = lower_bound(all(positions), a) - positions.begin();
        b = lower_bound(all(positions), b) - positions.begin();

        cout << a + 1 << " " << b + 1 << "\n";
        positions.erase(positions.begin() + a);
    };

    for (auto step : steps) {
        int delta = step.x;

        for (int i = 0; i < n; ++i) {
            if (delta & (1 << i)) {
                if (i != step.y) mv(i, step.y);
            }
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
    ::TTT = nxt();

    pre();

    for (int test = 1; test <= ::TTT; ++test) {
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

template<typename T>
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