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

struct graph {
    vector <vector <pii> > g;
    vector <int> size;
    vector <int> par;

    graph(int n) {
        g.resize(n);
        size.resize(n);
        par.assign(n, -1);
    }

    void addEdge(int u, int v, int d) {
        g[u].pb(mp(v, d));
        g[v].pb(mp(u, d));
    }

    void dfs(int v, int p) {
        size[v] = 1;
        for (auto to : g[v]) {
            if (to.x == p) continue;
            if (par[to.x] != -1) continue;
            dfs(to.x, v);
            size[v] += size[to.x];
        }
    }

    ll M;

    ll powers[111111];
    ll ipowers[111111];

    void initPowers() {
        powers[0] = 1;
        ipowers[0] = 1;
        ll iM;
        for (iM = 1; (iM * M + 1) % 10 != 0; ++iM) {}
        iM = (iM * M + 1) / 10;
        for (int i = 1; i < 111111; ++i) {
            powers[i] = powers[i - 1] * 10 % M;
            ipowers[i] = ipowers[i - 1] * iM % M;
        }
    }

    ll ans = 0;

    unordered_map <int, int> z;

    void dfs4(int v, int p, int h, ll cur) {
        ++s;
        z[cur]++;
        for (auto to : g[v]) {
            if (par[to.x] != -1) continue;
            if (to.x == p) continue;
            dfs4(to.x, v, h + 1, (cur + powers[h] * to.y) % M);
        }
    }

    void dfs5(int v, int p, int h, ll cur) {
        ++s;
        z[cur]--;
        for (auto to : g[v]) {
            if (par[to.x] != -1) continue;
            if (to.x == p) continue;
            dfs5(to.x, v, h + 1, (cur + powers[h] * to.y) % M);
        }
    }

    void dfs6(int v, int p, int h, ll cur) {
        ++s;
        ll d = (M - cur) * ipowers[h] % M;
        ans += z[d];
        for (auto to : g[v]) {
            if (par[to.x] != -1) continue;
            if (to.x == p) continue;
            dfs6(to.x, v, h + 1, (cur * 10 + to.y) % M);
        }
    }

    int s = 0;
    void doit(int v) {
        //z.clear();
        dfs4(v, v, 0, 0);
        ans += z[0] - 1;
//        cerr << v << " " << ans << endl;
        //cerr << ans << "\n";
        for (auto to : g[v]) {
            if (par[to.x] != -1) continue;
//            cerr << to.y << endl;
            dfs5(to.x, v, 1, to.y);
//            cerr << v << " " << ans << endl;
//            cerr << z[0] << "\n";
            dfs6(to.x, v, 1, to.y);
//            cerr << v << " " << ans << endl;
            dfs4(to.x, v, 1, to.y);
        }
        dfs5(v, v, 0, 0);
    }

    void centroid(int v, int p, int n, int prev) {
        for (auto to : g[v]) {
            if (to.x == p) continue;
            if (par[to.x] != -1) continue;
            if (2 * size[to.x] > n) {
                centroid(to.x, v, n, prev);
                return;
            }
        }

        par[v] = prev;

//        cerr << "CENTER " << v << endl;

        doit(v);

        for (auto to : g[v]) {
            if (par[to.x] == -1) {
                dfs(to.x, to.x);
                centroid(to.x, v, size[to.x], v);
            }
        }
    }

    void init() {
        dfs(0, 0);
        centroid(0, 0, g.size(), -2);
    }

};

void solve(int test) {
    int n = nxt();
    int m = nxt();
    if (m == 1) {
        cout << 1ll * n * (n - 1) << "\n";
        return;
    }
    graph G(n);
    G.M = m;
    G.initPowers();
    G.z.reserve(5000000);
    forn(i, n - 1) {
//        int u = i;
//        int v = i + 1;
        int u = nxt();
        int v = nxt();
        int d = nxt() % m;
//        int d = rand() % 9 + 1;
        G.addEdge(u, v, d);
    }
    cerr << "OK\n";
    G.init();
    cerr << G.s << endl;
    cout << G.ans << "\n";
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