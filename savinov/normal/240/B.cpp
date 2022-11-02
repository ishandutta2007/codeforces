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

const ll INF = 1e17;

const int N = 1 << 16;

inline void input(int &a)
{
    a = 0;
    while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-'))
    {}
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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    in(n);
    in(a);in(b);
    int h[n];
    int com_s = 0;
    forn(i, n)
    {
        h[i] = nxt();
        com_s += h[i];
    }
    int can[2][n][com_s + 1];
    forn(i, n)
        forn(j, com_s + 1)
        {
            can[0][i][j] = -1;
            can[1][i][j] = -1;
        }
    can[0][0][h[0]] = 0;
    can[1][0][0] = 0;
    forn(i, n)
        if (i)
        {
            For(j, 0, com_s - h[i])
            {
                if (can[0][i - 1][j] != -1)
                {
                    int s = j;
                    int unlike = can[0][i - 1][j];
                    can[0][i][s + h[i]] = unlike;
                    can[1][i][s] = unlike + min(h[i], h[i - 1]);
                }
                if (can[1][i - 1][j] != -1)
                {
                    int s = j + h[i];
                    int unlike = can[1][i - 1][j] + min(h[i], h[i - 1]);
                    if (can[0][i][s] != -1)
                        unlike = min(unlike, can[0][i][s]);
                    can[0][i][s] = unlike;

                    s = j;
                    unlike = can[1][i - 1][j];
                    if (can[1][i][s] != -1)
                        unlike = min(unlike, can[1][i][s]);
                    can[1][i][s] = unlike;
                }
            }

        }
    int mi = 10000000;
    forn(j, com_s + 1)
    {
        int s = j;
        int unlike = can[0][n - 1][j];
        if (unlike != - 1 && s <= a && ((com_s - s) <= b) && unlike < mi)
            mi = unlike;
    }
    forn(j, com_s + 1)
    {
        int s = j;
        int unlike = can[1][n - 1][j];
        if (unlike != - 1 && s <= a && ((com_s - s) <= b) && unlike < mi)
            mi = unlike;
    }
    if (mi != 10000000)
        cout << mi << endl;
    else
        cout << "-1" << endl;
    return 0;
}