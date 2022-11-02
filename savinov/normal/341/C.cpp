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

int mod = 1000000007;

int f[2001];
int ans[2001];
int delta = 0;

int solve(int k)
{
    if (ans[k] != -1)
        return ans[k];
    if (k == 0)
        return ans[k] = f[k + delta];
    if (k == 1)
        return ans[k] = (ll)(k + delta - 1) * f[k + delta - 1] % mod;
    return ans[k] = ((ll)(k + delta - 1) * solve(k - 1) + (ll)(k - 1) * solve(k - 2)) % mod;
}

int main()
{
    memset(ans, 255, sizeof(ans));
    in(n);
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
        f[i] = (ll)i * f[i - 1] % mod;
    vector <int> a, b;
    for(int i = 0; i < n; ++i)
    {
        int v = nxt();
        if (v == -1)
            a.pb(i);
        else
            b.pb(v - 1);
    }
    sort(all(a));
    sort(all(b));
    vector <int> c(a.size());
    int p = set_intersection(all(a), all(b), c.begin()) - c.begin();
    int q = a.size();
    delta = p;
    p = q - p;
    cout << solve(p) << endl;
    return 0;
}