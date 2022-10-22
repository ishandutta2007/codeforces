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
 

#define sz(x) (int)(x).size()


#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;

typedef pair<int, int> pii;
typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


void decrement() {}
tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);


vector< vector<pii> > g;
string ans;
vi d;
vi pe;
vector< pair< pii, int> > ex;

void dfs(int v, int p) {
    if (p != -1) d[v] = d[p]+1;
    else d[v] = 0;
    
    for (auto [x, ei] : g[v]) if (x != p) {
        if (d[x] == -1) dfs(x, v);
        else if (d[x] < d[v]) {
            ex.emplace_back( pii{v, x}, ei );
        }
    }
    else {
        pe[v] = ei;
    }
}

void go() {
    ints(n,m);
    
    ans = string(m, '0');
    g = vector< vector<pii> >(n);
    d = vi(n, -1);
    pe = vi(n,-1);
    ex = vector< pair<pii, int> >();
    
    for (int i = 0; i < m; i++) {
        int1(u,v);
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    
    dfs(0, -1);
    
    map<int,int> ec;
    for (auto [e, _] : ex) {
        auto [u,v] = e;
        ec[u]++; ec[v]++;
    }
    
    bool ok = false;
    for (auto [k,v] : ec) {
        if (v != 2) ok = true;
    }
    if (sz(ex) != 3) ok = true;
    
    if (!ok) {
        auto [e, _] = ex.back();
        ex.pop_back();
        ans[pe[e.first]]='1';
    }
    for (auto [_, e] : ex) ans[e]='1';
    
    ps(ans);
}

void solve()
{
    int t;
    for (cin >> t; t;  t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}