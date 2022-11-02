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

int main()
{

    in(n);
    int a[100000];
    forn(i,n-1) input (a[i]);
    ll l1[100000],l2[100000],r1[100000],r2[100000];
    l1[0] = 0;
    l2[0] = 0;
    for(int i = 1; i < n; i++)
    {
        l1[i] = (a[i-1]>0)*max(l1[i-1]+1+((a[i-1]-1)/2)*2,l2[i-1]+a[i-1]);
        l2[i] = (a[i-1]>1)*(l2[i-1]+(a[i-1]/2)*2);
        
    }
    r1[n-1] = 0;
    r2[n-1] = 0;
    for(int i = n-2; i>=0; i--)
    {
        r1[i] = (a[i]>0)*max(r1[i+1]+1+((a[i]-1)/2)*2,r2[i+1]+a[i]);
        r2[i] = (a[i]>1)*(r2[i+1]+(a[i]/2)*2);
    }
    ll ans = 0; 
    
    forn(i,n)
        ans = max(ans,max(l1[i]+r2[i],l2[i]+r1[i]));
        
    cout << ans;
}