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

template <class T>
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

vector <pair <int, int> > g[1 << 20];

int up[20][1 << 20];
int m[20][1 << 20];
int tin[1 << 20], tout[1 << 20];

int timer;

void dfs(int v, int par) {
    tin[v] = timer++;
    for (int i = 1; i < 20; ++i) {
        up[i][v] = up[i - 1][up[i - 1][v]];
        m[i][v] = max(m[i - 1][v], m[i - 1][up[i - 1][v]]);
    }
    for (auto to : g[v]) {
        if (to.x == par) {
            continue;
        }
        up[0][to.x] = v;
        m[0][to.x] = to.y;
        dfs(to.x, v);
    }
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "ticket-office"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int n = nxt();
    int mm = nxt();

    pair <int, pair <PII, int> > e[mm];

    for (int i = 0; i < mm; ++i) {
        e[i].y.x.x = nxt() - 1;
        e[i].y.x.y = nxt() - 1;
        e[i].y.y = i;
        e[i].x = nxt();
    }
    sort(e, e + mm);

    int p[n];
    iota(p, p + n, 0);

    std::function<int(int)> get = [&](int v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = get(p[v]);
    };

    auto unite = [&](int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        p[a] = b;
        return true;
    };

    char used[mm];
    clr(used);

    long long cost = 0;

    for (int i = 0; i < mm; ++i) {
        int a = e[i].y.x.x;
        int b = e[i].y.x.y;
        bool res = unite(a, b);
        if (res) {
            g[a].pb(mp(b, e[i].x));
            g[b].pb(mp(a, e[i].x));
            used[i] = 1;
            cost += e[i].x;
        }
    }
    dfs(0, 0);
    long long ans[mm];
    for (int i = 0; i < mm; ++i) {
        if (used[i]) {
            ans[e[i].y.y] = cost;
            continue;
        }

        int u = e[i].y.x.x;
        int v = e[i].y.x.y;

        if (upper(v, u)) {
            swap(u, v);
        }
        int z = 0;
        if (upper(u, v)) {
            for (int j = 19; j >= 0; --j) {
                if (!upper(up[j][v], u)) {
                    z = max(z, m[j][v]);
                    v = up[j][v];
                }
            }
            z = max(z, m[0][v]);
        } else {
            for (int j = 19; j >= 0; --j) {
                if (!upper(up[j][v], u)) {
                    z = max(z, m[j][v]);
                    v = up[j][v];
                }
            }
            z = max(z, m[0][v]);
            swap(u, v);

            for (int j = 19; j >= 0; --j) {
                if (!upper(up[j][v], u)) {
                    z = max(z, m[j][v]);
                    v = up[j][v];
                }
            }
            z = max(z, m[0][v]);
        }
        ans[e[i].y.y] = cost + e[i].x - z;
    }

    for (int i = 0; i < mm; ++i){
        cout << ans[i] << "\n";
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}