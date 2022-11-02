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

const int INF = 1e9;

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
inline int nxt() {in(ret); return ret;}

#define x first
#define y second

VVI g;
VI used;
VI p;
int ans = 0;
int r = 0;

void dfs(int v,int l)
{
    p[v] = l & 1;
    used[v] = true;
    fori(it,g[v])
    {
        int to = *it;
        if (!used[to])
            dfs(to,l+1);
        else
            ans+=(p[to]==p[v]);
    }
}

int main()
{
    in(n);in(m);
    g.resize(n);
    p.resize(n);

    used.resize(n);
    forn(i,m)
    {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn(i,n)
    {
        if (!used[i])
            dfs(i,0);
    }
    ans/=2;
    if ((n-ans)%2==1)
        ans++;
    cout << ans << endl;
    return 0;
}