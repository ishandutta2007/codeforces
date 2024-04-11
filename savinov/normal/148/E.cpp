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
    int t[101];
    int tmp[10002];
    int ma[101][101];
    int cnt[101];
    in(n);
    in(m);
    forn(i,n)
    {
        in(k);
        cnt[i] = k;
        t[0] = 0;
        forn(j,k)
            t[j+1] = t[j]+nxt();
        forn(j,k+1)
        {
            ma[i][j] = 0;
            forn(p,j+1)
                ma[i][j]=max(ma[i][j],t[p]+t[k]-t[k-j+p]);
        }
    }
    int q[10002];
    memset(q,-1,sizeof(q));
    q[0] = 0;
    forn(i,n)
    {
        forn(j,m+1)
        {
            tmp[j] = q[j];
            for(int k = 0;k<=min(cnt[i],j);k++)
                if (q[j-k]!=-1) tmp[j] = max(tmp[j],q[j-k]+ma[i][k]);
        }
        forn(j,m+1)
            q[j] = tmp[j];   
   }   
    cout << q[m];
    return 0;
}