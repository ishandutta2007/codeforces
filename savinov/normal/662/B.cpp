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

typedef int itn;

//#define next next12345
//#define prev prev12345
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
typedef pair<int, int> PII;
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

vector <pair <int, int> > g[1 << 20];

int used[1 << 20];

bool ok;
int b, w;

vector <int> C[2];

void dfs(int v, int c) {
    used[v] = c;
    C[c].pb(v);
    for (auto to : g[v]) {
        if (used[to.x] == -1) {
            dfs(to.x, c ^ to.y);
        } else {
            if (used[to.x] != (c ^ to.y)) {
                ok = false;
            }
        }
    }
}

void solve(int test) {
    int n = nxt();
    int m = nxt();

    for (int i = 0; i < m; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        string s;
        cin >> s;
        int c;
        if (s == "R") {
            c = 0;
        } else {
            c = 1;
        }
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
        // << u << " " << v << " " << c << endl;
    }
    int it = 2;

    int ans = INT_MAX;

    vector <int> z;

    while (it--) {
        memset(used, 255, sizeof(used));

        int ta = 0;

        vector <int> ANS;

        for (int i = 0; i < n; ++i) {
            if (used[i] == -1) {
                ok = 1;
                b = 0, w = 0;
                C[0].clear();
                C[1].clear();
                dfs(i, 0);
                if (!ok) {
                    goto l1;
                }
                if (C[0].size() < C[1].size()) {
                    for (int v : C[0]) {
                        ANS.pb(v);
                    }
                } else {
                    for (int v : C[1]) {
                        ANS.pb(v);
                    }
                }
            }
        }
        if (ANS.size() < ans) {
            ans = ANS.size();
            z = ANS;
        }
        l1:;
        for (int i = 0; i < n; ++i) {
            for (auto & x : g[i]) {
                x.y ^= 1;
            }
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << "\n";
    for (int x : z) {
        cout << x + 1 << " ";
    }
    if (ans != -1) cout << "\n";
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
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