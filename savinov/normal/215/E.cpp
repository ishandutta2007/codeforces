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

const ll INF = 1e10;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while ((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0')
    {}

    while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0')
    {
        a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
        TEMPORARY_CHAR = getchar();
    }
}
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

ll ans[61];
ll g[32];
VI divs[63];
void prec()
{
    for(int i=1;i<61;i++)
        for(int j=1;j<i;j++)
            if (i%j==0)
                divs[i].pb(j);
}
inline int lg(ll n)
{
    int l = 0;
    while (n)
    {
        l++;
        n>>=1;
    }
    return l;
}

inline void upd(int i)
{
    fori(j,divs[i])
        g[i]-=g[*j];
}

ll f(ll n)
{
    if (n<=1) return 0;
    ll ans = 0;
    int l = lg(n);
    ans+=f((1ll<<(l-1)) - 1);
    clr(g);
    fori(it,divs[l])
    {
        int i = *it;
        ll t = n >> (l-i);
        ll p = t;
        forn(j,l/i-1)
            p = (p << i) + t;
        if (p<=n) g[i]++;
        g[i]+= t & ((1ll<<(i-1))-1);
        upd(i);
        ans+=g[i];
    }
    return ans;
}

int main()
{
    prec();
    ll l,r;
    cin >> l >> r;
    cout << f(r)-f(l-1);
    return 0;
}