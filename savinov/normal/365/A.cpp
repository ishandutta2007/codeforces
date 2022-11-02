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

int c[202][202];
int f[202][202];

int p[202];
int q[202];
int d[202];

int s, t;

int z;

bool bfs()
{
    memset(d, 255, sizeof(d));
    int qs = 0, qf = 0;
    q[qf++] = s;
    d[s] = 0;
    while(qs != qf)
    {
        int v = q[qs++];
        for(int i = 0; i < z; ++i)
        {
            if (d[i] == -1 && c[v][i] - f[v][i] > 0)
            {
                d[i] = d[v] + 1;
                p[i] = v;
                q[qf++] = i;
            }
        }
    }
    return d[t] != -1;
}


int maxflow()
{
    int flow = 0;
    while(bfs())
    {
        int ff = INF;
        for(int v = t; v != s; v = p[v])
        {
            remin(ff, c[p[v]][v] - f[p[v]][v]);
        }
        for(int v = t; v != s; v = p[v])
        {
            f[p[v]][v] += ff;
            f[v][p[v]] -= ff;
        }
        flow += ff;
    }
    return flow;
}

int main()
{
    in(n);
    in(k);


    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        char ok = true;
        for(int p = 0; p <= k; ++p)
        {
            if (s.find(p + '0') == string::npos)
            {
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}