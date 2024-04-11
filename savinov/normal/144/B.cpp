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
#define in(x) int (x); cin >> x;
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

const int INF = 1e9;

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

inline bool isin(int x,int y,int xx, int yy, int r)
{
    return (xx-x)*(xx-x)+(yy-y)*(yy-y)<=r*r;
}

int main()
{
    in(xa);
    in(ya);
    in(xb);
    in(yb);
    in(n);
    int xx[1001],yy[1001],rr[1001];
    forn(i,n)
    {
        xx[i] = nxt();
        yy[i] = nxt();
        rr[i] = nxt();
    }
    if (xa>xb) swap(xa,xb);
    if (ya>yb) swap(ya,yb);
    int ans = 0;
    for(int x = xa; x<xb; x++)
    {
        bool flag = true;
        forn(i,n)
            flag&=!isin(x,ya,xx[i],yy[i],rr[i]);
        ans+=flag;
    }
    for(int y = ya; y<yb; y++)
    {
        bool flag = true;
        forn(i,n)
            flag&=!isin(xb,y,xx[i],yy[i],rr[i]);
        ans+=flag;
    }
    for(int x = xb; x>xa; x--)
    {
        bool flag = true;
        forn(i,n)
            flag&=!isin(x,yb,xx[i],yy[i],rr[i]);
        ans+=flag;
    }
    for(int y = yb; y>ya; y--)
    {
        bool flag = true;
        forn(i,n)
            flag&=!isin(xa,y,xx[i],yy[i],rr[i]);
        ans+=flag;
    }
    cout << ans;

    return 0;
}