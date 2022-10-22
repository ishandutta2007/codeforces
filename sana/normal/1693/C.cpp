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
 
 
using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;
typedef long long ll;

typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

const int INF = 1000000000;
typedef pair<int, int> pii;

void solve()
{
    ints(n,m);
    vector<vi> g(n);
    vector<vi> rg(n);
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v; u--; v--;
        edges[i] = pii{u,v};
        g[u].push_back(i);
        rg[v].push_back(i);
    }
    
    set<pii> s;
    vi real_costs(n, INF);
    vi heuristic(n, INF);
    
    vector< set<int> > optimal_costs(n);
    vector< ordered_set< pii > > out_costs(n);
    
    for (int i = 0; i < m; i++) {
        out_costs[edges[i].first].insert({INF, -i});
    }
    
    heuristic[n-1] = 0;
    for (int i = 0; i < n; i++) {
        s.insert({heuristic[i], i});
    }
    
    auto calc = [&](int src, int real_cost) {
        int order = out_costs[src].order_of_key({real_cost, INF});
        int blocked = (int)g[src].size() - order;
        return blocked + real_cost + 1;
    };
    
    int tt = 10;
    auto update = [&](int city, int real_cost) {
        for (int edge : rg[city]) {
            int src = edges[edge].first;
            if (real_costs[src] == INF) s.erase({heuristic[src], src});
            
            out_costs[src].erase({INF, -edge});
            out_costs[src].insert({real_cost, ++tt});
            
            auto it = optimal_costs[src].insert(real_cost).first;
            auto nxt = next(it);
            
            while (it != optimal_costs[src].begin() && calc(src, *it) <= calc(src, *prev(it))) optimal_costs[src].erase(prev(it));
            while (nxt != optimal_costs[src].begin() && nxt != optimal_costs[src].end() && calc(src, *nxt) <= calc(src, *prev(nxt))) optimal_costs[src].erase(prev(nxt));
            
            heuristic[src] = calc(src, *optimal_costs[src].begin());
            if (real_costs[src] == INF) s.insert({heuristic[src], src});
        }
    };
    
    
    for (int _ = 0; _ < n; _++) {
        int cur = s.begin()->second;
        s.erase(s.begin());
        
        real_costs[cur] = heuristic[cur];
        update(cur, real_costs[cur]);
    }
    
    ps(real_costs[0]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}