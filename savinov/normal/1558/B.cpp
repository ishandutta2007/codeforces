#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

#include <memory>
#include <random>
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


mt19937 gen;

void pre() {
}

struct divider_64 {
    uint64_t value;
    uint64_t magic;
    uint8_t more;

    static inline uint64_t div_64_to_64(uint64_t u1, uint64_t u0, uint64_t v, uint64_t *r) {
        const uint64_t b = (1ULL << 32); // Number base (16 bits)
        uint64_t un1, un0; // Norm. dividend LSD's
        uint64_t vn1, vn0; // Norm. divisor digits
        uint64_t q1, q0; // Quotient digits
        uint64_t un64, un21, un10; // Dividend digit pairs
        uint64_t rhat; // A remainder
        int s; // Shift amount for norm

        // If overflow, set rem. to an impossible value,
        // and return the largest possible quotient
        if (__builtin_expect(u1 >= v, 0)) {
            if (r != NULL)
                *r = (uint64_t) -1;
            return (uint64_t) -1;
        }

        // count leading zeros
        s = __builtin_clzll(v);
        if (__builtin_expect(s > 0, 1)) {
            // Normalize divisor
            v = v << s;
            un64 = (u1 << s) | ((u0 >> (64 - s)) & (-s >> 31));
            un10 = u0 << s; // Shift dividend left
        } else {
            // Avoid undefined behavior
            un64 = u1 | u0;
            un10 = u0;
        }

        // Break divisor up into two 32-bit digits
        vn1 = v >> 32;
        vn0 = v & 0xFFFFFFFF;

        // Break right half of dividend into two digits
        un1 = un10 >> 32;
        un0 = un10 & 0xFFFFFFFF;

        // Compute the first quotient digit, q1
        q1 = un64 / vn1;
        rhat = un64 - q1 * vn1;

        while (q1 >= b || q1 * vn0 > b * rhat + un1) {
            q1 = q1 - 1;
            rhat = rhat + vn1;
            if (rhat >= b)
                break;
        }

        // Multiply and subtract
        un21 = un64 * b + un1 - q1 * v;

        // Compute the second quotient digit
        q0 = un21 / vn1;
        rhat = un21 - q0 * vn1;

        while (q0 >= b || q0 * vn0 > b * rhat + un0) {
            q0 = q0 - 1;
            rhat = rhat + vn1;
            if (rhat >= b)
                break;
        }

        // If remainder is wanted, return it
        if (r != NULL)
            *r = (un21 * b + un0 - q0 * v) >> s;

        return q1 * b + q0;
    }


    static inline uint64_t mullhi_u64(uint64_t x, uint64_t y) {
#ifdef __SIZEOF_INT128__
        __uint128_t xl = x;
        __uint128_t rl = xl * y;

        return (rl >> 64);
#else
        uint64_t u0, u1, v0, v1, k, t;
    uint64_t w1, w2;
    uint64_t whi;

    u1 = x >> 32; u0 = x & 0xFFFFFFFF;
    v1 = y >> 32; v0 = y & 0xFFFFFFFF;

    t = u0*v0;
    k = t >> 32;

    t = u1*v0 + k;
    w1 = t & 0xFFFFFFFF;
    w2 = t >> 32;

    t = u0*v1 + w1;
    k = t >> 32;

    whi = u1*v1 + w2 + k;

    return whi;
#endif
    }

    divider_64(uint64_t d) : value(d) {
        assert(d != 0);

        uint32_t floor_log_2_d = 63 - __builtin_clzll(d);

        // Power of 2
        if ((d & (d - 1)) == 0) {
            magic = 0;
            more = (uint8_t) (floor_log_2_d);
        } else {
            uint64_t rem;
            auto proposed_m = div_64_to_64(1ULL << floor_log_2_d, 0, d, &rem);
            const auto e = d - rem;
            proposed_m += proposed_m;
            const uint64_t twice_rem = rem + rem;
            if (twice_rem >= d || twice_rem < rem) proposed_m += 1;
            more = (uint8_t) (floor_log_2_d | 0x40);
            magic = 1 + proposed_m;
        }
        more &= 0x3f;
    }

    friend inline uint64_t operator/(uint64_t numer, const divider_64 &d) {
        if (!d.magic) {
            return numer >> d.more;
        }
        auto q = mullhi_u64(d.magic, numer);
        auto t = ((numer - q) >> 1u) + q;
        return t >> d.more;
    }

    friend inline uint64_t operator%(uint64_t numer, const divider_64 &d) {
        return numer - (numer / d) * d.value;
    }
};

void solve(int test_number) {
    int n = nxt();
    divider_64 m = nxt();

    vector<uint64_t> dp(n + 1);
    vector<uint64_t> pref_sum(n + 1);
    dp[1] = 1;
    uint64_t s = 0;
    for (int i = 1; i <= n; ++i) {
        s += pref_sum[i];
        s = s % m;
        if (i > 1) dp[i] = s;

        if (i + 1 <= n) {
            pref_sum[i + 1] += dp[i];
        }

        uint64_t delta = dp[i] - dp[i - 1] + m.value;

        for (int j = 2 * i; j <= n; j += i) {
            pref_sum[j] += delta;
        }
    }

    cout << dp[n] % m << "\n";
}


int main(int argc, char **argv) {
//    freopen("input", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ::TTT = 1;
//    nxt();
    pre();

    for (int test = 1; test <= ::TTT; ++test) {
//        cout << "Case #" << test << ": ";
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
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    }

} init_global_;

#endif // LOCAL

//#define AUTO_MALLOC
#ifdef AUTO_MALLOC
namespace MALLOC {
    const size_t MAX_HEAP = 256 * 1000 * 1000;
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

template<>
inline void input(string &a) {
    a.clear();
    static int ed;
    while (isspace(ed = getchar())) {}
    while (!isspace(ed) && ed != EOF) {
        a += (char) ed;
        ed = getchar();
    }
}

template<typename T>
inline T nxt() {
    T res;
    input(res);
    return res;
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