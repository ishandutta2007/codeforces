#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

using namespace std;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; typedef unsigned int uint; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

const int MAXN = 222; //  

struct FLOW {


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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "cheval";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif
    in(n); in(m);

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }
    int f[m], t[m];

    for (int i = 0; i < m; ++i) {
        in(x); in(y);
        --x;
        --y;
        if (x & 1) {
            swap(x, y);
        }
        f[i] = x;
        t[i] = y;
    }

    vector <PII> q[n];

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 2; j * j <= x; ++j) {
            if (x % j == 0) {
                q[i].push_back(mp(j, 0));
                while (x % j == 0) {
                    q[i].back().y++;
                    x /= j;
                }
            }
        }
        if (x > 1) {
            q[i].push_back(mp(x, 1));
        }
    }
    int ans = 0;
    while (1) {
        int ok = 0;
        FLOW F;
        F.n = n + 2;
        F.s = n;
        F.t = n + 1;
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            if (!q[i].empty()) {
                cur = max(cur, q[i].back().x);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!q[i].empty()) {
                ok = 1;
                if (q[i].back().x == cur) {
                    cur = q[i].back().x;
                    if (i & 1)
                        F.add_edge(i, F.t, q[i].back().y);
                    else
                        F.add_edge(F.s, i, q[i].back().y);
                    q[i].pop_back();
                }
            }
        }
        if (!ok) break;
        for (int i = 0; i < m; ++i) {
            F.add_edge(f[i], t[i], INF);
        }
        ans += F.dinic();
    }
    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL
    return 0;
}