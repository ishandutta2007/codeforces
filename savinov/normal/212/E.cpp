
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

VI g[5001];
bool used[5001];
bool ans[5001];
int n;

int go(int v)
{
    used[v] = true;
    int s = 0;
    VI p;
    vector<bool> can[2];

    fori(it,g[v])
    {
        int to = *it;
        if (!used[to])
        {
            p.pb(go(to));
            s+=p.back();
        }
    }
    p.pb(n-s-1);
    can[0].resize(n);
    can[0][0]=true;
    int cur = 0;
    fori(it,p)
    {
        can[cur^1] = can[cur];
        int c = *it;
        forn(i,n-c)
            if (can[cur][i])
            {
                can[cur^1][i+c] = true;
                ans[i+c] = true;
            }
        cur^=1;
    }
    return s+1;
}

int main()
{
    input(n);
    forn(i,n-1)
    {
        in(a);
        in(b);
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    clr(used);
    clr(ans);
    go(0);
    int k = 0;
    for(int i = 1; i < n-1; i++)
    {
        k+=ans[i];
    }
    cout << k << endl;
    for(int i = 1;i < n-1; i++)
    {
        if (ans[i]) cout << i << " " << n-1-i << endl;
    }
    return 0;
}