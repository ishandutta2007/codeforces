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
#define all(x) begin(x), end(x)


#define each(a,x) for (auto& a: x)
#define tcT template<class T

#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;

typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


tcT> void re(V<T>& x) { each(a,x) re(a); }


void decrement() {}
tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);


vector< vi> g;
vector< ll > s;

pair<ll, ll> dfs(int v, int k) {
    if (g[v].size() == 0) {
        return pair<ll,ll> {s[v] * k, s[v]};
    }
    
    int pa = k / sz(g[v]);
    
    ll tot = s[v] * k;
    vector<ll> marginal;
    for (int x : g[v]) {
        pair<ll, ll> d = dfs(x, pa);
        marginal.push_back(d.second);
        tot += d.first;
    }
    
    sort(all(marginal));
    reverse(all(marginal));
    for (int i = 0; i < (k % sz(g[v])); i++) {
        tot += marginal[i];
    }
    
    return pair<ll,ll>{tot, marginal[k % sz(g[v])] + s[v]};
}

void go() {
    ints(n,k);
    g = vector< vi > (n);
    for (int i = 1; i < n; i++) {
        int1(x);
        g[x].push_back(i);
    }
    s = vector<ll>(n); re(s);
    
    ps( dfs(0, k).first );
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}