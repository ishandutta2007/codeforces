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

typedef vector <int> vi;
typedef pair <int, int> pii;

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


int ans[1 << 20];

int up[20][1 << 20];

vi g[1 << 20];

int timer = 0;

int tin[1 << 20], tout[1 << 20];

int h[1 << 20];

void dfs(int v) {
    tin[v] = timer++;

    forn(i, 19) {
        up[i + 1][v] = up[i][up[i][v]];
    }
    for (int to : g[v]) {
        up[0][to] = v;
        h[to] = h[v] + 1;
        dfs(to);
    }
    tout[v] = timer++;
}

int upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int u, int v) {
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;

    ford(i, 20) {
        if (!upper(up[i][u], v)) {
            u = up[i][u];
        }
    }

    return up[0][u];
}

int dist(int u, int v) {
//    cerr << u + 1 << " " << v + 1 << " " << lca(u, v) + 1 << "\n";
//    cerr << h[u] + h[v] - 2 * h[lca(u, v)] << "\n";
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void solve(int test) {
    int n = nxt();

    int p[n];
    forn(i, n - 1) {
        p[i + 1] = nxt() - 1;
        g[p[i + 1]].pb(i + 1);
    }


    dfs(0);

    int u = 0, v = 0;
    int best = 0;

    forn(i, n - 1) {
//        cerr << "OK\n";
        int x = i + 1;

        int uu = u, vv = v;
        int b = best;

        if (dist(x, u) > b) {
            uu = x, vv = u;
            b = dist(x, u);
        }

        if (dist(x, v) > b) {
            uu = x, vv = v;
            b = dist(x, v);
        }

        u = uu, v = vv, best = b;

        cout << best << " ";
    }
    cout << "\n";

}


int main(int argc, char ** argv) {

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