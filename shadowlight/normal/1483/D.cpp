#include <bits/stdc++.h>
 
#define int long long
 
#define pii pair<int, int>
 
#define x1 x1228
#define y1 y1228
 
#define left left228
#define right right228
 
#define data data228
 
#define pb push_back
#define eb emplace_back
 
#define mp make_pair                                                                
 
#define ff first                                                                  
#define ss second   
 
#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << ": " << x << endl; 
#define TIME (ld)clock()/CLOCKS_PER_SEC
 
using namespace std;
typedef long long ll; 
typedef long double ld; 
 
const int maxn = 600 + 7, mod = 1e9 + 7, MAXN = 2e6 + 7;
const double eps = 1e-9;                                        
const ll INF = 1e18, inf = 1e15;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());                       
int n, m; 
int dist[maxn][maxn]; 
 
struct edge {
    int u, v, w; 
}; 
vector<pii> req[maxn]; 
int rem[maxn][maxn]; 
 
void solve() {
    cin >> n >> m;     
    vector<edge> e; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf; 
        }
        dist[i][i] = 0; 
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w, --u, --v; 
        e.pb({u, v, w}); 
        dist[u][v] = min(dist[u][v], w); 
        dist[v][u] = min(dist[v][u], w); 
    }
    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);  
            }
        }
    }
    int q; cin >> q; 
    for (int i = 0; i < q; ++i) {
        int u, v, l; cin >> u >> v >> l, --u, --v;
        req[u].pb({v, l});
        req[v].pb({u, l});                 
    }
 
    for (int i = 0; i < n; ++i) {
        vector<vector<int> > matr(n, vector<int> (n, inf)); 
        for (int u = 0; u < n; ++u) {
            for (auto v : req[u]) {
                matr[u][v.ff] = min(matr[u][v.ff], dist[u][i] - v.ss); 
            }
        }
        for (int u = 0; u < n; ++u) {
            int ver = 0; 
            for (int j = 0; j < n; ++j) {
                if (matr[ver][u] > matr[j][u]) {
                    ver = j; 
                }                                
            }
            rem[i][u] = matr[ver][u]; 
        }
    }
 
    int res = 0; 
    for (auto kek : e) {
        int u = kek.u; 
        int v = kek.v; 
        int w = kek.w; 
        bool ok = false; 
        for (int i = 0; i < n; ++i) {
            if (rem[u][i] + w + dist[v][i] <= 0) {
                ok = true; 
                break; 
            }                                    
        }
        for (int i = 0; i < n; ++i) {
            if (rem[v][i] + w + dist[u][i] <= 0) {
                ok = true; 
                break; 
            }                                    
        }
        res += ok; 
    }
    cout << res << '\n'; 
}                                
 
signed main() {                                                                             
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    int t = 1; 
    for (int i = 0; i < t; ++i) {              
        solve();
    }
    return 0;
}