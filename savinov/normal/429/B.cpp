#include <bits/stdc++.h>
#include <ext/rope>
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

using namespace __gnu_cxx;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

//inline void input(long long &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;}

int main()
{
    in(n); in(m);

    int a[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = nxt();
        }
    }

    int d[4][n][m];

    clr(d);

    d[0][0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) {
                remax(d[0][i][j], d[0][i - 1][j] + a[i][j]);
            }
            if (j > 0) {
                remax(d[0][i][j], d[0][i][j - 1] + a[i][j]);
            }
        }
    }

    d[1][0][m - 1] = a[0][m - 1];

    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i > 0) {
                remax(d[1][i][j], d[1][i - 1][j] + a[i][j]);
            }
            if (j < m - 1) {
                remax(d[1][i][j], d[1][i][j + 1] + a[i][j]);
            }
        }
    }

    d[2][n - 1][0] = a[n - 1][0];

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (i < n - 1) {
                remax(d[2][i][j], d[2][i + 1][j] + a[i][j]);
            }
            if (j > 0) {
                remax(d[2][i][j], d[2][i][j - 1] + a[i][j]);
            }
        }
    }

    d[3][n - 1][m - 1] = a[n - 1][m - 1];

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i < n - 1) {
                remax(d[3][i][j], d[3][i + 1][j] + a[i][j]);
            }
            if (j < m - 1) {
                remax(d[3][i][j], d[3][i][j + 1] + a[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            ans = max(ans, d[0][i][j - 1] + d[2][i + 1][j] + d[1][i - 1][j] + d[3][i][j + 1]);
            ans = max(ans, d[0][i - 1][j] + d[2][i][j - 1] + d[1][i][j + 1] + d[3][i + 1][j]);
        }
    }

    cout << ans << endl;


    return 0;
}