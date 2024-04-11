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
   in(m);
   PII a[100001];
   int gol[100001];
   int op = 0;
   forn(i,n)
   {
       char c = getchar();
       in(g);
       if (c=='-')
       {
           op++;
           a[g-1].y++;
           gol[i] = g;
       }
       else
       {
           a[g-1].x++;
           gol[i] = -g;
       }
   }
   int pr[100001];
   clr(pr);
   int num = 0;
   forn(i,n)
   {
       int col = op - a[i].y + a[i].x;
       if (col==m)
       {
           pr[i] = true;
           num++;
       }
   }
   forn(i,n)
   {

       if (gol[i]>0&&!pr[gol[i]-1])
       {
           cout << "Truth\n";
           continue;
       }
       if (gol[i]>0&&num==1&&pr[abs(gol[i])-1])
       {
           cout << "Lie\n";
           continue;
       }
       if (gol[i]<0&&!pr[-gol[i]-1])
       {
           cout << "Lie\n";
           continue;
       }
       if (gol[i]<0&&num==1&&pr[-gol[i]-1])
       {
           cout << "Truth\n";
           continue;
       }

       cout << "Not defined\n";
   }
   return 0;
}