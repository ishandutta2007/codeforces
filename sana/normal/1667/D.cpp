//#define LOCAL
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

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


typedef string str;

typedef pair<int, int> pii;
typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

vector<vi> g;
vi h, par;
vector<pii> ans;

pii dfs(int v, int p) {
    par[v] = p;
    if (p != -1) h[v] = h[p]+1;
    
    vi have[2];
    
    for (int x : g[v]) if (x != p) {
        pii ret = dfs(x,v);
        if (ret.first == -1) return {-1, -1};
        if (ret.first != -2) have[ret.first].push_back(ret.second);
    }
    
    if (sz(g[v]) % 2) have[ h[v] % 2 ].push_back(v);
    
    while (!have[0].empty() && !have[1].empty()) {
        ans.push_back( {have[0].back(), have[1].back()} );
        have[0].pop_back();
        have[1].pop_back();
    }
    
    if (sz(have[0]) + sz(have[1]) == 0) return {-2, -1};
    if (sz(have[0]) + sz(have[1]) >= 2) return {-1, -1};
    if (!have[0].empty()) return pii{0, have[0].front()};
    return pii{1, have[1].front()};
}

void go() {
    int n; cin >> n;
    
    g = vector<vi>(n);
    for (int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    h = vi(n);
    par = vi(n);
    ans = vector<pii>();
    
    if (dfs(0,-1).first != -2) {
        cout << "NO" << '\n';
        return;
    }
    
    ps("YES");
    for (auto [a,b] : ans) {
        vector<pii> patha;
        vector<pii> pathb;
        
        while (a != b) {
            dbg(a,b);
            if (h[a] >= h[b]) {
                patha.push_back({a, par[a]});
                a = par[a];
            }
            else if (h[b] >= h[a]) {
                pathb.push_back({b, par[b]});
                b = par[b];
            }
        }
        
        reverse(all(pathb));
        patha.insert(patha.end(), all(pathb));
        for (int i = 1; i < sz(patha); i += 2) {
            ps(patha[i].first+1, patha[i].second+1);
        }
        for (int i = 0; i < sz(patha); i += 2) {
            ps(patha[i].first+1, patha[i].second+1);
        }
    }
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