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
int n, m;
vector<pt> g[N];

inline bool read()
{
    if (scanf ("%d%d", &n, &m) != 2)
        return false;
        
    forn (i, m)
    {
        int x, y, l;
        assert(scanf ("%d%d%d", &x, &y, &l) == 3);
        
        g[x].pb(mp(y, l));
        g[y].pb(mp(x, l));
    }
    
    return true;
}

int q[N], d[N], head, tail;
int mark[N];

inline void bfs (int s)
{
    forn (i, n)
        d[i] = INF;
    head = tail = 0;
    
    d[s] = 0;
    q[tail++] = s;
    
    while (head != tail)
    {
        int v = q[head++];
        
        forn (i, sz(g[v]))
        {
            int to = g[v][i].ft;
            
            if (d[to] <= d[v] + 1)
                continue;
                
            d[to] = d[v] + 1;
            
            q[tail++] = to;
        }
    }
}

int pr[N], d2[N];

inline void bfs2 (int s)
{
    forn (i, n)
        mark[i] = 0;
    head = tail = 0;
    
    mark[s] = 1;
    q[tail++] = s;
    d2[s] = 0;
    
    while (head != tail)
    {
        int v = q[head++];
        
        forn (i, sz(g[v]))
        {
            int to = g[v][i].ft;
            
            if (mark[to])
                continue;

            if (g[v][i].sc > 0)
                continue;   

            mark[to] = 1;
            pr[to] = v;
            d2[to] = d2[v] + 1;
            q[tail++] = to;
        }
    }
}

inline bool cmp (const pair<int, int>& a, const pt& b)
{
    if (a.sc != b.sc)
        return a.sc < b.sc;
        
    return a.ft < b.ft;
}

int cur[2 * N], szc, ncur[2 * N], sznc;
int p[N];
int ans[N], szans;
int used[N];

inline void solve()
{
    bfs(0);
    bfs2(n - 1);
    
    int minVal = INF;
    
    forn (i, n)
        if (mark[i])
            minVal = min(minVal, d[i]); 
    
    forn (i, n) {
        if (d[i] == minVal) {   
            if (mark[i])
            {
                cur[szc++] = i;
                used[i] = 1;
            }
        } else 
            mark[i] = 0;    
    }
        
    if (mark[0])
    {
        printf ("0\n%d\n", d2[0] + 1);
        for (int v = 0; v != n - 1; v = pr[v])
            printf ("%d ", v);
        printf ("%d\n", n - 1);

        return;
    }

    while (true)
    {
        int minVal = INF;
        forn (i, szc)
        {
            int v = cur[i];
            
            forn (j, sz(g[v]))
            {
                int to = g[v][j].ft;
                
                if (used[to])
                    continue;

                if (d[to] == d[v] - 1)  
                    minVal = min(minVal, g[v][j].sc);
            }
        }
        
        assert(minVal != INF);
        ans[szans++] = minVal;
        
        sznc = 0;
        forn (i, szc)
        {
            int v = cur[i];
            
            forn (j, sz(g[v]))
            {
                int to = g[v][j].ft;
                
                if (used[to])
                    continue;
                
                if (g[v][j].sc == minVal && d[to] == d[v] - 1)
                {
                    ncur[sznc++] = to;
                    used[to] = 1;
                }
            }
        }
        
        sort(ncur, ncur + sznc);
        sznc = int(unique(ncur, ncur + sznc) - ncur);
        
        szc = sznc;
        forn (i, szc)
            cur[i] = ncur[i];
            
        if (cur[0] == 0)
            break;
    }
    
    reverse(ans, ans + szans);
    
    szc = 0;
    cur[szc++] = 0;
    int it = 0;

    while (it < szans)
    {
        sznc = 0;
        forn (i, szc)
        {
            int v = cur[i];
            
            forn (j, sz(g[v]))
            {
                int to = g[v][j].ft, len = g[v][j].sc;
                
                if (d[to] != d[v] + 1)
                    continue;
                    
                if (ans[it] != len)
                    continue;
                    
                ncur[sznc++] = to;
                p[to] = v;
            }
        }
        
        sort(ncur, ncur + sznc);
        sznc = unique(ncur, ncur + sznc) - ncur;
        
        szc = sznc;
        forn (i, szc)
            cur[i] = ncur[i];

        it++;
    }
    
    int mid = -1;
    forn (i, szc)
        if (mark[cur[i]])
        if (mid == -1 || (mark[cur[i]] && d2[ cur[i] ] < d2[mid]))  
            mid = cur[i];
            
    assert(mid != -1);
    
    
    vector<int> path;
    for (int v = mid; v != 0; v = p[v])
        path.pb(v);
    path.pb(0);
    
    reverse(all(path));

    if (mid != n - 1)
    {   
        for (int v = pr[mid]; v != n - 1; v = pr[v])
            path.pb(v);
        path.pb(n - 1);
    }
        
    reverse(ans, ans + szans);

    forn (i, szans)
        printf ("%d", ans[i]);
    puts("");
    
    printf ("%d\n", sz(path));
    forn (i, sz(path))
        printf ("%d ", path[i]);
    puts("");   
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