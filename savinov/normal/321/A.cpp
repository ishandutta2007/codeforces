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

PII get(char c)
{
    if (c == 'U')
    {
        return mp(0, 1);
    }
    if (c == 'D')
    {
        return mp(0, -1);
    }
    if (c == 'L')
    {
        return mp(-1, 0);
    }
    if (c == 'R')
    {
        return mp(1, 0);
    }
    return mp(0, 0);
}

int main()
{
    in(a); in(b);
    string s;
    cin >> s;
    int x[s.length() + 1], y[s.length() + 1];
    x[0] = 0;
    y[0] = 0;
    for(int i = 0; i < (int)s.length(); ++i)
    {
        x[i + 1] = x[i];
        y[i + 1] = y[i];
        PII dd = get(s[i]);
        x[i + 1] += dd.x;
        y[i + 1] += dd.y;
    }
    int xx = x[s.length()], yy = y[s.length()];
    for(int i = 0; i <= (int)s.length(); ++i)
    {
        int c = a - x[i];
        int d = b - y[i];
        if (((xx == 0) && (c == 0)) || (xx && abs(c) % abs(xx) == 0))
        {
            if ((yy == 0 && d == 0) || (yy && abs(d) % abs(yy) == 0))
            {
                if (xx == 0)
                {
                    if (yy == 0)
                    {
                        puts("Yes");
                        return 0;
                    }
                    else
                    {
                        if (d / yy >= 0)
                        {
                            puts("Yes");
                            return 0;
                        }
                    }
                }
                else
                {
                    int c1 = c / xx;
                    if (c1 >= 0)
                    {
                        if (yy == 0)
                        {
                            puts("Yes");
                            return 0;
                        }
                        else
                        {
                            int c2 = d / yy;
                            if (c2 == c1)
                            {
                                puts("Yes");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    puts("No");

    return 0;
}