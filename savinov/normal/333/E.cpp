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
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const ld EPS = 5e-12; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

#define bit(a, pos) ((a >> pos) & 1)

struct mybitset
{
    ull a[47];
    mybitset()
    {
        memset(a, 0, sizeof(a));
    }
    inline void set(int pos)
    {
        a[pos >> 6] ^= 1ull << (pos & 63);
    }
};

inline bool is_ok(const mybitset & a, const mybitset & b)
{
    forn(i, 47)
    {
        ull cur = a.a[i] & b.a[i];
        if (cur) return true;
    }
    return false;
}

struct pt
{
    int x, y;
};

struct pp
{
    int d;
    int a;
    int b;
};

inline bool cmp(const pp & a, const pp & b)
{
    return a.d > b.d;
}

inline int dist(const pt & a, const pt & b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int main()
{
    in(n);
    pt a[n];
    for(int i = 0; i < n; ++i)
    {
        a[i].x = nxt();
        a[i].y = nxt();
    }
    vector <pp> z;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < i; ++j)
            z.pb(pp{dist(a[i], a[j]), i, j});
    mybitset can[n];
    stable_sort(all(z), cmp);
    cout << setprecision(10);
    cout << fixed;
    for(auto cur : z)
    {
        if (is_ok(can[cur.a], can[cur.b]))
        {
            cout << sqrt(cur.d) / 2.0 << endl;
            return 0;
        }
        can[cur.a].set(cur.b);
        can[cur.b].set(cur.a);
    }
    return 0;

}