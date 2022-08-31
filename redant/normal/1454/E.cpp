#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        VI G[n];
        REP(i, n) {
            int u, v; cin >> u >> v;
            --u; --v;
            G[u].PB(v);
            G[v].PB(u);
        }

        vector<bool> cyc(n);
        vector<bool> vis(n);
        vector<int> par(n, -1);

        bool got = false;
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = true;
            for (auto v : G[u]) {
                if (v == par[u]) continue;
                if (vis[v]) {
                    for (int x = u; x != par[v]; x = par[x])
                        cyc[x] = true;
                    got = true;
                    return;
                }
                par[v] = u;
                dfs1(v);
                if (got) return;
            }
        };

        dfs1(0);

        LL res = 1ll * n * (n - 1);

        function<int(int)> dfs2 = [&](int u) {
            int r = 1;
            for (auto v : G[u]) {
                if (par[u] == v) continue;
                if (cyc[v]) continue;
                par[v] = u;
                r += dfs2(v);
            }
            return r;
        };

        par.assign(n, -1);
        REP(i, n) if (cyc[i]) {
            LL k = dfs2(i);
            res -= k * (k - 1) / 2;
        }

        cout << res << "\n";
    }
    
    return 0;
}