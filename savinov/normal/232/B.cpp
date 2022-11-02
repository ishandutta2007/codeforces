#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define out(x) cout << (x);


typedef long double ld;
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }



// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;
char TEMPORARY_CHAR;
// Types
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const ll INF = 1e17;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-'))
    {}
    char neg = 0;
    if (TEMPORARY_CHAR == '-')
    {
        neg = 1;
        TEMPORARY_CHAR = getchar();
    }

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }

    if (neg)
        a = -a;
}
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

ll mod = 1000000007;

ll pw(int a, ll n)
{
    if (n == 0)
        return 1;
    ll ret = pw(a, n >> 1ll);
    ret *= ret;
    ret %= mod;
    if (n & 1ll)
        ret *= a;
    ret %= mod;
    return ret;
}
ll kol[101];

int main()
{
    ll b[101][101];
    clr(b);
    forn(i,101)
        b[i][0] = 1;
    For(i, 1, 100)
        For(j, 1, i)
        {
            b[i][j] = b[i-1][j] + b[i-1][j-1];
            if (b[i][j] >= mod)
                b[i][j] -= mod;
        }
    in(n);
    ll m;
    cin >> m;
    in(k);
    ll dp[10001];
    clr(dp);
    dp[0] = 1;
    forn(i, n)
        kol[i] = (m / n) + ((m % n) > i);
    forn(i, n)
    {
            ll tmp[10001];
            ll c[10001];
            clr(tmp);
            forn(j, n + 1)
                c[j] = pw(b[n][j], kol[i]);
            forn(j, k + 1)
            {
                forn(p, n + 1)
                    if (p <= j)
                        tmp[j] += (c[p] * dp[j - p]) % mod;
                tmp[j] %= mod;
            }
            forn(j, k + 1)
                dp[j] = tmp[j];
    }
    cout << dp[k];
    return 0;
}