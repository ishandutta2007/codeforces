#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define itn int

#define next next12345
#define prev prev12345
#define x1 x12345
#define y1 y12345

using namespace std;

template <typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template <class _T> inline _T sqr(const _T& x) {return x * x;}
template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template <typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

const int MAXN = 1000; //  
const int INF = 1000000000; // -

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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int k = nxt();

    const int N = 25000;

    int primes[N + 1];
    clr(primes);

    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                primes[i] = 1;
                break;
            }
        }
    }

    int a[k];

    n = k + 2;
    s = k;
    t = k + 1;

    int a1 = 0;
    int a2 = 0;

    for (int i = 0; i < k; ++i) {
        a[i] = nxt();
        if (a[i] % 2 == 0) {
            add_edge(s, i, 2);
            ++a1;
        } else {
            add_edge(i, t, 2);
            ++a2;
        }
    }
    if (a1 != a2) {
        puts("Impossible");
        return 0;
    }

    for (int i = 0; i < k; ++i) {
        if (a[i] % 2) continue;
        for (int j = 0; j < k; ++j) {
            if (!primes[a[i] + a[j]]) {
                add_edge(i, j, 1);
            }
        }
    }

    int flow = dinic();

    if (flow != 2 * a1) {
        puts("Impossible");
        return 0;
    }
    char used[k];
    clr(used);

    vector <vector <int> > ans;

    for (int i = 0; i < k; ++i) {
        if (!used[i]) {
            ans.push_back(vector <int>());

            int v = i;
            while (!used[v]) {
                used[v] = 1;
                ans.back().push_back(v);
                if (a[v] % 2) {
                    for (int to : g[v]) {
                        if (e[to].flow == -1) {
                            v = e[to].b;
                            e[to].flow = 0;
                            e[to ^ 1].flow = 0;
                            break;
                        }
                    }
                } else {
                    for (int to : g[v]) {
                        if (e[to].flow == 1) {
                            v = e[to].b;
                            e[to].flow = 0;
                            e[to ^ 1].flow = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i].size();
        for (int x : ans[i]) {
            cout << " " << x + 1;
        }
        cout << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
};