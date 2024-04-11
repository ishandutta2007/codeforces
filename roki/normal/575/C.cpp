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

const int K = 20 + 3;
int n;
int a[K][K], b[K][K];

inline void gen ()
{
    n = 20;
    forn (i, n)
        forn (j, n)
        {
            a[i][j] = rand();
            b[i][j] = rand();
        }
}

inline bool read()
{
    //gen();
    //return true;
    
    if (scanf ("%d", &n) != 1)
        return false;
        
    forn (i, n)
        forn (j, n)
            assert(scanf ("%d", &a[i][j]) == 1);
            
    forn (i, n)
        forn (j, n)
            assert(scanf ("%d", &b[i][j]) == 1);

    return true;
}

char used[K];
int minv[K];
int u[K], v[K], p[K], way[K];  

inline int venrg(int a[K][K], int n, int m)
{
     forn (i, n + 1)
     {
        u[i] = 0;
        v[i] = 0;
        p[i] = 0;
        way[i] = 0;
     }
     
     for (int i=1; i<=n; ++i) 
     {
        p[0] = i;
        int j0 = 0;
        
        forn (i, m + 1)
        {
            used[i] = 0;
            minv[i] = INF;
        }

        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
     }
     
     return -v[0];
}

int s[K][K];

inline void solve()
{
    int ans = INF;
    
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (!(mask & 31) && clock() > 1950)
            break;

        int cnt = 0;
        forn (j, n)
            if ((mask >> j) & 1)
                cnt++;
                
        if (cnt != n / 2)
            continue;
            
        forn(i, n)
            forn (j, n)
                s[i + 1][j + 1] = ((mask >> j) & 1) ? -b[i][j] : -a[i][j];
                
        ans = min(ans, venrg(s, n, n));
    }
    
    cout << -ans << endl;
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