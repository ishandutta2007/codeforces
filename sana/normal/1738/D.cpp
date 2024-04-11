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
 

#define each(a,x) for (auto& a: x)
#define tcT template<class T


template<class T> using V = vector<T>; 


typedef string str;


typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


vi ans;
vi st;
int cross;

void dfs(int v, vector<vi>& g, int curst) {
    dbg(v,curst);
    for (int x : g[v]) {
        if (g[x].empty()) {
            ans.push_back(x);
            if (curst == 1) cross = max(cross, x+1);
        }
    }
    for (int x : g[v]) {
        if (!g[x].empty()) {
            ans.push_back(x);
            if (curst == 1) cross = max(cross, x+1);
            dfs(x,g,curst^1);
        }
    }
}

void go() {
    ints(n);
    vi a(n); re(a);
    for (int i = 0; i < n; i++) a[i]--;
    
    st = vi(n);
    cross = 0;
    int curst = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]==n) curst = 1;
    }
    
    vector<vi> g(n+1);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x == -1) x = n;
        g[ x ].push_back(i);
    }
    
    ans.clear();
    dfs(n, g, curst);
    
    ps(cross);
    for (int x : ans) pr(x+1," ");
    ps();
}

void solve()
{
    ints(t);
    for (; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}