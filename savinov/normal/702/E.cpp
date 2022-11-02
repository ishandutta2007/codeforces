#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

typedef int itn;

#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
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

template<typename T = int>
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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

typedef vector <long long> vll;

template <typename T>
vector <long long> build(T func, ll init, vi f, vll cost, ll k) {
    vll res(f.size(), init);
    vi pos(f.size());
    iota(all(pos), 0);
    while (k) {
        if (k & 1ll) {
            forn(i, f.size()) {
                res[i] = func(res[i], cost[pos[i]]);
                pos[i] = f[pos[i]];
            }
        }
        vi ff(f.size());
        vll cc(f.size());
        forn(i, f.size()) {
            cc[i] = func(cost[i], cost[f[i]]);
            ff[i] = f[f[i]];
        }
        f.swap(ff);
        cost.swap(cc);
        k >>= 1;
    }
    return res;
}


void solve(int test) {
    int n = nxt();
    ll k = nxt<ll>();
    vi f(n);
    forn(i, n) f[i] = nxt();
    vll cost(n);
    forn(i, n) cost[i] = nxt();

    std::function<ll(ll, ll)> fmin = [](const ll &a, const ll &b) {
        return std::min(a, b);
    };

    std::function<ll(ll, ll)> fsum = [&](const ll &a, const ll &b) {
        return a + b;
    };

    auto s = build(fsum, 0ll, f, cost, k);
    auto m = build(fmin, LLONG_MAX, f, cost, k);

    forn (i, n) {
        cout << s[i] << " " << m[i] << "\n";
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
    //ios_base::sync_with_stdio(false);
//    pre();
//    test();
//    exit(0);
    int t = 1;

#ifdef LOCAL
#else
#endif
    int c = 0;

    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}