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
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

template <typename T>
struct edge
{
   int from, to, u, f;
   T cost;
   edge(){}
   edge(int from, int to, int u, T cost = 0):from(from),to(to),u(u),cost(cost), f(0){}
};


template <typename T>
struct graph
{
    int n;
    vector <int> * g;
    int ec;
    edge<T> * e;
    char * used;
    T * d;
    int * p, * q;
    int flow;
    graph(int _n, int _m):n(_n)
    {
        g = new vector <int>[n];
        e = new edge<T>[2 * _m];
        d = new T[n];
        p = new int[n];
        q = new int[n];
        used = new char[n];
        ec = 0;
        flow = 0;
    }
    inline void add_edge(int from, int to, int u, T cost)
    {
       g[from].pb(ec);
       e[ec++] = edge<T>(from, to, u, cost);
       g[to].pb(ec);
       e[ec++] = edge<T>(to, from, 0, -cost);
    }

    inline T min_cost_flow(int max_flow, int s, int t)
    {
        for(int i = 0; i < ec; ++i)
            e[i].f = 0;
        flow = 0;
        T cost = 0;
        while (flow < max_flow)
        {
           memset(used, 0, n * sizeof(char));
           memset(d, 0x3f, n * sizeof(T));
           T inf = d[0];
           d[s] = 0;
           int qs = 0, qf = 0;
           q[qf++] = s;
           used[s] = 1;
           while (qs != qf)
           {
               int v = q[qs++];
               if (qs == n) qs = 0;
               used[v] = 0;
               for (size_t j = 0; j < g[v].size(); ++j)
               {
                   int ed = g[v][j], to = e[ed].to;
                   T len = e[ed].cost;
                   if (e[ed].u > e[ed].f && d[to] > d[v] + len)
                   {
                       d[to] = d[v] + len;
                       p[to] = ed;
                       if (!used[to])
                       {
                           q[qf++] = to;
                           if (qf == n) qf = 0;
                           used[to] = 1;
                       }
                   }
               }
           }
           if (d[t] == inf) break;
           int cur = t;
           int add_flow = max_flow - flow;
           T add_cost = 0;
           while(cur != s)
           {
               int from = e[p[cur]].from;
               add_cost += e[p[cur]].cost;
               remin(add_flow, e[p[cur]].u - e[p[cur]].f);
               cur = from;
           }
           flow += add_flow;
           cur = t;

           while(cur != s)
           {
               int from = e[p[cur]].from;
               e[p[cur]].f += add_flow;
               e[p[cur] ^ 1].f -= add_flow;
               cur = from;
           }
           cost += add_flow * add_cost;
        }
        if (flow == max_flow)
            return cost;
        else
            return INF;
    }
    inline T min_cost_max_flow(int s, int t)
    {
        return min_cost_flow(INF, s, t);
    }
};

int main()
{
    in(n); in(k);

    graph<int> g(n, 2 * n * n);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int c = nxt();
            if (c)
            {
                g.add_edge(i, j, c, 0);
                g.add_edge(i, j, INF, 1);
            }
        }
    }
    int l = 0, r = 51 * 1000000;
    while(l < r)
    {
        int m = (l + r + 1) / 2;
        if (g.min_cost_flow(m, 0, n - 1) > k)
            r = m - 1;
        else
            l = m;
    }
    cout << l << endl;
    return 0;
}