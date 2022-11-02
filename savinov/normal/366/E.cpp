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

int main()
{
    in(n); in(m); in(k); in(s);

    short a[n][m];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            a[i][j] = nxt() - 1;
    }
    //cout << endl;
    short dp[k][k];
    memset(dp, 255, sizeof(dp));
    short dp1[n][m][k], dp2[n][m][k];
    memset(dp1, 255, sizeof(dp1));
    memset(dp2, 255, sizeof(dp2));

    for(int i = 0; i < n; ++i)
    {
        if (i)
        {
            memcpy(dp1[i], dp1[i - 1], sizeof(dp1[i]));
            memcpy(dp2[i], dp2[i - 1], sizeof(dp2[i]));
        }
        for(int j = 0; j < m; ++j)
        {
            for(int v = 0; v < k; ++v)
            {
                if (dp1[i][j][v] != -1)
                    ++dp1[i][j][v];
                if (dp2[i][j][v] != -1)
                    ++dp2[i][j][v];
            }
        }
        for(int j = 0; j < m; ++j)
        {
            int c = a[i][j];
            if (dp1[i][j][c] == -1)
                dp1[i][j][c] = 0;
            for(int v = 0; v < k; ++v)
            {
                if (j)
                    if (dp1[i][j - 1][v] != -1)
                        remax(dp1[i][j][v], dp1[i][j - 1][v] + 1);
                remax(dp[c][v], dp1[i][j][v]);
                remax(dp[v][c], dp1[i][j][v]);
            }
        }
        for(int j = m - 1; j >= 0; --j)
        {
            int c = a[i][j];
            if (dp2[i][j][c] == -1)
                dp2[i][j][c] = 0;
            for(int v = 0; v < k; ++v)
            {
                if (j != m - 1)
                    if (dp2[i][j + 1][v] != -1)
                        remax(dp2[i][j][v], dp2[i][j + 1][v] + 1);
                remax(dp[c][v], dp2[i][j][v]);
                remax(dp[v][c], dp2[i][j][v]);
            }
        }
        /*for(int j = 0; j < m; ++j)
        {
            cout << dp1[i][j][0] << " ";
        }
        cout << endl;
        */
    }

    int ans = 0;

    int ss[s];

    for(int i = 0; i < s; ++i)
    {
        ss[i] = nxt() - 1;
        if (i)
        {
            remax(ans, dp[ss[i]][ss[i - 1]]);
        }
    }

    cout << ans << endl;

    return 0;
}