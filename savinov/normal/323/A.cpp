#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>

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
typedef long double ld;
template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-8;
char TEMPORARY_CHAR;
typedef long long ll;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;
const int INF = 2e9;
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){}
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
inline void out(int a)
{
    if (!a) putchar('0');
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    char s[10];
    int i;
    for(i = 0; a; ++i)
    {
        s[i] = '0' + a % 10;
        a /= 10;
    }
    ford(j, i) putchar(s[j]);
}
inline int nxt()
{
    in(ret);
    return ret;
}


int main()
{
    in(n);
    if (n & 1)
    {
        puts("-1");
        return 0;
    }
    forn(i, n)
    {
        if (i & 1)
        {
        forn(j, n)
        {
            forn(k, n / 2)
            {
                if ((j & 3) < 2)
                {
                    if (k & 1)
                    {
                        putchar('w');
                        putchar('w');
                    }
                    else
                    {
                        putchar('b');
                        putchar('b');
                    }
                }
                else
                {
                    if (k & 1)
                    {
                        putchar('b');
                        putchar('b');
                    }
                    else
                    {
                        putchar('w');
                        putchar('w');
                    }
                }
            }
            putchar('\n');
        }
        }
        else
        {
            forn(j, n)
        {
            forn(k, n / 2)
            {
                if ((j & 3) < 2)
                {
                    if (k & 1)
                    {
                        putchar('b');
                        putchar('b');
                    }
                    else
                    {
                        putchar('w');
                        putchar('w');
                    }
                }
                else
                {
                    if (k & 1)
                    {
                        putchar('w');
                        putchar('w');
                    }
                    else
                    {
                        putchar('b');
                        putchar('b');
                    }
                }
            }
            putchar('\n');
        }
        }
        putchar('\n');
    }
    return 0;
}