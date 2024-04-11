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

int nx[300005], pr[300005];
vector<int> p[300005];
int c[300005], d[300005];
int s[300005];
int ans[300005];

void dfs(int u, int &i, Tree &t){
    s[c[u]]++;
    if(s[c[u]] == (int)p[c[u]].size()){
        for(int v : p[c[u]]) ans[i++] = v;
        for(int v : p[c[u]]){
            for(int w : t.t[v]) dfs(w, i, t);
        }
        return;
    }
    for(int v : t.t[u]){
        if(c[v] == c[u] && d[v] > d[u]) dfs(v, i, t);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    Tree t(n);
    int r = -1;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p != 0) t.add_edge(--p, i);
        else r = i;
    }
    t.build(r);
    for(int i = 0; i < n; i++) nx[i] = pr[i] = -1;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(nx[x] != -1 || pr[y] != -1){
            cout << 0 << endl;
            return 0;
        }
        nx[x] = y;
        pr[y] = x;
    }
    for(int i = 0; i < n; i++) c[i] = d[i] = -1;
    for(int i = 0; i < n; i++){
        if(pr[i] == -1){
            int u = i;
            int e = 0;
            while(u != -1){
                p[i].push_back(u);
                c[u] = i;
                d[u] = e++;
                u = nx[u];
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(c[i] == -1){
            cout << 0 << endl;
            return 0;
        }
    }
    int i = 0;
    dfs(r, i, t);
    if(i < n){
        cout << 0 << endl;
        return 0;
    }
    for(i = 0; i < n; i++) cout << ans[i] + 1 << " ";
    cout << endl;
}