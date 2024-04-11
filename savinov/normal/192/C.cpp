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

#define bublic public
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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

#define x first
#define y second

int main()
{
    int a[26][26];
    forn(i,26)
    {
        forn(j,26)
        {
            a[i][j]=0;
        }
    }
    int n;
    scanf("%i",&n);
    getchar();
    forn(i,n)
    {
        char c1=getchar(),c=c1,c2;
        int l=0;
        while (c!='\n')
        {
            l++;
            c2=getchar();
            if (c2=='\n')
            {
                c2=c;
                c='\n';
            } else c=c2;
        }
        for (int i=0;i<26;i++)
        {
            if (a[i][c1-'a']!=0) a[i][c2-'a']=max(a[i][c1-'a']+l,a[i][c2-'a']);
        }
        a[c1-'a'][c2-'a']=max(l,a[c1-'a'][c2-'a']);
    }
    int ans=0;
    forn(i,26)
    {
        ans=max(ans,a[i][i]);
    }
    printf("%i\n",ans);
    return 0;
}