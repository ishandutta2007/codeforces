#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline") //Optimization flags
//#pragma GCC option("arch=native", "tune=native", "no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")  //Enable AVX

#ifdef LOCAL

#include <cstdint>
#include <cinttypes>
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

void solve(int _) {
    int n = nxt();
    int k = nxt();

    auto cmp = [&](vector <int> a, vector <int> b) {
        assert(a.size() == b.size());

        sort(all(a));
        sort(all(b));

        vector <int> c;
        set_intersection(all(a), all(b), back_inserter(c));

        a.erase(set_difference(all(a), all(c), a.begin()), a.end());
        b.erase(set_difference(all(b), all(c), b.begin()), b.end());

        assert(a.size() == b.size());
        if (a.empty()) {
            return 0;
        }

        cout << "? " << a.size() << " " << b.size() << endl;
        forn(i, a.size()) {
            cout << a[i] + 1;
            if (i + 1 < a.size()) {
                cout << " ";
            } else {
                cout << endl;
            }
        }

        forn(i, b.size()) {
            cout << b[i] + 1;
            if (i + 1 < b.size()) {
                cout << " ";
            } else {
                cout << endl;
            }
        }

        string res;
        cin >> res;

        if (res == "FIRST") return -1;
        if (res == "SECOND") return 1;
        return 0;
    };

    set <int> stones;

    auto check = [&](int l, int r) {
        assert(r - l <= stones.size());

        vector <int> a, b;
        auto it = stones.begin();

        for (int i = l; i < r; ++i) {
            a.push_back(i);
            b.push_back(*(it++));
        }

        auto res = cmp(a, b) == 0;

        if (res) {
            for (auto x : a) stones.insert(x);
        }

        return res;
    };

    function<void(int, int)> findStone = [&](int l, int r) {
        cerr << l << " " << r << endl;
        if (r - l == 1) {
            stones.insert(l);
            return;
        }


        int len = (r - l + 1) / 2;

        vector <int> a(len);
        vector <int> b(len);
        iota(all(a), l);
        iota(all(b), r - len);

        if (cmp(a, b) <= 0) {
            findStone(l, l + len);
        } else {
            findStone(r - len, r);
        }
    };

    findStone(0, n);
    assert(!stones.empty());
    cerr << "! stone " << *stones.begin() << endl;

    if (!check(0, 1)) {
        cout << "! 1" << endl;
        return;
    }

    int t = 1;
    while (check(t, min(n, t + t))) {
        t *= 2;
    }

    int lo = t, hi = min(n, t + t);
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;

        if (check(t, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << "! " << hi << endl;

}

int main(int argc, char **argv) {
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
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