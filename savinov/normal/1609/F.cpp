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

struct fenwick {
    vector <int> k;
    vector <int> b;

    fenwick(int n) {
        k.assign(n, 0);
        b.assign(n, 0);
    }

    void clear() {
        fill(all(k), 0);
        fill(all(b), 0);
    }

    void _add(int pos, int k_, int b_) {
        for (;pos < k.size(); pos |= pos + 1) {
            k[pos] += k_;
            b[pos] += b_;
        }
    }

    int _get(int pos) {
        int x = pos;
        int k_ = 0, b_ = 0;
        for (; pos >= 0; pos &= pos + 1, --pos) {
            k_ += k[pos];
            b_ += b[pos];
        }

        return k_ * x + b_;
    }


    void add(int l, int r, int delta) {
        _add(l, delta, delta - delta * l);
        _add(r, -delta, -(delta - delta * r));
    }

    int get(int l, int r) {
        return _get(r - 1) - _get(l - 1);
    }
};

void solve(int) {
    int n = nxt();
    vll a(n);
    forn(i, n) a[i] = nxt();

    vi pc(n);
    forn(i, n) pc[i] = __builtin_popcountll(a[i]);

    long long ans = 0;

    vector <int> st_min;
    vector <int> st_max;

    st_min.reserve(n);
    st_max.reserve(n);

    for (auto bit_range: vector <pii>{{0, 10}, {10, 20}, {20, 30}, {30, 40}, {40, 50}, {50, 60}}) {
        int from_bit, to_bit;
        tie(from_bit, to_bit) = bit_range;

        st_min.clear();
        st_max.clear();

        vector <fenwick> f_min(to_bit - from_bit, n);
        vector <fenwick> f_max(to_bit - from_bit, n);

        int cur = 0;

        auto insert_min = [&](int l, int r, int bits) {
            if (bits < from_bit || bits >= to_bit) return;
            cur += f_max[bits - from_bit].get(l, r);
            f_min[bits - from_bit].add(l, r, 1);
        };

        auto erase_min = [&](int l, int r, int bits) {
            if (bits < from_bit || bits >= to_bit) return;
            cur -= f_max[bits - from_bit].get(l, r);
            f_min[bits - from_bit].add(l, r, -1);
        };

        auto insert_max = [&](int l, int r, int bits) {
            if (bits < from_bit || bits >= to_bit) return;
            cur += f_min[bits - from_bit].get(l, r);
            f_max[bits - from_bit].add(l, r, 1);
        };

        auto erase_max = [&](int l, int r, int bits) {
            if (bits < from_bit || bits >= to_bit) return;
            cur -= f_min[bits - from_bit].get(l, r);
            f_max[bits - from_bit].add(l, r, -1);
        };

        st_min.push_back(n);
        st_max.push_back(n);

        ford(i, n) {
            while (st_min.back() < n && a[i] <= a[st_min.back()]) {
                erase_min(st_min[st_min.size() - 1], st_min[st_min.size() - 2], pc[st_min.back()]);
                st_min.pop_back();
            }

            insert_min(i, st_min.back(), pc[i]);
            st_min.push_back(i);

            while (st_max.back() < n && a[i] >= a[st_max.back()]) {
                erase_max(st_max[st_max.size() - 1], st_max[st_max.size() - 2], pc[st_max.back()]);
                st_max.pop_back();
            }

            insert_max(i, st_max.back(), pc[i]);
            st_max.push_back(i);

            ans += cur;
        }
    }


    cout << ans << "\n";
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
    const size_t MAX_HEAP = 8 * 1000L * 1000 * 1000;
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