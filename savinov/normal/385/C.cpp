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

const int N = 10000000;

int lp[N + 1];
int dp[N + 1];

int cnt[N + 2];


int main()
{
    lp[1] = 0;
    for(int i = 2; i <= N; ++i)
    {
        if (!lp[i])
        {
            lp[i] = i;
            if ((ll)i * i <= N)
            {
                for(int j = i * i; j <= N; j += i)
                {
                    if (!lp[j])
                    {
                        lp[j] = i;
                        dp[j] = j / i;
                    }
                }
            }
        }
    }

    in(n);

    while(n--)
    {
        in(x);

        while(x > 1)
        {
            int lq = lp[x];
            while(lp[x] == lq)
                x = dp[x];
            cnt[lq]++;
        }
    }
    for(int i = 1; i <= N; ++i)
    {
        cnt[i] += cnt[i - 1];
    }

    in(q);

    while(q--)
    {
        int l = nxt();
        int r = nxt();

        if (l > N)
        {
            cout << "0\n";
            continue;
        }
        r = min(r, N);

        cout << cnt[r] - cnt[l - 1] << "\n";
    }


    return 0;
}