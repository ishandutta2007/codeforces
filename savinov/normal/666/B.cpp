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

int n;

vector <int> g[1 << 15];
vector <int> gr[1 << 15];

void sh(int s, int * d) {
    d[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            if (d[to] > n) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
}

int vv[1 << 15][5];
int s1[1 << 15];
int r[1 << 15][5];
int s2[1 << 15];

int d[5000][5000];

void solve(int test) {
    n = nxt();
    int m = nxt();

    memset(d, 0x3f, sizeof(d));

    for (int i = 0; i < m; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        gr[v].pb(u);
    }

    for (int i = 0; i < n; ++i) {
        sh(i, d[i]);
    }

    for (int i = 0; i < n; ++i) {
        auto cmp1 = [&](const int &a, const int &b) {
            return d[i][a] > d[i][b];
        };
        auto cmp2 = [&](const int &a, const int &b) {
            return d[a][i] > d[b][i];
        };

        for (int to = 0; to < n; ++to) {
            if (d[i][to] < n) {
                vv[i][s1[i]++] = to;
                if (s1[i] == 5) {
                    nth_element(vv[i], vv[i] + 3, vv[i] + 5, cmp1);
                    s1[i] = 4;
                }
            }
            if (d[to][i] < n) {
                r[i][s2[i]++] = to;
                if (s2[i] == 5) {
                    nth_element(r[i], r[i] + 3, r[i] + 5, cmp2);
                    s2[i] = 4;
                }
            }
        }
    }

    int ans = 0;

    vector <int> res;

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (u == v) continue;
            if (d[u][v] >= n) continue;

            for (int a = 0; a < s1[v]; ++a) {
                int A = vv[v][a];
                if (A == u || A == v) continue;
                for (int b = 0; b < s2[u]; ++b) {
                    int B = r[u][b];
                    if (B == u || B == v || B == A) continue;
                    int z = d[B][u] + d[u][v] + d[v][A];
                    if (z > ans) {
                        ans = z;
                        res = {B, u, v, A};
                    }
                }
            }
        }
    }

    cerr << ans << endl;

    for (int x : res) {
        cout << x + 1 << " ";
    }
    cout << "\n";
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
//    pre();
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