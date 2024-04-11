
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

int n, st;
const int N = 5000 + 5;
const int M = 2 * N;

pt p[N];

inline bool read()
{
    cin >> n >> st;
    forn (i, n) {
        cin >> p[i].ft >> p[i].sc;
    }
    return true;
}

li dp[2][M];
vector<li> x;

int pos(int a) {
    return lower_bound(all(x), a) - x.begin();
}

inline void solve()
{
    forn (i, n) {
        x.pb(p[i].ft);
        x.pb(p[i].sc);
    }
    
    x.pb(st);
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    
    forn (i, 2)
        forn (j, sz(x))
            dp[i][j] = INF64;
    
    dp[0][pos(st)] = 0;
    forn (i, n) {
        int _i = (i & 1);
        
        forn (j, sz(x))
            dp[_i ^ 1][j] = INF64;

        int l = pos(p[i].ft);
        int r = pos(p[i].sc);
        li bt = INF64;
        forn (j, l + 1) {
            bt = min(bt, dp[_i][j] + p[i].ft - x[j]);
            dp[_i ^ 1][j] = min(dp[_i ^ 1][j], bt);             
        }
        
        fore (j, l, r)
            dp[_i ^ 1][j] = min(dp[_i ^ 1][j], dp[_i][j]);

        bt = INF64;
            
        for (int j = sz(x) - 1; j >= r; --j) {
            bt = min(bt, dp[_i][j] + x[j] - p[i].sc);
            dp[_i ^ 1][j] = min(dp[_i ^ 1][j], bt);                     
        }
    }
    
    li ans = INF64;
    
    forn (i, sz(x))
        ans = min(ans, dp[n & 1][i]);
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