#include <bits/stdc++.h>
#define endl '\n'
 
#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back
 
using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);
 
struct dsu {
    int sz;
    vector<int> par, psz;
 
    void init(int n) {
        sz = n;
        par.assign(sz + 1, 0);
        psz.assign(sz + 1, 0);
        for(int i = 0; i <= sz; i++)
            par[i] = i, psz[i] = 1;
    }
 
    int root(int u) { return par[u] = ((u == par[u]) ? u : root(par[u])); }
    bool connected(int x, int y) { return root(x) == root(y); }
 
    void unite(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return;
        if(psz[x] > psz[y]) swap(x, y);
        par[x] = y, psz[y] += psz[x]; 
    }
};
 
int n, m, q;
int p[MAXN];
pair<int, int> e[MAXN];
pair<int, int> que[MAXN];
int removed[MAXN];
 
int ver[MAXN];
 
void read() {
    cin >> n >> m >> q;
 
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        ver[p[i]] = i;
    }
 
    for(int i = 1; i <= m; i++) {
        cin >> e[i].first >> e[i].second;
    }
 
    for(int i = 1; i <= q; i++) {
        cin >> que[i].first >> que[i].second;
        if(que[i].first == 2) {
            removed[que[i].second] = true;
        }
    }
}
 
dsu d;
int smaller[MAXN];
set<int> adj[MAXN];
 
int used[MAXN], TIMER = 0;
priority_queue<int> pq[MAXN << 1];
 
void dfs(int u) {
    if(p[u] != 0) {
        pq[TIMER].push(p[u]);
    }
 
    used[u] = TIMER;
 
    for(int v: adj[u]) {
        if(used[v] != TIMER) {
            dfs(v);
        }
    }
}
 
void create_new_comp(int u) {
    TIMER++;
    dfs(u);
}
 
void solve() {
    d.init(n);
    for(int i = 1; i <= m; i++) {
        if(!removed[i]) {
            d.unite(e[i].first, e[i].second);
        }
    }
 
    for(int i = q; i >= 1; i--) {
        smaller[i] = -1;
        
        int id = que[i].second; 
        if(que[i].first == 2 && !d.connected(e[id].first, e[id].second)) {
            int r1 = d.root(e[id].first), r2 = d.root(e[id].second);
            if(d.psz[r1] < d.psz[r2]) {
                smaller[i] = e[id].first;
            } else {
                smaller[i] = e[id].second;
            }
 
            d.unite(e[id].first, e[id].second);
        }
    }
 
    for(int i = 1; i <= m; i++) {
        adj[e[i].first].insert(e[i].second);
        adj[e[i].second].insert(e[i].first);
    }
 
    for(int i = 1; i <= n; i++) {
        if(used[i] == 0) {
            create_new_comp(i);
        }
    }
 
    for(int i = 1; i <= q; i++) {
        if(que[i].first == 1) {
            int comp = used[que[i].second];
            int ans = 0;
            while(!pq[comp].empty()) {
                int cand = ver[pq[comp].top()];
                pq[comp].pop();
                
                if(used[cand] == comp && p[cand] != 0) {
                    ans = cand;
                    break;
                }
            }
            
            cout << p[ans] << endl;
            if(ans != 0) p[ans] = 0;
        } else {
            int id = que[i].second;
            adj[e[id].first].erase(e[id].second);
            adj[e[id].second].erase(e[id].first);
 
            if(smaller[i] != -1) {
                create_new_comp(smaller[i]);
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    read();
    solve();
    return 0;
}