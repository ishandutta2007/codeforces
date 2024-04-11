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

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    in(n);
    int a[10];
    forn(i,10) a[i] = 0;
    int s = 0;
    int cnt = 0;
    forn (i,n)
    {
        in(t);
        a[t]++;
        s+=t;
        if (t==0) cnt++;
    }

    if (cnt==0)
    {
        cout << "-1" << endl;
        return 0;
    }
    if (s==0)
    {
        cout << "0" << endl;
        return 0;
    }

    if (s%3==0)
    {
        ford(i,10)
        {
            forn(j,a[i])
            {
                cout << (char)(i+'0');
            }
        }
        return 0;
    }
    forn(i,10)
    {
        if ((i%3)==(s%3)&&(a[i]>0))
        {
            a[i]--;
            s-=i;
            break;
        }
    }
    if (s%3>0)
    {
        int k = s%3;
        k = 3 - k;
        forn(i,10)
        {
            while ((s%3)>0&&(i%3)==k&&(a[i]>0))
            {
                a[i]--;
                s-=i;
            }
    }

    }
    if (s==0)
    {
        cout << "0" << endl;
        return 0;
    }
    ford(i,10)
    {
        forn(j,a[i])
        {
            cout << (char)(i+'0');
        }
    }

    return 0;
}