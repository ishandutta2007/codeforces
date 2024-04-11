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

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return pw(a, mod - 2);
}

const int K = 10;

struct data {
    int sz;
    int x[K];
    data cp() {
        data res;
        res.sz = sz;
        memcpy(res.x, x, sizeof(x));
        return res;
    }
    data() {
        sz = 0;
    }
};

void merge(const data &l, const data &r, data &res) {
    int i = 0, j = 0, k = 0;
    while (k < K && i < l.sz && j < r.sz) {
        if (l.x[i] < r.x[j]) {
            res.x[k++] = l.x[i++];
        } else {
            res.x[k++] = r.x[j++];
        }
    }
    while (k < K && i < l.sz) {
        res.x[k++] = l.x[i++];
    }
    while (k < K && j < r.sz) {
        res.x[k++] = r.x[j++];
    }
    res.sz = k;
}

const int N = 100111;

const int L = 17;

data t[L][N];
int p[L][N];

int tin[N];
int tout[N];

vector <int> ids[N];

vector <int> g[N];

#define tm werwerwe

int tm = 0;

void dfs(int v, int par) {
    tin[v] = tm++;
    p[0][v] = par;
    for (int i = 0; i < (int)ids[v].size() && i < K; ++i) {
        t[0][v].x[t[0][v].sz++] = ids[v][i];
    }
//    cerr << v << " " << t[0][v].sz << "\n";
    for (int i = 1; i < L; ++i) {
        p[i][v] = p[i - 1][p[i - 1][v]];
        merge(t[i - 1][v], t[i - 1][p[i - 1][v]], t[i][v]);
    }

    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        dfs(to, v);
    }
    tout[v] = tm++;
}

int upper(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (upper(u, v)) {
        return u;
    }
    if (upper(v, u)) {
        return v;
    }
    for (int i = L - 1; i >= 0; --i) {
        if (!upper(p[i][u], v)) {
            u = p[i][u];
        }
    }
    return p[0][u];
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();
    int q = nxt();

    for (int i = 0; i + 1 < n; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    g[n].push_back(0);

    for (int i = 0; i < m; ++i) {
        int v = nxt() - 1;
        ids[v].push_back(i);
    }

    dfs(n, n);

    while (q--) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        int a = nxt();

        int l = p[0][lca(u, v)];

        data res;

        for (int i = L - 1; i >= 0; --i) {
            if (!upper(p[i][u], l)) {
                data aa;
                merge(res, t[i][u], aa);
                res = aa.cp();
                u = p[i][u];
            }
        }
        swap(u, v);
        for (int i = L - 1; i >= 0; --i) {
            if (!upper(p[i][u], l)) {
                data aa;
                merge(res, t[i][u], aa);
                res = aa.cp();
                u = p[i][u];
            }
        }
        assert(u == v);
        data aa;
        merge(res, t[0][u], aa);
        res = aa.cp();

        int k = min(res.sz, a);

        printf("%d", k);

        for (int i = 0; i < k; ++i) {
            printf(" %d", res.x[i] + 1);
        }
        printf("\n");
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}