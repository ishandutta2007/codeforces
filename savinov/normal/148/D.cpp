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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second


int main()
{
    in(w);
    in(b);
    ld dp[1001][1001];
    forn(i,w+1)
        dp[i][0] = 1.0L;
    forn(i,b+1)
        dp[0][i] = 0L;
    for(int i = 1;i<=w;i++)
        for(int j=1;j<=b;j++)
        {
            dp[i][j] = (ld)i/((ld)i+(ld)j);
            if (j==2&&i!=1)
                dp[i][j]+=(ld)j/((ld)i+(ld)j)*((ld)(j-1))/(ld)(i+j-1);
            if (j>2)
                dp[i][j]+=(ld)j/((ld)i+(ld)j)*((ld)(j-1))/(ld)(i+j-1)/(ld)(i+j-2)*((ld)i*dp[i-1][j-2]+(ld)(j-2)*dp[i][j-3]);
        }
    cout << fixed;
    cout << setprecision(18);
    cout << dp[w][b];

    return 0;
}