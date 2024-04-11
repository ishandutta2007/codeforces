#include <bits/stdc++.h>
#include <x86intrin.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)
#define in(x) int (x); input((x));
#define x first
#define fi first
#define y second
#define se second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
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
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector <int> vi;
const long double PI = 3.1415926535897932384626433832795L;

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

mt19937 generator;

bool check(int v) {
    if (v == 1) return false;
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

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

const int N = 200000;
int a[N];

int n;

int dp[1 << 20];
int solve(int mask) {
    if (dp[mask] != -1) {
        return dp[mask];
    }
    if (__builtin_popcount(mask) == 2) {
        return a[31 - __builtin_clz(mask)] - a[__builtin_ctz(mask)];
    }
    int move = (n & 1) ^ __builtin_parity(mask);
    if (move == 0) {
        int best = 1e9;
        int h = 0;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                last = i;
                if (solve(mask ^ (1 << i)) < best) {
                    best = solve(mask ^ (1 << i));
                    h = i;
                }
            }
        }
        assert(h == last);
        return dp[mask] = best;
    } else {
        int best = 1e9;
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (solve(mask ^ (1 << i)) > best) {
                    best = solve(mask ^ (1 << i));
                    h = i;
                }
            }
        }
        return dp[mask] == best;
    }
}

void solve() {
    int n = nxt();
    double ra = nxt();
    double v = nxt();

    cout << setprecision(10) << fixed;

    for (int i = 0; i < n; ++i) {
        int s = nxt();
        int t = nxt();

        double len = t - s;

        double r = len / v;
        double l = (len - 2 * ra) / v;

        double alpha = v / 2 / ra;

        int it = 100;

        while (it--) {
            double m = (l + r) / 2;
            if (v * m + 2 * ra * abs(sin(alpha * m)) >= len) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << l << "\n";
    }
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "atoms"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif


    int t = 1;
    while (t--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}