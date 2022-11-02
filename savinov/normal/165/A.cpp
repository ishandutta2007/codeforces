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
inline int nxt() {int ret; cin >> ret; return ret;}

#define x first
#define y second

int main()
{
    in(n);
    PII a[201];
    forn(i,n)
    {
        a[i].x = nxt();
        a[i].y = nxt();
    }
    VI cnt1(n);
    VI cnt2(n);
    VI cnt3(n);
    VI cnt4(n);
    forn(i,n)
        forn(j,n)
        {
            if (i!=j)
            {
                if (a[i].x==a[j].x&&a[i].y>a[j].y)
                {
                    cnt1[i]++;
                }
                if (a[i].x==a[j].x&&a[i].y<a[j].y)
                {
                    cnt2[i]++;
                }
                if (a[i].y==a[j].y&&a[i].x>a[j].x)
                {
                    cnt3[i]++;
                }
                if (a[i].y==a[j].y&&a[i].x<a[j].x)
                {
                    cnt4[i]++;
                }
            }
        }
    int ans = 0;
    forn(i,n)
        if (cnt1[i]&&cnt2[i]&&cnt3[i]&&cnt4[i]) ans++;
    cout << ans;
    return 0;
}