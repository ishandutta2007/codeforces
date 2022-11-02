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

struct edge
{
    int f, t;
    int l, r;
    bool operator < (const edge & r) const
    {
        return l < r.l;
    }
};

int p[1000];

int get(int v)
{
    return p[v] == v ? v : p[v] = get(p[v]);
}

void unite(const edge & e)
{
    int a = get(e.f);
    int b = get(e.t);

    if (a == b)
        return;
    p[a] = b;
}

void prec()
{
    for(int i = 0; i < 1000; ++i)
        p[i] = i;
}

int main()
{
    //freopen("input.txt", "r", stdin);


    in(n); in(m);

    edge e[m];
    for(int i = 0; i < m; ++i)
    {
        e[i].f = nxt() - 1;
        e[i].t = nxt() - 1;
        e[i].l = nxt();
        e[i].r = nxt();
    }
    sort(e, e + m);
    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
        int R = e[i].r;
        prec();
        for(int j = 0; j < m; ++j)
        {
            if (e[j].r >= R)
            {
                unite(e[j]);
            }
            if (get(0) == get(n - 1))
            {
                remax(ans, R - e[j].l + 1);
                break;
            }
        }
    }
    if (ans == 0)
    {
        puts("Nice work, Dima!");
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}