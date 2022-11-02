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

int a[100];

int ans[53][52][52][52];

int go(int k, int last0, int last1,int last2)
{
    
    if (k==1)
        return 1;
        
    if (ans[k][last0][last1][last2]!=-1)return ans[k][last0][last1][last2];
    ans[k][last0][last1][last2] = 1;
    if (k>3)
    {
        if ((a[k-4]/13)==(last2/13)||(a[k-4]%13)==(last2%13))
            if (go(k-1,last2,last0,last1)) return 1;
        if ((last1/13)==(last2/13)||(last1%13)==(last2%13))
            if (go(k-1,a[k-4],last0,last2)) return 1;
    }
    else
    {
        if ((last1/13)==(last2/13)||(last1%13)==(last2%13))
            if (go(k-1,0,last0,last2)) return 1;
    }
    ans[k][last0][last1][last2] = 0;
    return 0;
}

char p1[] = {'2','3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char p2[] = {'S', 'D', 'H', 'C'};

int parse(string t)
{
    int p = 0;
    while (t[0]!=p1[p]) p++;
    int q = 0;
    while (t[1]!=p2[q]) q++;
    return q*13+p;
}

int main()
{
    in(n);
    //memset(ans,-1,sizeof(ans));
    forn(i,n+1)
        forn(j,52)
            forn(k,52)
                forn(l,52)
                    ans[i][j][k][l] = -1;
    forn(i,n)
    {
        string t;
        cin >> t;
        a[i] = parse(t);
    }
    int last2=0,last0=0,last1=0;
    last2=a[n-1];
    if (n>1) last1=a[n-2];
    if (n>2) last0=a[n-3];
    printf(go(n,last0,last1,last2) ? "YES" : "NO");
    
    return 0;
}