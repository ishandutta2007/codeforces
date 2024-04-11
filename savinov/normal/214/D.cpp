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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
typedef long double ld;

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

const int INF = 0x3f3f3f3f;

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

#define x first
#define y second

ll dp[110][10];
ll c[110][110];
ll mod = 1000000007;

int main()
{
    clr(c);
    c[0][0] = 1;
    for(int i = 1;i<=109;i++)
        forn(j,101)
            forn(k,j+1)
                c[i][j] = (c[i][j]+c[i-1][j-k])%mod;
    //cout << c[3][5];
    
    in(n);
    int a[10];
    forn(i,10) input(a[i]);
    ll s = 0;
    ll ans = 0;
    forn (i,n+1)
    {
        dp[i][9] = 0;
        if (i>=a[9]) dp[i][9] = 1;
        //cout << dp[i][9] << endl;
        for(int j = 8;j>0;j--)
        {
            dp[i][j]  =  0;
            for(int k = a[j];k<=i;k++)
                dp[i][j]=(dp[i][j]+((dp[i-k][j+1]*c[i-k+1][k])%mod))%mod;
        }
        dp[i][0]  =  0;
        for(int k = a[0];k<=i;k++)
            dp[i][0]=(dp[i][0]+((dp[i-k][1]*c[i-k][k])%mod))%mod;
        //cout << dp[i][0] << endl;
        s+=dp[i][0];
        if (i) ans=(ans+dp[i][0])%mod;
    }
    cout << ans%mod;

    return 0;
}