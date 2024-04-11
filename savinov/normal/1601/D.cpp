//#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")  //Enable AVX

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

template <class T>
struct fenwick {
    vector <T> data;
    fenwick(int n) {
        data.resize(n);
    }

    void add(int pos, T val) {
        for (; pos < data.size(); pos |= pos + 1) {
            data[pos] = data[pos] + val;
        }
    }

    T get(int r) const {
        T res{};
        for (; r >= 0; r &= r + 1, --r) {
            res = res + data[r];
        }
        return res;
    }
};

struct query {
    int index;

    int r;
    int mul;
};

void solve(int) {
    int n = nxt();
    int d = nxt();

    vector <int> s(n);
    vector <int> a(n);

    vector <int> b(n);
    forn(i, n) {
        b[i] = s[i] = nxt();
        a[i] = nxt();
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    vector <vector <int> > bs(b.size() + 1);

    vector <vector <query> > q(b.size() + 1);

    vector <int> bsz(b.size() + 1);
    vector <int> qsz(b.size() + 1);
    forn(i, n) {
        s[i] = lower_bound(all(b), s[i]) - b.begin();
        a[i] = lower_bound(all(b), a[i]) - b.begin();

        bsz[s[i]]++;
        qsz[s[i]]++;
        qsz[a[i]]++;
    }

    forn(i, b.size() + 1) {
        bs[i].reserve(bsz[i]);
        q[i].reserve(qsz[i]);
    }

    forn(i, n) {
        bs[s[i]].push_back(i);

        q[s[i]].push_back({i, s[i], -1});
        q[a[i]].push_back({i, s[i], 1});
    }

    vector <int> tmp(n);
    fenwick<int> f(b.size() + 1);

    forn(i, b.size() + 1) {
        for (auto qq : q[i]) {
            tmp[qq.index] += qq.mul * f.get(qq.r);
        }

        for (auto id: bs[i]) {
            f.add(a[id], 1);
        }
    }

    vector <int> dp(b.size() + 1);

    ford(i, b.size()) {
        dp[i] = 0;
        int r = 0;

        for (auto x : bs[i]) {
            if (a[x] <= i) {
                ++r;
                continue;
            }

            dp[i] = max(dp[i], dp[a[x]] + tmp[x] + 1);
        }

        dp[i] = max(dp[i], dp[i + 1] + r);
    }

    cout << dp[lower_bound(all(b), d) - b.begin()] << "\n";
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