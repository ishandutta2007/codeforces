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

 
tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcT> void re(V<T>& x) { each(a,x) re(a); }


typedef vector<vector<int>> vvi;
int nq;
vi xq;
vi dist_f;
vvi g, bld;
vi ans;

void dfs(int v, int p) {
    bld[v] = {dist_f[v]};
    
    for (int x : g[v]) if (x != p) {
        dfs(x, v);
        
        bld[x].push_back(bld[x].back());
        if (sz(bld[x]) > sz(bld[v])) {
            swap(bld[x], bld[v]);
        }
        
        for (int d = 0; d < sz(bld[x]); d++) {
            int real_dist = sz(bld[x]) - d - 1;
            
            for (int q = 0; q < nq; q++) {
                while (true) {
                    int want = max(0, ans[q] + 1 - real_dist);
                    if (want >= sz(bld[v])) break;
                    if (bld[x][d] + xq[q] + bld[v][ sz(bld[v]) - 1 - want ] < ans[q]+1) break;
                    
                    if (q == 0) dbg(q, v, x, real_dist, ans[q]+1, bld[x], bld[v], want, sz(bld[v]) - 1 - want);
                    ans[q]++;
                }
            }
        }
        
        for (int d = 0; d < sz(bld[x]); d++) {
            bld[v][sz(bld[v])-1-d] = max(bld[x][sz(bld[x])-1-d], bld[v][sz(bld[v])-1-d]);
        }
        bld[x].clear();
    }
}

void solve()
{
    int n; re(n);
    
    g = vvi(n);
    bld = vvi(n);
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        g[u].push_back(i);
        g[i].push_back(u);
    }
    
    cin >> nq;
    xq = vi(nq); re(xq);
    
    dist_f = vi(n, 1000000000);
    queue<int> q;
    for (int i = 0; i < n; i++) if (sz(g[i]) == 1) {
        dist_f[i] = 0;
        q.push(i);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int x : g[cur]) if (dist_f[x] > dist_f[cur] + 1) {
            dist_f[x] = dist_f[cur] + 1;
            q.push(x);
        }
    }
    
    dbg(dist_f);
    ans = vi(nq, 0);
    
    dfs(0, -1);
    
    for (int x : ans) pr(x, " ");
    ps();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}