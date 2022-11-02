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

int s[41][41][41][41];

int get(const vector <int> & l, const vector <int> & r)
{
    int res = 0;
    for(int i = 0; i < (1 << 4); ++i)
    {
        int pos[4];
        int cnt = 0;
        for(int j = 0; j < 4; ++j)
        {
            if ((i >> j) & 1)
            {
                pos[j] = l[j];
                ++cnt;
            }
            else
            {
                pos[j] = r[j] + 1;
            }
        }
        int add = s[pos[0]][pos[1]][pos[2]][pos[3]];
        if (cnt & 1)
        {
            res -= add;
        }
        else
        {
            res += add;
        }
    }
    return res;
}


int main()
{
    in(n); in(m); in(q);
    string ss[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> ss[i];
    }
    int st[n + 1][m + 1];
    clr(st);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            st[i + 1][j + 1] = (ss[i][j] - '0') + st[i][j + 1] + st[i + 1][j] - st[i][j];
        }
    }
    int ok[n + 1][n + 1][m + 1][m + 1];
    clr(ok);
    for(int i1 = 0; i1 < n; ++i1)
    {
        for(int i2 = i1; i2 < n; ++i2)
        {
            for(int j1 = 0; j1 < m; ++j1)
            {
                for(int j2 = j1; j2 < m; ++j2)
                {
                    int z = st[i2 + 1][j2 + 1] - st[i1][j2 + 1] - st[i2 + 1][j1] + st[i1][j1];
                    if (!z)
                    {
                        ok[i1][i2][j1][j2] = 1;
                    }
                }
            }
        }
    }

    for(int i1 = 0; i1 < n; ++i1)
    {
        for(int i2 = 0; i2 < n; ++i2)
        {
            for(int j1 = 0; j1 < m; ++j1)
            {
                for(int j2 = 0; j2 < m; ++j2)
                {
                    vector <int> l(4);
                    l[0] = i1;
                    l[1] = i2;
                    l[2] = j1;
                    l[3] = j2;
                    s[i1 + 1][i2 + 1][j1 + 1][j2 + 1] = ok[i1][i2][j1][j2] - get(l, l);
                }
            }
        }
    }

    while(q--)
    {
        int a = nxt() - 1;
        int b = nxt() - 1;
        int c = nxt() - 1;
        int d = nxt() - 1;
        vector <int> l(4);
        vector <int> r(4);

        l[0] = a;
        r[0] = n - 1;
        l[1] = 0;
        r[1] = c;
        l[2] = b;
        r[2] = m - 1;
        l[3] = 0;
        r[3] = d;
        cout << get(l, r) << "\n";
    }


    return 0;
}