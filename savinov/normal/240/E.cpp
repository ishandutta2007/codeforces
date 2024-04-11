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

vector <vector <PII> > g;
vector <vector <PII> > g2;
bool used[100000];
bool colored[100000];
int color[100000];

bool cmp(PII a, PII b)
{
    return a.x == b.x;
}

vector <PII> dfs(int v)
{
    used[v] = true;
    vector <PII> res;
    fori(it, g[v])
    {
        int to = it -> x;
        int num = it -> y;
        if (color[num])
            res.pb(*it);
        else if (!used[to])
        {
            vector <PII> to_add = dfs(to);
            fori(i, to_add)
                res.pb(*i);
        }
    }
    sort(all(res));
    res.resize(unique(all(res), cmp) - res.begin());
    return res;
}

VI ans;

void dfs2(int v)
{
    used[v] = true;
    fori(it, g2[v])
    {
        int to = it -> x;
        int num = it -> y;
        if (colored[to] && !used[to])
        {
            ans.pb(num);
            color[num] = 0;
            dfs2(to);
        }
    }   
}

void dfs3(int v)
{
    used[v] = true;
    fori(it, g[v])
    {
        int to = it -> x;
        int num = it -> y;
        if (!color[num] && !used[to])
            dfs3(to);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    in(n); in(m);
    int white_degree[n];
    clr(used);
    clr(white_degree);
    g.resize(n);
    g2.resize(n);
    forn(i, m)
    {
        int a = nxt() - 1;
        int b = nxt() - 1;
        color[i] = nxt();
        if (b)
        {
            g[a].pb(mp(b, i));
            if (!color[i])
                ++white_degree[b];
        }
    }
    
    clr(colored);
    forn(i, n)
    {
        if (!white_degree[i])
        {
            colored[i] = true;
            g2[i] = dfs(i);
        }
    }
    clr(used);
    dfs2(0);
    clr(used);
    dfs3(0);
    forn(i, n)
    {
        if (!used[i])
        {
            puts("-1");
            return 0;
        }
    }
    cout << (int)ans.size() << endl;
    forn(i, ans.size())
        cout << ans[i] + 1 << " ";  
    cout << endl;
    return 0;
}