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

const int N = 100000;

int n;

int t[5000];


int get(int r)
{
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
    {
        res += t[r];
    }
    return res;
}

void add(int pos)
{
    for(; pos < n; pos |= pos + 1)
        t[pos]++;
}

int main()
{
    input(n);

    int a[n];

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
                ++ans;
        }
    }

    int inv = ans;

    int cnt = 0;

    for(int i = 0; i < n; ++i)
    {
        clr(t);
        int cur = inv;
        add(a[i]);
        for(int j = i + 1; j < n; ++j)
        {
            int delta = 2 * get(a[j]) - (j - i - 1);
            if (cur + delta < ans)
            {
                ans = cur + delta;
                cnt = 1;
            }
            else
            {
                if (cur + delta == ans)
                {
                    ++cnt;
                }
            }
            add(a[j]);
            cur += (a[j] > a[i]) ? 1 : -1;
        }
    }

    cout << ans - 1 << " " << cnt << endl;

    return 0;
}