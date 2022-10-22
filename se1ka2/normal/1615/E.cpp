#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 10000000000000;

struct Tree
{
    int n;
    int r;
    int l;
    std::vector<std::vector<int>> prit;
    std::vector<std::vector<int>> t;
    std::vector<int> par;
    std::vector<int> dpt;
    std::vector<int> tour;
    std::vector<std::vector<int>> appear_on_tour;
    std::vector<std::vector<int>> anc;
    
    Tree(){}
    
    Tree(int n) : n(n){
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }
    
    void add_edge(int u, int v){
        prit[u].push_back(v);
        prit[v].push_back(u);
    }
    
    void build(int r_){
        r = r_;
        for(int i = 0; i < n; i++) dpt[i] = -1;
        std::queue<int> que;
        par[r] = -1;
        dpt[r] = 0;
        que.push(r);
        while(que.size()){
            int u = que.front();
            que.pop();
            for(int v : prit[u]){
                if(dpt[v] == -1){
                    t[u].push_back(v);
                    par[v] = u;
                    dpt[v] = dpt[u] + 1;
                    que.push(v);
                }
            }
        }
    }
    
    void rebuild(int r_){
        for(int u = 0; u < n; u++) t[u].clear();
        build(r_);
    }
    
/*
    std::vector<int> toposort(){
        std::vector<std::pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
*/
    
    void dfs(int u, int &k){
        appear_on_tour[u].push_back(k);
        tour[k++] = u;
        for(int v : t[u]){
            dfs(v, k);
            appear_on_tour[u].push_back(k);
            tour[k++] = u;
        }
    }
    
    void build_euler_tour(){
        tour.resize(n * 2 - 1);
        appear_on_tour.resize(n);
        int k = 0;
        dfs(r, k);
    }
    
    void build_lca(){
        for(l = 1; l <= n; l++){
            if((1 << (l - 1)) >= n) break;
        }
        anc.resize(l);
        for(int j = 0; j < l; j++) anc[j].resize(n);
        for(int i = 0; i < n; i++) anc[0][i] = par[i];
        for(int j = 1; j < l; j++){
            for(int i = 0; i < n; i++){
                if(anc[j - 1][i] == -1) anc[j][i] = -1;
                else anc[j][i] = anc[j - 1][anc[j - 1][i]];
            }
        }
    }
    
    int lca(int u, int v){
        if(dpt[u] < dpt[v]) std::swap(u, v);
        int dpt_diff = dpt[u] - dpt[v];
        for(int j = l - 1; j >= 0; j--){
            if((dpt_diff >> j) & 1) u = anc[j][u];
        }
        if(u == v) return u;
        for(int j = l - 1; j >= 0; j--){
            if(anc[j][u] != anc[j][v]){
                u = anc[j][u];
                v = anc[j][v];
            }
        }
        return anc[0][u];
    }
};

void dfs(int u, int *d, Tree &t){
    for(int v : t.t[u]){
        if(d[v]){
            d[v] = d[u] + 1;
            dfs(v, d, t);
        }
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;
    Tree t(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        t.add_edge(u, v);
    }
    t.build(0);
    int d[200005];
    for(int u = 0; u < n; u++) d[u] = t.dpt[u];
    priority_queue<P> que;
    for(int u = 0; u < n; u++) que.push(P(d[u], u));
    ll a = 0, b = n - 1, w = 1;
    ll ans = -INF;
    while(que.size() && a < k){
        P p = que.top();
        que.pop();
        int u = p.second;
        if(d[u] != p.first){
            que.push(P(d[u], u));
            continue;
        }
        while(d[u]){
            d[u] = 0;
            b--;
            w++;
            dfs(u, d, t);
            u = t.par[u];
        }
        a++;
        w--;
        if(b >= n / 2) ans = max(ans, -(a - n / 2) * (a - (n - n / 2)));
        else ans = max(ans, (a - b) * (n - a - b));
    }
    cout << ans << endl;
}