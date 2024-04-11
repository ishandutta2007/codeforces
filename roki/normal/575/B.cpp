#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 100 * 1000 + 13;
int n, k;
vector<pt> g[N];

inline bool read()
{
    if (scanf ("%d", &n) != 1)
        return false;
        
    forn (i, n - 1)
    {
        int x, y, s;
        assert (scanf ("%d%d%d", &x, &y, &s) == 3);
        
        x--, y--;
        
        if (s == 0)
        {
            g[x].pb(mp(y, 2));
            g[y].pb(mp(x, 2));
        }
        else
        {
            g[x].pb(mp(y, 0));
            g[y].pb(mp(x, 1));
        }
    }
    
    return true;
}

const int LOGN = 20;
int tin[N], tout[N], Time = 0, up[LOGN][N];

void dfs (int v, int pr = 0)
{
    tin[v] = Time++;
    
    up[0][v] = pr;
    for (int i = 1; i < LOGN; i++)
        up[i][v] = up[i - 1][ up[i - 1][v] ];
        
    forn (i, sz(g[v]))
    {
        int to = g[v][i].ft;
        
        if (to == pr)
            continue;
            
        dfs(to, v);
    }
    
    tout[v] = Time++;
}

inline bool isAncestor (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

inline int lca (int a, int b)
{
    if (isAncestor(a, b))
        return a;
        
    if (isAncestor(b, a))
        return b;
        
    for (int i = LOGN - 1; i >= 0; i--)
        if (!isAncestor(up[i][a], b))
            a = up[i][a];
            
    return up[0][a];
}

int up2[N], down[N];

const int M = 1000 * 1000 + 13;
int st[M];

const int MOD = 1000 * 1000 * 1000 + 7;
vector<int> cnt[N];

pt dfs2 (int v, int pr = 0)
{
    int upCnt = 0, downCnt = 0;
    
    forn (i, sz(g[v]))
    {
        int to = g[v][i].ft, t = g[v][i].sc;
        
        if (to == pr)
            continue;
            
        pt cur = dfs2(to, v);
        
        if (t == 0)
            cnt[v][i] += cur.ft;
        if (t == 1)
            cnt[v][i] += cur.sc;        
        
        upCnt += cur.ft;
        downCnt += cur.sc;
    }
    
    upCnt += up2[v], downCnt += down[v];
    
    return mp(upCnt, downCnt);
}

inline void solve()
{
    dfs(0);
    
    assert(scanf ("%d", &k) == 1);
    int last = 0;
    forn (i, k)
    {
        int x;
        assert(scanf ("%d", &x) == 1);
        
        x--;
        
        int l = lca(last, x);
        
        if (last != l)
        {
            up2[l]--;
            up2[last]++;    
        }

        if (l != x)
        {
            down[l]--;
            down[x]++;
        }
        
        last = x;
    }
    
    st[0] = 1;
    fore(i, 1, M - 1)
        st[i] = (st[i - 1] * 2) % MOD;
        
    forn (i, n)
    {
        cnt[i].resize(sz(g[i]));

        forn (j, sz(cnt[i]))
            cnt[i][j] = 0;
    }
        
    dfs2(0);
    
    int ans = 0;
    forn (i, n)
        forn (j, sz(g[i]))
            if (cnt[i][j] > 0)
            {
                //cerr << i << ' ' << j << ' ' << cnt[i][j] << endl;
                ans = (ans + st[ cnt[i][j] ] - 1) % MOD;
            }
    
    cout << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));

    assert(read());
    solve();

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}