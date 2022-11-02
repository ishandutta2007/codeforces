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


struct pt
{
    ld x, y, z;
    int num;
};

int x1, ypp, z1;

inline bool yes(ld x, ld y, ld z)
{
    return (x >= 0 && x <= x1 && y >=0 && y <= ypp && z >= 0 && z <= z1);
}
int main()
{
    in(x);in(y);in(z);
    input(x1);input(ypp);input(z1);
    int a[6];
    forn(i, 6)
        a[i] = nxt();
    if (y == 0)
        a[0] = 0;
    if (y == ypp)
        a[1] = 0;
    if (z == 0)
        a[2] = 0;
    if (z == z1)
        a[3] = 0;
    if (x == 0)
        a[4] = 0;
    if (x == x1)
        a[5] = 0;
    pt p[6];
    forn(i, 6)
        p[i].num = a[i];

    p[0].x = x1 / 2.0L;
    p[0].y = -EPS;
    p[0].z = z1 / 2.0L;
    p[1].x = x1 / 2.0L;
    p[1].y = ypp + EPS;
    p[1].z = z1 / 2.0L;
    p[2].x = x1 / 2.0L;
    p[2].y = ypp / 2.0L;
    p[2].z = -EPS;
    p[3].x = x1 / 2.0L;
    p[3].y = ypp / 2.0L;
    p[3].z = z1 + EPS;
    p[4].x = -EPS;
    p[4].y = ypp / 2.0L;
    p[4].z = z1 / 2.0L;
    p[5].x = x1 + EPS;
    p[5].y = ypp / 2.0L;
    p[5].z = z1 / 2.0L;
    int ans = 0;
    forn(i,6)
    {
        ld step_x = (p[i].x - x) / 10000000;
        ld step_y = (p[i].y - y) / 10000000;
        ld step_z = (p[i].z - z) / 10000000;
        ans += p[i].num;
        forn(j, 10000000)
        {
            ld cur_z = z + step_z * j;
            ld cur_x = x + step_x * j;
            ld cur_y = y + step_y * j;
            if (yes(cur_x, cur_y, cur_z))
            {
                ans -= p[i].num;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}