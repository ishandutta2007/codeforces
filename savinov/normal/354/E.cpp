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

int kk[20];
int ii[20];

int s = 0;

ll res[6];

bool ok = false;

void solve(ll a)
{
    if (ok) return;
    if (a == 0)
    {
        clr(res);
        for(int i = s - 1; i >= 0; --i)
        {
            for(int j = 0; j < 6; ++j)
            {
                if (j < kk[i])
                {
                    if (j < ii[i])
                        res[j] = 10 * res[j] + 4;
                    else
                        res[j] = 10 * res[j] + 7;
                }
                else
                {
                    if (res[j])
                        res[j] *= 10;
                }
            }
        }
        s = 0;
        ok = true;
        return;
    }
    int dig = a % 10;
    for(int k = 0; k <= 6; ++k)
    for(int i = 0; i <= k; ++i)
    {
        if ((7 * k - 3 * i) % 10 == dig)
        {
            ll b = a - 7 * k + 3 * i;
            if (b >= 0)
            {
                //cout << b << " " << i << " " << k << " " << endl;
                b /= 10;
                kk[s] = k;
                ii[s++] = i;
                solve(b);
                if (ok) return;
                --s;
            }
        }
    }
}

int main()
{
    /*int sz[N + 1];
    clr(sz);
    for(int i = 1; i <= N; ++i)
    {
        for(int j = i; j <= N; j += i)
            sz[j]++;//divs[j].pb(i);
    }
    int * divs[N + 1];
    int s[N + 1];
    clr(s);
    for(int i = 1; i <= N; ++i)
    {
        divs[i] = new int[sz[i]];
    }
    for(int i = 1; i <= N; ++i)
    {
        for(int j = i; j <= N; j += i)
            divs[j][s[j]++] = i;
    }
    in(n); in(k);
    int a[n];
    int add[N + 2];
    clr(add);
    int cnt[N + 1];
    clr(cnt);
    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
        add[max(0, a[i] - k)]++;
        add[a[i] + 1]--;
    }
    int cur = 0;
    for(int i = 1; i <= N; ++i)
    {
        cur += add[i];
        for(int j = 0; j < sz[i]; ++j)
            cnt[divs[i][j]] += cur;
    }
    int res = 0;
    for(int i = 1; i <= N; ++i)
        if (cnt[i] == n)
            remax(res, i);
    cout << res << endl;
    */
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
    }
    return 0;
}