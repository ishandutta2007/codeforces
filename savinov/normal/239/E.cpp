#include <algorithm>
#include <cmath>
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
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-8;
char TEMPORARY_CHAR;
typedef long long ll;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef vector < vector < int > > VVI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;
const ll INF = 1e17;
const int N = 1 << 17;
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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)

#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

struct edge
{
    int to;
    int prev;
    int type;
} edges[6000];
int dp[3000];
int last[6000];
int cnt = 0;

int dfs(int v, int p)
{
    int mi1 = dp[v], mi2 = 1e9;
    int cur = last[v];
    while(cur)
    {
        if (edges[cur].to != p)
        {
            dp[edges[cur].to] = dp[v] - 2 * edges[cur].type + 1 ;
            cnt += edges[cur].type;
            int rr = dfs(edges[cur].to, v);
            if (rr < mi1)
            {
                mi2 = mi1;
                mi1 = rr;
            }
            else
                if (rr < mi2)
                    mi2 = rr;
        }
        cur = edges[cur].prev;
    }
    int ret = mi1;
    if (p == -1)
        ret += mi2;
    return ret;
}

int main()
{
    in(n);
    if (n == 1)
    {
        puts("0");
        return 0;
    }
    clr(last);
    clr(dp);
    int m = 1;
    forn(i, n - 1)
    {
        in(a);in(b);
        edges[m].to = b - 1;
        edges[m].prev = last[a - 1];
        edges[m].type = 0;
        last[a - 1] = m++;
        edges[m].to = a - 1;
        edges[m].prev = last[b - 1];
        edges[m].type = 1;
        last[b - 1] = m++;
    }
    dfs(0, - 1);
    int val[n];
    int ans = 1e9;
    forn(i, n)
    {
        val[i] = cnt + dp[i];
        ans = min(ans, val[i]);
    }
    forn(i, n)
    {
        dp[i] = 0;
        ans = min(val[i] + dfs(i, -1), ans);
    }
    cout << ans << endl;
    return 0;
}