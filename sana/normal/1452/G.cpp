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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

typedef string str;

typedef pair<int, int> pii;
typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }

 
vi bob;

typedef vector<vector<int>> vvi;
struct Centroid {
    vvi g, centrG, dist; //
    vector<int> sub, cpar;
    vector< vector<pii> > rdist;
    vector<bool> done;
    Centroid(vvi &g_) : g(g_), centrG(sz(g)), dist(centrG), sub(g.size()), cpar(sub), rdist(sz(g)), done(g.size()) { init(0); }
    void process(int x, int d, int c, int p = -1) {
        dbg(x,c,dist[x],d);
        dist[x].push_back(d);
        rdist[c].emplace_back(d - bob[x], -bob[x]);
        for (auto i : g[x]) {
            if (i != p && !done[i]) {
                process(i, d + 1, c, x);
            }
        }
    }
    int init(int x) {
        int c = getCentr(x, dfs(x));
        done[c] = true;
        process(c, 0, c);
        for (auto i : g[c]) {
            if (!done[i]) {
                centrG[c].push_back(init(i));
                cpar[centrG[c].back()] = c;
            }
        }
        sort(all(rdist[c]));
        vector< pii > ans_c;
        for (pii p : rdist[c]) {
            if (ans_c.empty() || ans_c.back().second < -p.second) ans_c.emplace_back(p.first, -p.second);
        }
        rdist[c] = move(ans_c);
        
        return c;
    }
    int dfs(int x, int p = -1) {
        sub[x] = 1;
        for (auto i : g[x]) {
            if (!done[i] && i != p) {
                sub[x] += dfs(i, x);
            }
        }
        return sub[x];
    }
    int getCentr(int x, int totSz, int p = -1) {
        for (auto i : g[x]) {
            if (i != p && !done[i] && sub[i] > totSz / 2)
                return getCentr(i, totSz, x);
        }
        return x;
    }
    
    int query(int a) {
        int c = a;
        int ans = 0;
        for (int i = sz(dist[a]) - 1; i >= 0; i--) {
            auto it = lower_bound(all(rdist[c]), pii{-dist[a][i], -1000000000});
            dbg(a, c, rdist[c], dist[a][i]);
            if (it != rdist[c].begin()) ans = max(ans, (--it)->second);
            c = cpar[c];
        }
        return ans;
    }
};

// cf1452G: Alice can reach a vertex safely iff distA[v] < distB[v]
// proof: if Bob catches Alice in the path, then he can follow Alice and distB[v] <= distA[v]
void solve()
{
    int n; cin >> n;
    vvi g(n);
    REP(i,n-1) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    bob = vi(n, 1000000000);
    int k;
    for (cin >> k; k; k--) {
        int t; cin >> t; t--;
        bob[t] = 0;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) if (bob[i] == 0) q.push(i);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : g[v]) if (bob[x] > bob[v]+1) {
            bob[x] = bob[v]+1;
            q.push(x);
        }
    }
    
    Centroid cent(g);
    for (int i = 0; i < n; i++) pr(cent.query(i), " ");
    ps();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}