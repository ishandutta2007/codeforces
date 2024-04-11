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

const int MAXN = 1000; //  
const int INF = 1000000000; // -

struct D {
    struct edge {
        int a, b, cap, flow;
    };

    int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
    vector<edge> e;
    vector<int> g[MAXN];

    void add_edge (int a, int b, int cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back ((int) e.size());
        e.push_back (e1);
        g[b].push_back ((int) e.size());
        e.push_back (e2);
    }

    bool bfs() {
        int qh=0, qt=0;
        q[qt++] = s;
        memset (d, -1, n * sizeof d[0]);
        d[s] = 0;
        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            for (size_t i=0; i<g[v].size(); ++i) {
                int id = g[v][i],
                        to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow)  return 0;
        if (v == t)  return flow;
        for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                    to = e[id].b;
            if (d[to] != d[v] + 1)  continue;
            int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int dinic() {
        int flow = 0;
        for (;;) {
            if (!bfs())  break;
            memset (ptr, 0, n * sizeof ptr[0]);
            while (int pushed = dfs (s, INF))
                flow += pushed;
        }
        return flow;
    }
};

struct E {
    int u;
    int v;
    int c;
};

vector <E> e;


struct G {
    vector<int> g[MAXN];
    char used[MAXN];
    int ok[MAXN];
    int comp[MAXN];
    int timer, tin[MAXN], fup[MAXN];
    int n;

    void add_edge(int id) {
        g[e[id].u].push_back(2 * id);
        g[e[id].v].push_back(2 * id + 1);
    }

    void clear() {
        forn(i, n) {
            g[i].clear();
        }
    }

    void dfs (int v, int p = -1) {
//        cerr << v + 1 << " ";
        used[v] = true;
        tin[v] = fup[v] = timer++;
        for (size_t i=0; i<g[v].size(); ++i) {
            int eid = g[v][i];
            if (p != -1 && (eid ^ p) == 1)  continue;
            int to = (eid & 1) ? e[eid >> 1].u : e[eid >> 1].v;
            if (used[to])
                fup[v] = min (fup[v], tin[to]);
            else {
                dfs (to, eid);
                fup[v] = min (fup[v], fup[to]);
            }
        }
    }

    int sz;

    int ans = INT_MAX;
    int ID;

    int s, t;

    bool dfs2(int v, int p, int c) {
        used[v] = true;
        comp[v] = c;
        bool res = v == t;
        for (size_t i=0; i<g[v].size(); ++i) {
            int eid = g[v][i];
            if ((eid ^ p) == 1)  continue;
            int to = (eid & 1) ? e[eid >> 1].u : e[eid >> 1].v;
            if (used[to]) {
                continue;
            } else {
                if (fup[to] > tin[v]) {
//                    cerr << "BRIDGE " << (eid / 2) + 1 << "\n";
                    if (dfs2(to, eid, sz++)) {
                        if (e[eid >> 1].c < ans) {
                            ans = e[eid >> 1].c;
                            ID = eid >> 1;
                        }
                        res = true;
                    }
                } else {
                    if (dfs2(to, eid, c)) {
                        res = true;
                    }
                }
            }
        }
        return res;
    }

    int find_bridges() {
        timer = 0;
        for (int i=0; i<n; ++i)
            used[i] = false;
        dfs(s, -1);
//        cerr << "\n";
        sz = 0;
        ans = INT_MAX;
        for (int i=0; i<n; ++i)
            used[i] = false;
        bool res = dfs2(s, -1, sz++);
        if (!res) return 0;
        if (comp[s] == comp[t]) {
            return INT_MAX;
        }
        return ans;
    }
};

void solve(int test) {
    int n = nxt();
    int m = nxt();

    int s = nxt() - 1;
    int t = nxt() - 1;


    forn(i, m) {
        E z;
        z.u = nxt() - 1;
        z.v = nxt() - 1;
        z.c = nxt();
        e.pb(z);
    }


    D d;
    d.n = n;
    d.s = s;
    d.t = t;

    for (int i = 0; i < m; ++i) {
        int c = 0;
        if (e[i].u != e[i].v) {
            c = 1;
        }
        d.add_edge(e[i].u, e[i].v, c);
        d.add_edge(e[i].v, e[i].u, c);
    }

    int f = d.dinic();

    if (f == 0) {
        cout << "0\n0\n";
        return;
    }

    if (f > 2) {
        cout << "-1\n";
        return;
    }
    vector <int> ids;
    for (int i = 0; i < 4 * m; i += 2) {
        if (d.e[i].flow > 0) {
            ids.push_back(i / 4);
        }
    }
//    cerr << f << endl;
//    cerr << ids.size() << "\n";
    G g;
    g.n = n;
    g.s = s;
    g.t = t;

    int ans = INT_MAX;

    vector <int> I;

    for (int id : ids) {
        g.clear();
//        cerr << id + 1 << "\n";
        for (int i = 0; i < m; ++i) {
            if (i != id) {
                g.add_edge(i);
            }
        }
        int res = g.find_bridges();
        if (res == INT_MAX) {
            continue;
        }
        if (res == 0) {
            if (e[id].c < ans) {
                ans = e[id].c;
                I.clear();
                I.push_back(id);
            }
        } else {
            if (g.ans + e[id].c < ans) {
                ans = g.ans + e[id].c;
                I.clear();
                I.push_back(id);
                I.push_back(g.ID);
            }
        }

    }

    cout << ans << "\n";

    cout << I.size() << "\n";
    for (int x : I) {
        cout << x + 1 << " ";
    }
    cout << "\n";

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