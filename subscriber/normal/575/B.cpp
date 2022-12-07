/* -- ITMO UNIVERSITY 1 ---*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <queue>

#define fs first
#define sc second
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

static inline unsigned long long rdtsc() { unsigned long long d; __asm__ __volatile__ ("rdtsc" : "=A" (d) ); return d; }

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1.01e9;
const dbl eps = 1e-9;
const int M = (int)1e9 + 7;
const int N = (int)3.22e5;

/* --- main part --- */

#define TASK "1"

const int maxn = (int)2e6 + 10;
const int maxe = 2 * maxn;
const int mod = (int)1e9 + 7;

int p2[maxn];

int head[maxn], next[maxe], to[maxe], ec = 1, col[maxe];

inline void add(int x, int y, int c)
{
    ec += 1;
    to[ec] = y;
    next[ec] = head[x];
    head[x] = ec;
    col[ec] = c;
}

int in[maxn], out[maxn];
int T = 0;

const int L = 20;
int pr[maxn/10][L];

int up[maxn], down[maxn];

void dfs1(int x, int p)
{
    in[x] = T++;
    pr[x][0] = p;
    for (int i = 1; i < L; ++i) pr[x][i] = pr[pr[x][i - 1]][i - 1];
    for (int e = head[x]; e; e = next[e])
    {
        int y = to[e];
        if (y == p) continue;
        dfs1(y, x);
    }
    out[x] = T++;
}


inline int lca(int x, int y)
{
    if (in[x] <= in[y] && out[y] <= out[x]) return x;
    for (int i = L - 1; i >= 0; --i)
    {
        int xx = pr[x][i];
        if (!(in[xx] <= in[y] && out[y] <= out[xx])) x = xx;
    }
    return pr[x][0];
}


void ADD(int x, int y)
{
    int z = lca(x, y);
    //eprintf("x = %d, y = %d, z = %d\n", x, y, z);
    up[x] += 1;
    up[z] -= 1;
    down[z] -= 1;
    down[y] += 1;
}

int res = 0;

void calc(int x, int ee)
{
    for (int e = head[x]; e; e = next[e]) if ((e ^ 1) != ee)
    {
        int y = to[e];
        calc(y, e);
        up[x] += up[y];
        down[x] += down[y];
    }
    //eprintf("x = %d, up = %d, down = %d\n", x, up[x], down[x]);   
    //assert(up[x] >= 0 && down[x] >= 0);
    if (ee != 0)
    {
        if (col[ee] == 0)
        {
            res = (res + p2[down[x]]) % mod;
        }
        if (col[ee ^ 1] == 0)
        {
            res = (res + p2[up[x]]) % mod;
        }
    }
}
        


int a[maxn * 10];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int n;
    scanf("%d", &n);
    forn(i, n - 1)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        --x, --y;
        if (c == 0)
        {
            add(x, y, 1);
            add(y, x, 1);
        }
        else
        {
            add(x, y, 1);
            add(y, x, 0);
        }
    }
    dfs1(0, 0);
    int k;
    scanf("%d", &k);
    forn(i, k) scanf("%d", &a[i]);
    forn(i, k) a[i] -= 1;
    int cur = 0;
    forn(i, k)
    {
        ADD(cur, a[i]);
        cur = a[i];
    }
    p2[0] = 0;
    for (int i = 1; i < maxn; ++i) p2[i] = (p2[i - 1] * 2 + 1) % mod;
    //forn(i, n) eprintf("%d %d %d\n", i, up[i], down[i]);
    //eprintf("calc\n");
    calc(0, 0);
    printf("%d\n", res);   
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}