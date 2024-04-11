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

long long mod = 100711433;

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

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

const int MAXN = 200000;

vector<int> g[MAXN];
char used[MAXN];
int timer = 0, tin[MAXN], fup[MAXN];

set <PII> bridges;

map <PII, int> cnt;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v] && cnt[{v, to}] == 1) {
                bridges.insert({v, to});
                bridges.insert({to, v});
            }
        }
    }
}

int n;

void find_bridges() {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}

struct dsu {

    int p[MAXN];
    int sz[MAXN];

    void init() {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get(int v) {
        if (p[v] != v) {
            p[v] = get(p[v]);
        }
        return p[v];
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        p[a] = b;
        sz[b] += sz[a];
    }
};

dsu dsu1, dsu2;

struct Hld {
    vector<vector<int> > g;
    vector<vector<int> > up;
    vector<int> tin;
    vector<int> tout;
    int timer;

    Hld(int n = 0) {
        g.resize(n);
        tin.resize(n);
        tout.resize(n);
        up.resize(n);
        timer = 0;
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int v, int p) {
        tin[v] = timer++;
        up[v].resize(20);
        up[v][0] = p;
        for (int i = 1; i < 20; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
        }
        tout[v] = timer++;
    }

    vector <int> roots;

    void build() {
        for (int i = 0; i < n; ++i) {
            if (tout[i] == 0) {
                roots.push_back(i);
                dfs(i, i);
            }
        }
    }

    bool upper(int a, int b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    int lca(int a, int b) {
        if (upper(a, b)) {
            return a;
        }
        if (upper(b, a)) {
            return b;
        }
        for (int i = 19; i >= 0; --i) {
            if (!upper(up[a][i], b)) {
                a = up[a][i];
            }
        }
        return up[a][0];
    }

    vector <int> addUp[MAXN];
    vector <int> eraUp[MAXN];


    vector <int> addDo[MAXN];
    vector <int> eraDo[MAXN];

    multiset<int>* merge(multiset<int>* l, multiset<int>* r) {
        if (l->size() < r->size()) {
            swap(l, r);
        }
        for (int x : *r) {
            l->insert(x);
        }
        return l;
    }

    pair <multiset<int>*, multiset<int>*> dfs3(int v, int p) {
        pair <multiset<int>*, multiset<int>*> res = {new multiset<int>(), new multiset<int>()};
        for (int x : addUp[v]) {
            res.x->insert(x);
        }
        for (int x : addDo[v]) {
            res.y->insert(x);
        }

        for (int to : g[v]) {
            if (to == p) continue;
            auto t = dfs3(to, v);
            if (!t.x->empty() && !t.y->empty()) {
                cout << "No\n";
                exit(0);
            }
            res.x = merge(res.x, t.x);
            res.y = merge(res.y, t.y);
        }

        for (int x : eraUp[v]) {
            res.x->erase(res.x->find(x));
        }
        for (int x : eraDo[v]) {
            res.y->erase(res.y->find(x));
        }
        return res;
    }

} hld;


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

    n = nxt();
    int m = nxt();
    int q = nxt();

    for (int i = 0; i < m; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        cnt[{u, v}]++;
        cnt[{v, u}]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    find_bridges();

    dsu1.init();
    dsu2.init();

    hld = Hld(n);

    for (int i = 0; i < n; ++i) {
        for (int to : g[i]) {
            if (!bridges.count({i, to})) {
                dsu2.unite(i, to);
            }
            dsu1.unite(i, to);
        }
    }

    for (const PII & e : bridges) {
        if (e.x > e.y) continue;
        int u = dsu2.get(e.x);
        int v = dsu2.get(e.y);
        hld.addEdge(u, v);
    }

    hld.build();


    while (q--) {
        int s = nxt() - 1;
        int t = nxt() - 1;

        if (dsu1.get(s) != dsu1.get(t)) {
            cout << "No\n";
            return 0;
        }
        s = dsu2.get(s);
        t = dsu2.get(t);

        int l = hld.lca(s, t);

        hld.addUp[s].push_back(s);
        hld.eraUp[l].push_back(s);
        hld.addDo[t].push_back(t);
        hld.eraDo[l].push_back(t);
    }

    for (int s : hld.roots) {
        hld.dfs3(s, s);
    }

    cout << "Yes\n";



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}