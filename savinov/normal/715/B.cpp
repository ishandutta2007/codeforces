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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

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

template <typename T>
T pw(T a, T n, T p);

template <typename T>
T inv(T a, T p);

void pre() {

}

struct G {
    set <pii> q;
    vll dist;
    vector <vector <pii> > g;

    G(int n) {
        dist.assign(n, INT_MAX);
        g.resize(n);
    }

    void addEdge(int u, int v, int w) {
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    void doit(int s) {
        dist[s] = 0;
        q.insert(mp(0, s));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto to : g[v]) {
                if (dist[to.x] > dist[v] + to.y) {
                    q.erase(mp(dist[to.x], to.x));
                    dist[to.x] = dist[v] + to.y;
                    q.insert(mp(dist[to.x], to.x));
                }
            }
        }
    }
};

struct edge {
    int u;
    int v;
    int w;
};

void solve(int test) {
    int n = nxt();
    int m = nxt();
    int L = nxt();
    int s = nxt();
    int t = nxt();

    vector<edge> e;

    forn(i, m) {
        int u = nxt();
        int v = nxt();
        int w = nxt();
        e.push_back(edge{u, v, w});
    }
    {
        G g(n);
        for (auto E : e) {
            g.addEdge(E.u, E.v, max(E.w, 1));
        }
        g.doit(s);
        if (g.dist[t] > L) {
            cout << "NO\n";
            return;
        }
    }
    {
        G g(n);
        for (auto E : e) {
            if (E.w == 0) continue;
            g.addEdge(E.u, E.v, E.w);
        }
        g.doit(s);
        if (g.dist[t] < L) {
            cout << "NO\n";
            return;
        }
    }

    int l = 0, r = m;

    int MANY = 1000000001;

    while (l < r) {
        int mid = (l + r) / 2;
        G T(n);
        for (int i = 0; i < mid; ++i) {
            if (e[i].w == 0) {
                T.addEdge(e[i].u, e[i].v, 1);
            } else {
                T.addEdge(e[i].u, e[i].v, e[i].w);
            }
        }
        for (int i = mid; i < m; ++i) {
            if (e[i].w == 0) {
                T.addEdge(e[i].u, e[i].v, MANY);
            } else {
                T.addEdge(e[i].u, e[i].v, e[i].w);
            }
        }
        T.doit(s);
        cerr << mid << " " << T.dist[t] << endl;
        if (T.dist[t] > L) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cerr << "MID " << l << endl;
    G T(n);

    for (int i = 0; i < l; ++i) {
        if (e[i].w == 0) {
            T.addEdge(e[i].u, e[i].v, 1);
        } else {
            T.addEdge(e[i].u, e[i].v, e[i].w);
        }
    }
    for (int i = l; i < m; ++i) {
        if (e[i].w == 0) {
            T.addEdge(e[i].u, e[i].v, MANY);
        } else {
            T.addEdge(e[i].u, e[i].v, e[i].w);
        }
    }

    T.doit(s);

    int add = L - T.dist[t] + 1;

    cerr << "DIST " << T.dist[t] << endl;

    G ch(n);

    cout << "YES\n";
    for (int i = 0; i < l - 1; ++i) {
        if (e[i].w == 0) {
            cout << e[i].u << " " << e[i].v << " " << 1 << "\n";
            ch.addEdge(e[i].u, e[i].v, 1);
        } else {
            cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
            ch.addEdge(e[i].u, e[i].v, e[i].w);
        }
    }
    if (l != 0) {
        assert(e[l - 1].w == 0);
        cout << e[l - 1].u << " " << e[l - 1].v << " " << add << "\n";
        ch.addEdge(e[l - 1].u, e[l - 1].v, add);
    }
    for (int i = l; i < m; ++i) {
        if (e[i].w == 0) {
            cout << e[i].u << " " << e[i].v << " " << MANY << "\n";
            ch.addEdge(e[i].u, e[i].v, MANY);
        } else {
            cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
            ch.addEdge(e[i].u, e[i].v, e[i].w);
        }
    }
    ch.doit(s);
    assert(ch.dist[t] == L);
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
    pre();
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
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

template<typename T = long long>
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
template <typename T>
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

template <typename T>
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