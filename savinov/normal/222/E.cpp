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


int m;
ll mod = 1000000007;

struct matr
{
    ll r[52][52];

    friend matr operator*(const matr &a, const matr &b)
    {
        matr ret;
        forn(i,m)
        {
            forn(j,m)
            {
                ret.r[i][j] = 0;
                forn(k,m)
                    ret.r[i][j] = (ret.r[i][j] + a.r[i][k] * b.r[k][j]) % mod;
            }
        }
        return ret;
    }
};
matr E()
{
        matr ret;
        forn(i,m)
            forn(j,m)
                if (i == j)
                    ret.r[i][j] = 1;
                else
                    ret.r[i][j] = 0;
        return ret;
    }
inline int num(char c)
{
    if (c >= 'A' && c <='Z')
        return c - 'A' + 26;
    else
        return c - 'a';
}

matr pw(matr a, ll n)
{
    if (n == 0)
        return E();
    matr ans = pw (a, n >> 1ll);
    ans = ans * ans;
    if (n & 1ll)
        ans = ans * a;
    return ans;
}


int main()
{
    ll n;
    cin >> n;
    m = nxt();
    in(k);
    matr r;
    forn(i,m)
        forn(j,m)
            r.r[i][j] = 1;
    forn(i,k)
    {
        string t;
        cin >> t;
        r.r[num(t[1])][num(t[0])] = 0;
    }
    r = pw(r, n - 1ll);
    ll ans = 0;
    forn(i,m)
        forn(j,m)
            ans += r.r[i][j];
    ans %= mod;
    cout << ans << endl;
    return 0;
}