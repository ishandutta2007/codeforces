#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
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


void pre() {

}

struct fen {
    vector <int> s;
    fen(int n) {
        s.resize(n);
    }
    void add(int pos, int val) {
        for (; pos < s.size(); pos |= pos + 1) {
            s[pos] += val;
        }
    }

    int get(int pos) {
        int res = 0;
        for (; pos >= 0; pos &= pos + 1, --pos) {
            res += s[pos];
        }
        return res;
    }
};

const int N = 200000;

vector <int> g[N];
int color[N];

int dp0[N], s[N], dp1[N], dp2[N];

void dfs0(int v, int p) {
    s[v] = 1;
    dp0[v] = color[v];
    dp1[v] = color[v];
    int scom = 0;
    int best = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs0(to, v);
        s[v] += s[to];
        if (dp0[to]) {
            scom += s[to];
        } else {
            best = max(best, dp1[to]);
        }
    }
    dp2[v] = scom;
    if (color[v]) {
        dp1[v] = scom + best + 1;
        dp0[v] = scom + 1 == s[v];
    } else {
        dp1[v] = 0;
        dp0[v] = 0;
    }
//    cerr << v + 1 << " " << color[v] << " " << dp0[v] << " " << dp1[v] << " " << dp2[v] << endl;
}

int ans;
int n;

void dfs1(int v, int p, int d0, int d1) {

    int pmax[g[v].size() + 1];
    clr(pmax);
    int smax[g[v].size() + 1];
    clr(smax);

    int scom = dp2[v] + (n - s[v]) * d0;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            if (!d0) {
                pmax[i + 1] = d1;
                smax[i] = d1;
            } else {
                pmax[i + 1] = 0;
                smax[i] = 0;
            }
        } else {

            if (!dp0[to]) {
                pmax[i + 1] = dp1[to];
                smax[i] = dp1[to];
            } else {
                pmax[i + 1] = 0;
                smax[i] = 0;
            }
        }
    }

    for (int i = 0; i < g[v].size(); ++i) {
        pmax[i + 1] = max(pmax[i + 1], pmax[i]);
    }
    for (int i = (int)g[v].size() - 1; i >= 0; --i) {
        smax[i] = max(smax[i], smax[i + 1]);
    }
    if (color[v]) {
        //cerr << "C " << v + 1 << " " << scom << " " << pmax[g[v].size()] << " " <<  d1  << endl;
        ans = max(ans, scom + 1 + pmax[g[v].size()]);
    }

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        } else {
            if (!color[v]) {
                dfs1(to, v, 0, 0);
            } else {
                int s1 = scom + 1 - dp0[to] * s[to];
                int dd0 = 0;
                if (s1 == n - s[to]) {
                    dd0 = 1;
                }
                int dd1 = s1 + max(pmax[i], smax[i + 1]);
                dfs1(to, v, dd0, dd1);
            }
        }
    }

}

void solve(int test) {
    n = nxt();
    int k = nxt();

    int a[n];

    for (int i = 0 ;i < n; ++i) {
        a[i] = nxt();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].pb(v);
        g[v].pb(u);
    }

    int l = 0, r = 1000000;

    while (l < r) {
        int m = (l + r + 1) / 2;
        for (int i = 0; i < n; ++i) {
            color[i] = a[i] >= m;
        }
        ans = 0;
        dfs0(0, 0);
        dfs1(0, 0, 1, 0);
//        cerr << m << " " << ans << endl;
        if (ans >= k) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << "\n";
}



int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
//    pre();
#ifdef LOCAL
#endif
    pre();
    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}