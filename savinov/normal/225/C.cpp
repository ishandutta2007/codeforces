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

const int INF = 2e6;

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
    in(n);in(m);in(x);in(y);
    int cost0[m + 1],cost1[m + 1];
    int ans0[m + 1],ans1[m + 1];
    For(i,1,m)
    {
        cost0[i] = n;
        cost1[i] = n;
        ans0[i] = INF;
        ans1[i] = INF;
    }

    forn(i,n)
    {
        forn(j,m)
        {
            char c = getchar();
            if (c == '#')
                cost1[j + 1]--;
            else
                cost0[j + 1]--;
        }
        getchar();
    }
    int psum1[m + 1], psum0[m + 1];
    psum1[0] = 0;
    psum0[0] = 0;
    For(i,1,m)
    {
        psum1[i] = psum1[i - 1] + cost1[i];
        psum0[i] = psum0[i - 1] + cost0[i];
    }
    ans0[0] = 0;
    ans1[0] = 0;
    For(i,1,m)
    {
            for(int j = x; j <= y && i - j >= 0;j++)
            {
                ans1[i] = min(ans1[i], ans0[i-j] + psum1[i] - psum1[i - j]);
                ans0[i] = min(ans0[i], ans1[i-j] + psum0[i] - psum0[i - j]);
            }
    }
    cout << min(ans0[m],ans1[m]);

    return 0;
}