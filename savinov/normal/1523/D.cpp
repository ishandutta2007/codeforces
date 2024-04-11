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

const ll mod = 1000000007;

int color[1 << 20];
int mi[1 << 20];

int INF = 1e9;

void push(int v) {
    if (color[v] != INF) {
        color[v + v] = color[v + v + 1] = color[v];
        color[v] = INF;
    }
}

void init(int v, int tl, int tr) {
    color[v] = INF;
    mi[v] = INF;

    if (tr - tl == 1) {
        return;
    }

    int tm = (tl + tr) / 2;

    init(v + v, tl, tm);
    init(v + v + 1, tm, tr);
}

void do_color(int v, int tl, int tr, int l, int r, int c) {
    if (l >= r) return;
    if (tl == l && tr == r) {
        color[v] = c;
        return;
    }
    push(v);

    int tm = (tl + tr) / 2;
    do_color(v + v, tl, tm, l, min(tm, r), c);
    do_color(v + v + 1, tm, tr, max(tm, l), r, c);

    mi[v] = min({mi[v + v], color[v + v], mi[v + v + 1], color[v + v + 1]});
}

int get_min(int v, int tl, int tr, int l, int r) {
    if (l >= r) return INF;
    if (tl == l && tr == r) {
        return min(mi[v], color[v]);
    }

    if (color[v] != INF) return color[v];

    int tm = (tl + tr) / 2;

    return min(get_min(v + v, tl, tm, l, min(tm, r)), get_min(v + v + 1, tm, tr, max(tm, l), r));
}

int L[1 << 20], R[1 << 20];
int n, m;

set <int> children[1 << 20];

void remove(int, int, int, int);

int sum = 0;

void insert(int s) {
    if (int pos = get_min(1, 0, n, L[s], R[s]); pos < s) {
        children[pos].insert(s);
        return;
    }

    for (int v = get_min(1, 0, n, L[s], R[s]); v < m; v = get_min(1, 0, n, L[s], R[s])) {
        assert(v >= s);
        remove(v, L[s], R[s], s);
        children[s].insert(v);
    }

    sum += R[s] - L[s];
    do_color(1, 0, n, L[s], R[s], s);

    cerr << "inserted " << s + 1 << endl;
}

void remove(int s, int l, int r, int p) {
    do_color(1, 0, n, L[s], R[s], m);
    sum -= R[s] - L[s];

    for (int x : children[s]) {
        if (R[x] <= l || L[x] >= r) {
            insert(x);
        } else {
            children[p].insert(x);
        }
    }

    children[s].clear();

    cerr << "removed " << s + 1 << endl;
}

void solve(int _) {
    int n = nxt();
    int m = nxt();
    int p = nxt();

    vll mask(n);
    forn(i, n) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') mask[i] ^= (1ll << j);
        }
    }

    int ans = 0;
    string res(m, '0');
    int it = 50;
    while (it--) {
        int pos = gen() % n;

        vector <int> bits;
        forn(j, m) if (mask[pos] & (1ll << j)) bits.push_back(j);

        vector <int> dp(1 << bits.size());

        forn(i, n) {
            int x = 0;
            for (int q = 0; q < bits.size(); ++q) {
                if (!(mask[i] & (1ll << bits[q]))) x ^= 1 << q;
            }

            dp[x] += 1;
        }

        for (int i = 0; i < bits.size(); ++i) {
            for (int j = 0; j < (1 << bits.size()); ++j) {
                if (!(j & (1 << i))) dp[j ^ (1 << i)] += dp[j];
            }
        }

        for (int j = 0; j < (1 << bits.size()); ++j) {
            if (dp[j] * 2 >= n) {
                if (uax(ans, (int)bits.size() - __builtin_popcount(j))) {
                    res = string(m, '0');
                    for (int b = 0; b < bits.size(); ++b) {
                        if (!(j & (1 << b))) {
                            res[bits[b]] = '1';
                        }
                    }
                }
            }
        }
    }

    cout << res << "\n";
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