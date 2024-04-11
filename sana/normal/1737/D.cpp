#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


using namespace std;
 

#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


ll g[510][510];

void go() {
    ints(n,m);
    
    const ll INFLL = 1000000000000000000LL;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g[i][j]=INFLL;
    
    vector< array<int,3> > ed;
    for (int i = 0; i < m; i++) {
        int u,v,w; re(u,v,w); u--; v--;
        
        ed.push_back({u, v, w});
        g[u][v]=1;
        g[v][u]=1;
    }
    
    for (int i = 0; i < n; i++) g[i][i] = 0;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    
    vector<ll> dist(n, INFLL);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i] = min(dist[i], g[i][j]+g[0][j]+g[j][n-1]+1);
        }
    }
    
    ll ans = INFLL;
    
    for (auto [x, y, w] : ed) {
        ans = min(ans, (min({dist[x], dist[y], g[0][x]+g[n-1][y], g[0][y]+g[n-1][x]})+1)*w);
        dbg(x,y,w,dist[x],dist[y],g[0][x]+g[n-1][y],g[0][y]+g[n-1][x]);
    }
    
    ps(ans);
}

void solve()
{
    int t;
    for (re(t); t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}