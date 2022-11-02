//#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper", "fast-math", "unsafe-math-optimizations") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

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
typedef double ld;
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

mt19937 gen;

const int INF = 1e9;

struct ST {
    struct Data {
        int val;

        Data operator + (const int &r) const {
            return Data{val + r};
        }
        bool operator < (const Data &r) const {
            return val < r.val;
        }
    };

    Data val[1 << 17];
    int add[1 << 17];

    void build(int v, int tl, int tr) {
        if (tr - tl == 1) {
            val[v] = Data{INF};
            add[v] = 0;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v + v, tl, tm);
        build(v + v + 1, tm, tr);
        add[v] = 0;
        val[v] = min(val[v + v], val[v + v + 1]);
    }

    void push(int v) {
        add[v + v] += add[v];
        add[v + v + 1] += add[v];
        add[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, ll x) {
        if (l >= r) return;
        if (tl == l && tr == r) {
            add[v] += x;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;

        update(v + v, tl, tm, l, min(r, tm), x);
        update(v + v + 1, tm, tr, max(tm, l), r, x);

        val[v] = min(val[v + v] + add[v + v], val[v + v + 1] + add[v + v + 1]);
    }

    Data get(int v, int tl, int tr, int l, int r) {
        if (l >= r) return Data{INF};
        if (l == tl && r == tr) {
            return val[v] + add[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        Data res = min(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm, tr, max(l, tm), r));
        val[v] = min(val[v + v] + add[v + v], val[v + v + 1] + add[v + v + 1]);
        return res;
    }
};



void solve(int _) {
    int n = nxt();
    int k = nxt();
    vi a(n);
    forn(i, n) a[i] = nxt();

    map <int, int> last;

    vector <ST> dp(k + 1);
    forn(i, k + 1) dp[i].build(1, 0, n + 5);
    dp[0].update(1, 0, n + 5, 0, 1, -dp[0].get(1, 0, n + 5, 0, 1).val);

    for (int i = 0; i < n; ++i) {
        if (last.count(a[i])) {
            int l = last[a[i]];
//            cerr << "add " << 0 << " " << l << " " << i - l << endl;
            for (int j = 0; j <= k; ++j) {
                dp[j].update(1, 0, n + 5, 0, l + 1, i - l);
            }
        }

        last[a[i]] = i;

        for (int j = 1; j <= k; ++j) {
            ll prev = dp[j - 1].get(1, 0, n + 5, 0, i + 1).val;
//            cerr << i << " " << j << " " << prev << endl;
            dp[j].update(1, 0, n + 5, i + 1, i + 2, prev - dp[j].get(1, 0, n + 5, i + 1, i + 2).val);
        }
    }

    cout << dp[k].get(1, 0, n + 5, n, n + 1).val << "\n";
}


int main(int argc, char **argv) {
//    freopen("input", "r", stdin);
//    freopen("output", "w", stdout);

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