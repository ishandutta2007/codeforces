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

const int INF = 1e7;

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

int steps, rep;
int gcd (int a, int b)
{
    if (b==0)
        return a;
    steps+=a/b;
    rep += a/b - 1;
    return gcd(b, a%b);
}
int main()
{
    in(n);in(r);
    if (n==1 && r==1)
    {
        cout << "0" << endl << "T";
        return 0;
    }
    int mi = INF;
    int m = 0;
    for(int i=1;i<r;i++)
    {
        steps = 0;
        rep = 0;
        int g = gcd(r,i);
        //cout << steps << endl;
        //cout << g << " " << rep << endl;
        if (steps == n && rep <  mi && g == 1)
        {
            m = i;
            mi = rep;
        }
    }
    if (m)
    {
        printf("%i\n",mi - 1);
        vector <int> ans;
        int a = r;
        int b = m;
        int cur = 0;
        while (b)
        {
            //cout << a << " " << b  << " " << a/b << endl;
            for(int i = 1; i <(a/b); i++)
                ans.pb(cur);

            if (b>1)
                ans.pb(cur);

            cur ^= 1;
            int t = a % b;
            a = b;
            b = t;
            //if (b) ans.pb(cur);
        }
        ans.pb(cur);
        reverse(all(ans));
        fori(it,ans)
        {
            if (*it == *ans.begin())
                putchar('T');
            else
                putchar('B');
        }
        return 0;
    }
    puts("IMPOSSIBLE");
    return 0;
}