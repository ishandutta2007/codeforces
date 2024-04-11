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
    in(n);
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
    }
    int N = 1;
    while(N < n)
        N *= 2;

    int g[2 * N];
    clr(g);
    for(int i = 0; i < n; ++i)
    {
        g[i + N] = a[i];
    }

    for(int i = N - 1; i > 0; --i)
    {
        if (g[i + i] || g[i + i + 1])
            g[i] = __gcd(g[i + i], g[i + i + 1]);
        else
            g[i] = 0;
    }

    int best = -1;

    vector <int> ans;

    for(int i = 0; i < n; ++i)
    {
        int l = 0, r = i;
        while(l < r)
        {
            int m = (l + r) / 2;

            int res = 0;

            for(int L = m + N, R = i + N; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
            {
                if (L & 1)
                {
                    res = __gcd(res, g[L]);
                }
                if (!(R & 1))
                {
                    res = __gcd(res, g[R]);
                }
            }
            if (res == a[i])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        int LL = l;

        l = i, r = n - 1;
        while(l < r)
        {
            int m = (l + r + 1) / 2;

            int res = 0;

            for(int L = i + N, R = m + N; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
            {
                if (L & 1)
                {
                    res = __gcd(res, g[L]);
                }
                if (!(R & 1))
                {
                    res = __gcd(res, g[R]);
                }
            }
            if (res == a[i])
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        int RR = l;
        if (RR - LL > best)
        {
            ans.clear();
            best = RR - LL;
            ans.pb(LL);
        }
        else
        {
            if (RR - LL == best)
            {
                ans.pb(LL);
            }
        }
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());

    cout << ans.size() << " " << best << endl;

    for(int i = 0; i < (int)ans.size(); ++i)
    {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}