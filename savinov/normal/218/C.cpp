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

bool cmp(PII a, PII b)
{
    return a.x<b.x;
}

VVI g;
vector <bool> used;
void dfs(int v)
{
    used[v] = true;
    fori(it,g[v])
    {
        int to = *it;
        if (!used[to])
            dfs(to);
    }
}

int main()
{
    in(n);
    VI mp[100];
    int p[100];
    int size = 0;
    forn(i,n)
    {
        in(x);
        int i;
        for(i=0;i<size;i++)
        {
            if (p[i]==x)
                break;
        }
        p[i] = x;
        size = max(size,i+1);
        mp[i].pb(nxt());
    }
    g.resize(size);
    used.resize(size);
    VI tmp(200);
    forn(i,size)
        sort(all(mp[i]));
    forn(i,size)
        forn(j,size)
        {
            //tmp.cle();
            VI::iterator it = set_intersection(all(mp[i]),all(mp[j]),tmp.begin());
            if (it!=tmp.begin())
                g[i].pb(j);
        }
    int k = 0;
    forn(i,size)
    {
        if (!used[i])
        {
            dfs(i);
            ++k;
        }
    }
    cout << k - 1;
    return 0;
}