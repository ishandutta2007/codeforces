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

using namespace std;

int l = 19;
vector < vector<int> > g;
vector<int> tin, tout;
vector <int> h;
int timer;
vector < vector<int> > up;

void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    h[v] = h[p] + 1;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int dist(int a, int b)
{
    int lc = lca(a, b);
    return h[a] + h[b] - 2 * h[lc];
}


int main()
{
    g.resize(4);
    g[0].pb(1);
    g[0].pb(2);
    g[0].pb(3);
    in(q);
    g.resize(4 + 2 * q);
    int sz = 4;
    for(int i = 0; i < q; ++i)
    {
        int v = nxt() - 1;
        //int v = sz - 1;
        g[v].pb(sz++);
        g[v].pb(sz++);
    }
    tin.resize(sz);
    tout.resize(sz);
    h.resize(sz);
    up.assign(sz, vector <int>(l + 1));

    dfs(0);
    sz = 4;

    vector <int> candidates;
    candidates.pb(1);
    candidates.pb(2);
    int cur = 2;
    for(int i = 0; i < q; ++i)
    {
        int add = sz++;
        sz++;

        vector <int> tmp = candidates;

        for(int i = 0; i < (int)candidates.size(); ++i)
        {
            int a = candidates[i];
            int dd = dist(a, add);
            if (dd > cur)
            {
                tmp.clear();
                tmp.push_back(a);
                tmp.push_back(add);
                cur = dd;
            }
        }
        cout << cur << "\n";
        candidates = tmp;
    }
    return 0;
}