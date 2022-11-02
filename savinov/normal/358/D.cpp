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
#define bit(a, pos) ((a >> pos) & 1)
using namespace std;
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int main()
{
    //freopen("g.in", "r", stdin);
    //in(n);
    /*while(1)
    {*/
    int n;
    scanf("%d", &n);
    int a[n + 1], b[n + 1], c[n + 1];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", a + i + 1);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", b + i + 1);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", c + i + 1);
    }
    if (n < 0)
    {
        int d[n];
        char her[n + 1];
        for(int i = 0; i < n; ++i)
        {
            d[i] = i + 1;
        }
        int best = 0;
        int order[n];
        do
        {
            int cur = 0;
            memset(her, 1, sizeof(her));
            for(int i = 0; i < n; ++i)
            {
                int pos = d[i];
                int cnt = 0;
                if (pos > 1 && her[pos - 1]) cnt++;
                if (pos < n && her[pos + 1]) cnt++;
                if (cnt == 0)
                    cur += a[pos];
                if (cnt == 1)
                    cur += b[pos];
                if (cnt == 2)
                    cur += c[pos];
                her[pos] = 0;
            }
            if (cur > best)
            {
                memcpy(order, d, sizeof(d));
                best = cur;
            }
        }while(next_permutation(d, d + n));
        printf("%d\n", best);
        return 0;
    }
    int dp[n + 1][2];
    clr(dp);
    for(int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            dp[i][0] = a[i];
            dp[i][1] = a[i];
            continue;
        }
        if (i == 2)
        {
            dp[i][0] = b[i - 1] + a[i];
            dp[i][1] = a[i - 1] + b[i];
            continue;
        }
        /*if (i == 3)
        {
            continue;
        }*/
        remax(dp[i][0], a[i] + dp[i - 1][0] + b[i - 1] - a[i - 1]);
        remax(dp[i][0], a[i] + dp[i - 1][1] + c[i - 1] - b[i - 1]);
        remax(dp[i][1], b[i] + dp[i-1][0]);
        remax(dp[i][1], b[i] + dp[i-1][1]);
    }
    int ans = max(dp[n][0], dp[n][1]);
    printf("%d\n", ans);
    return 0;
}