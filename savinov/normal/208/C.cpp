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

int a[100];

ll t[2][101];
ll c[2][101];
VVI g;

void bfs(int v,int p)
{
    t[p][v]=0;
    c[p][v]=1;
    queue <int> q;
    q.push(v);
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        fori(it,g[v])
        {
            int to = *it;
            if (t[p][to]==-1)
            {
                t[p][to]=t[p][v]+1;
                c[p][to]+=c[p][v];
                q.push(to);
            }
            else
                if (t[p][to]==t[p][v]+1)
                    c[p][to]+=c[p][v];
        }
    }
}


int main()
{
    in(n);
    in(m);
    memset(t,-1,sizeof(t));
    memset(c,0,sizeof(c));
    g.resize(n);
    forn(i,m)
    {
        in(a);in(b);
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    bfs(0,0);
    bfs(n-1,1);
    ll ans = c[0][n-1];
    for(int i=1;i<n-1;i++)
        if (t[0][i]+t[1][i]==t[1][0]) ans=max(ans,2*c[0][i]*c[1][i]);
    cout << fixed;
    cout << setprecision(20);
    cout << (ld)ans/(ld)c[0][n-1];
    
    return 0;
}