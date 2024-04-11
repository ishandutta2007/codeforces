#ifdef LOCAL
#include <stdint.h>
#include <inttypes.h>
#include <sys/resource.h>
struct ___ { ___(){ rlimit R{}; getrlimit(RLIMIT_STACK, &R); R.rlim_cur = R.rlim_max; setrlimit(RLIMIT_STACK, &R); }} ___;
#endif

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
namespace MALLOC { const size_t MAX_HEAP = 256 * 1000 * 1000; char buf[MAX_HEAP]; size_t ptr; }
void* operator new(size_t size) { void *result = MALLOC::buf + MALLOC::ptr; MALLOC::ptr += size; return result; }
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


void pre() {}

int TTT;

ll mod = 1000000007;

ll f[1 << 20];

ll solve(vector <int> counts) {
    reverse(all(counts));
    ll res = 1;

    int cur = 0;

    for (int c : counts) {
        res = res * c % mod;
        res = res * f[cur + c - 1] % mod;
        res = res * inv(f[cur], mod) % mod;

        cur += c;
    }

    return res;
}

ll solve(int n, int c, const vector <int> &lp) {
    vector <int> primes;
    int cur = c;
    while (cur > 1) {
        primes.push_back(lp[cur]);
        cur /= lp[cur];
    }

    sort(all(primes));

    ll ans = 0;
    do {
        vector <int> used(n + 1);
        cur = c;

        vector <int> counts;

        for (int p : primes) {
            int zz = 0;
            for (int i = cur; i <= n; i += cur) {
                if (!used[i]) {
                    used[i] = 1;
                    ++zz;
                }
            }
            counts.push_back(zz);
            cur /= p;

        }
        counts.push_back(n - accumulate(all(used), 0));
        ans += solve(counts);

    } while (next_permutation(all(primes)));

    ans %= mod;
    return ans;
}

void solve(int) {
    int n = nxt();

    if (n == 1) {
        cout << "1\n";
        return;
    }

    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * i % mod;
    }

    vi lp(n + 1);
    vi c(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (!lp[i]) {
            for (int j = i; j <= n; j += i) {
                lp[j] = i;
            }
        }
        c[i] = c[i / lp[i]] + 1;
    }

    int mx = *max_element(all(c));

    vector <int> candidates;

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (c[i] == mx) {
            cerr << i << "\n";
            ans += solve(n, i, lp);
        }
    }

    ans %= mod;
    cout << ans << "\n";


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

mt19937 generator;

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