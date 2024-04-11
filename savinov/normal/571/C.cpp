#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
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

long long mod = 1000000007;

long long mulmod(const long long &a, const long long &b) {
    long long ratio = (long double)a * b / mod;

    long long res = a * b - ratio * mod;

    while (res < 0) {
        res += mod;
    }
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

long long addmod(const long long &a, const long long &b) {
    long long res = a + b;
    while (res >= mod) {
        res -= mod;
    }
    return res;
}

long long submod(const long long &a, const long long &b) {
    long long res = a - b;
    while (res < mod) {
        res += mod;
    }
    return res;
}

void fib(long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y = addmod(x, y);
    } else {
        long long a, b;
        fib(n / 2, a, b);
        long long u = mulmod(a, a);
        long long v = mulmod(a, b);
        long long w = mulmod(b, b);
        x = addmod(u, w);
        y = addmod(2 * v, w);
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = mulmod(res, a);
        }
        a = mulmod(a, a);
        n >>= 1;
    }
    return res;
}

long long pw(long long a, long long n, long long m) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

const int V = 200000 * 5;
const int E = 200000 * 5;

int e = 1, he[V], ne[E], to[E];
int cc = 1, u[V], pa[V];


void add( int a, int b ) {
    ne[e] = he[a], to[e] = b, he[a] = e++;
}

int dfs(int v) {
    u[v] = cc;
    for (int x, e = he[v]; e; e = ne[e])
        if (pa[x = to[e]] == -1 || (u[pa[x]] != cc && dfs(pa[x]))) {
            pa[x] = v, pa[v] = x;
            return 1;
        }
    return 0;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "carpet"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();

    set <PII> TR;
    set <PII> FA;

    vector <int> good[m];
    vector <int> bad[m];

    for (int i = 0; i < n; ++i) {
        int k = nxt();
        while (k--) {
            int u = nxt();
            if (u < 0) {
                FA.insert({i, -u - 1});
                bad[-u - 1].push_back(i);
            } else {
                TR.insert({i, u - 1});
                good[u - 1].push_back(i);
            }
            add(i, abs(u) - 1 + n);
        }
    }
    int ok[n];
    clr(ok);
    int aa[m];
    memset(aa, 255, sizeof(aa));

    for (int i = 0; i < m; ++i) {
        if (good[i].empty()) {
            aa[i] = 0;
            for (int z : bad[i]) {
                ok[z] = 1;
            }
        }
        if (bad[i].empty()) {
            aa[i] = 1;
            for (int z : good[i]) {
                ok[z] = 1;
            }
        }

    }

    memset(pa, 255, sizeof(pa));

    int M = 0;
    for (int i = 0; i < n; ++i) {
        if (ok[i]) {
            ++M;
            continue;
        }
        if (pa[i] == -1) {
            for (int x, e = he[i]; e; e = ne[e])
                if (pa[x = to[e]] == -1) {
                    pa[i] = x, pa[x] = i;
                    M++;
                    break;
                }
        }
    }

    for (int run = 1; run;) {
        run = 0, cc++;
        for (int i = 0; i < n; ++i) {
            if (ok[i]) continue;
            if (pa[i] == -1 && dfs(i))
                M++, run = 1;
        }
    }

    if (M != n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    string ans(m, '0');

    for (int i = 0; i < m; ++i) {
        if (aa[i] != -1) {
            ans[i] = (char)('0' + aa[i]);
            continue;
        }
        if (pa[n + i] == -1) {
            ans[i] = '0';
        } else {
            if (TR.count({pa[n + i], i})) {
                ans[i] = '1';
            } else {
                ans[i] = '0';
            }
        }
    }

    cout << ans << "\n";



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}