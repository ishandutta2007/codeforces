#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

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


vector <int> primes;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x  % i == 0) return false;
    }
    return true;
}




void solve(int _) {
    int n = nxt();
    ll a = nxt();
    ll r = nxt();
    ll m = nxt();
    m = min(m, a + r);

    auto h = make_vec(n, 0ll);
    forn(i, n) h[i] = nxt();

    sort(all(h));

    ll ans = LLONG_MAX;

    auto relax = [&](ll s1, ll p1, ll s2, ll p2, ll mx) {
        auto get = [&](int x) {
            return (s1 + x * p1) * a + (s2 - x * p2) * r - min(s1 + x * p1, s2 - x * p2) * (a + r - m);
        };
        ans = min(ans, get(0));
        ans = min(ans, get(mx));

        // s1 + p1 * x == s2 - p2 * x

        ll x = (s2 - s1) / (p1 + p2);
        if (x >= 0 && x <= mx) ans = min(ans, get(x));
        if (x-1 >= 0 && x-1 <= mx) ans = min(ans, get(x-1));
        if (x+1 >= 0 && x+1 <= mx) ans = min(ans, get(x+1));
    };

    ll s1 = 0;
    ll p1 = 0;
    ll s2 = accumulate(all(h), 0ll);
    ll p2 = n;

    ll prevh = 0;
    relax(s1, p1, s2, p2, h[0]);

    forn(i, n) {
        s1 += p1 * (h[i] - prevh);
        p1 += 1;

        s2 -= p2 * (h[i] - prevh);
        p2 -= 1;

        ll UP = (i + 1 < n ? h[i + 1] - h[i] : 1e9);

//        cerr << s1 << " " << p1 << " " << s2 << " " << p2 << endl;

        relax(s1, p1, s2, p2, UP);

        prevh = h[i];
    }

    cout << ans << endl;
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
    ::TTT = 1;

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