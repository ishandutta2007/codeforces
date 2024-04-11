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
    in(n);in(m);
    char c[100][10000];
    forn(i,n)
    {
        forn(j,m)
            c[i][j] = getchar();
        getchar();
    }
    int ans[10000];
    int tmp[10000];
    clr(ans);
    forn(i,n)
    {
        forn(j,m)
            tmp[j] = 10000000;
        int last = -1;
        forn(j,(2*m))
        {
            int cur = j % m;
            if (c[i][cur] == '1')
            {
                last = j;
            }
            if (last >= 0)
                tmp[cur] = min(tmp[cur], j - last);
        }
        if (last == -1)
        {
            cout << "-1\n";
            return 0;
        }
        last = -1;
        ford(j,(2 * m))
        {
            int cur = j % m;
            if (c[i][cur] == '1')
                last = j;
            if (last >= 0)
                tmp[cur] = min(tmp[cur], last - j);
        }
        forn(j,m)
            ans[j] += tmp[j];
    }
    int answer = 10000000;
    forn(i,m)
        answer = min(answer, ans[i]);
    cout << answer << endl;

    return 0;
}