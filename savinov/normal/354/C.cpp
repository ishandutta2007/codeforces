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
    const int N = 1000000;
    in(n); in(k);
    int a[n];
    int add[N + 2];
    clr(add);
    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
        add[max(1, a[i] - k)]++;
        add[a[i] + 1]--;
    }
    int cur = 0;
    for(int i = 1; i <= N; ++i)
    {
        cur += add[i];
        add[i] = cur;
    }
    int res = *min_element(a, a + n);
    for(int i = res; i >= 1; --i)
    {
        int v = 0;
        for(int j = i; j <= N; j += i)
            v += add[j];
        if (v >= n)
        {
            cout << i << endl;
            return 0;
        }
    }
    /*
    in(n);
    while(n--)
    {
        ll z;
        cin >> z;
        ok = false;
        s = 0;
        solve(z);
        if (ok)
        {
            for(int i = 0; i < 6; ++i)
            {
                if (i) cout << " ";
                cout << res[i];
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }*/
    return 0;
}