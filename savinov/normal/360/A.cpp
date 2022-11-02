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

int a[5005];

int get(int l, int r)
{
    int ret = -1e9 - 20;
    for (int i = l; i <= r; ++i)
    {
        ret = max(ret, a[i]);
    }
    return ret;
}

void update(int l, int r, int val)
{
    for (int i = l; i <= r; ++i)
        a[i] += val;
}

int main()
{
    clr(a);
    int n, k;
    cin >> n >> k;

    int type[k];
    int l[k];
    int r[k];
    int val[k];

    for(int i = 0; i < n; ++i)
    {
        a[i] = 100000000;
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> type[i] >> l[i] >> r[i] >> val[i];
        l[i]--;
        r[i]--;
    }
    for (int i = k - 1; i >= 0; --i)
    {
        if (type[i] == 1)
        {
            update(l[i], r[i], -val[i]);
        }
        if (type[i] == 2)
        {
            int cur = get(l[i], r[i]);
            if (cur < val[i])
            {
                puts("NO");
                return 0;
            }
            for(int j = l[i]; j <= r[i]; ++j)
            {
                remin(a[j], val[i]);
            }
        }
    }

    int ans[n];
    for (int i = 0; i < n; ++i)
        ans[i] = a[i];

    for (int i = 0; i < k; ++i)
    {
        if (type[i] == 1)
        {
            update(l[i], r[i], val[i]);
        }
        if (type[i] == 2)
        {
            int cur = get(l[i], r[i]);
            if (cur != val[i])
            {
                puts("NO");
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    for (int i = 0; i < n; ++i)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}