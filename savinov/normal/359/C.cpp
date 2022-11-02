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

ll mod = 1000000007;

ll pw(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if (n & 1ll)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1ll;
    }
    return res;
}

int main()
{
    in(n); in(x);
    long long a[n];
    long long s = 0;
    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
        s += a[i];
    }
    priority_queue <ll, vector <ll> , greater <ll> > q;
    for(int i = 0; i < n; ++i)
    {
        a[i] = s - a[i];
        q.push(a[i]);
    }
    ll ans = 0;
    ll mi = 0;
    while(!q.empty())
    {
        ll v = q.top();
        q.pop();
        ll cnt = 1;
        while(!q.empty() && q.top() == v)
        {
            ++cnt;
            q.pop();
        }
        ans += v - mi;
        mi = v;
        ll add = 0;
        while(cnt % x == 0)
        {
            ++add;
            cnt /= x;
        }
        if (add > 0)
        {
            while(cnt--)
                q.push(add + mi);
        }
        else
        {
            break;
        }
    }
    if (ans > s)
        ans = s;
    cout << pw(x, ans) << endl;
    return 0;
}