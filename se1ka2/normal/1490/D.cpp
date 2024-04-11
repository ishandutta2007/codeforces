#include <iostream>
#include <queue>
using namespace std;

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
    
    Tree(int n, int r) : n(n), r(r){
        prit.resize(n);
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
    }
    
    void add_edge(int u, int v){
        prit[u].push_back(v);
        prit[v].push_back(u);
    }
    
    void build(){
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

/*    std::vector<int> toposort(){
        std::vector<std::pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }*/
    
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
        dfs(0, k);
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

void dfs(int l, int r, int p, int *a, Tree &t){
    if(r <= l) return;
    int m = l;
    for(int i = l; i < r; i++){
        if(a[i] > a[m]) m = i;
    }
    if(p != -1) t.add_edge(p, m);
    dfs(l, m, m, a, t);
    dfs(m + 1, r, m, a, t);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[102];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        int m = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > a[m]) m = i;
        }
        Tree t(n, m);
        dfs(0, n, -1, a, t);
        t.build();
        for(int i = 0; i < n; i++) cout << t.dpt[i] << " ";
        cout << endl;
    }
}