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

const ll INF = 1e10;

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
char used[1001];
int nw[1001];
int t = 0;

void dfs(int v)
{
    nw[v] = t++;
    used[v] = 1;
    fori(it,g[v])
    {
        int to = *it;
        if (!used[to])
            dfs(to);
    }
}

int main()
{
    in(n);in(m);
    if (!(n&1))
    {
        cout << "-1" << endl;
        return 0;
    }

    g.resize(n);
    clr(used);
    int a0[1001],a1[1001],col[100001];
    int can[1001][1001];
    memset(a0,-1,sizeof(a0));
    memset(a1,-1,sizeof(a1));
    memset(can,-1,sizeof(can));
    int fr[100001],to[100001];
    forn(i,m)
    {
        int a = nxt()-1;
        int b = nxt()-1;
        char c = getchar();
        if (c=='S')
            col[i] = 0;
        else
            col[i] = 1;
        g[a].pb(b);
        g[b].pb(a);
        fr[i] = a;
        to[i] = b;
    }
    memset(nw,-1,sizeof(nw));
    dfs(0);

    if (nw[n-1]==-1)
    {
        cout << "-1";
        return 0;
    }
    forn(i,m)
    {
        int a = nw[fr[i]];
        int b = nw[to[i]];
        if (a>b) swap (a,b);
        if (a<b)
        {
            if (col[i])
                a1[b]=i;
            else
                a0[b]=i;
        }
    }
    can[0][0] = 0;
    for(int i=1;i<n;i++)
        forn(j,n)
        {

            if (can[i-1][j]!=-1&&a0[i]!=-1) can[i][j] = a0[i];
            if (j>0&&can[i-1][j-1]!=-1&&a1[i]!=-1) can[i][j] = a1[i];
        }

    if (can[n-1][(n-1)/2]!=-1)
    {
        cout << n-1 << endl;
        int cur = (n-1)/2;
        for(int i=n-1;i>0;i--)
        {
            cout << can[i][cur]+1 << " ";
            cur-=col[can[i][cur]];
        }
    }
    else
    {
        cout << "-1" <<endl;
    }
    return 0;
}