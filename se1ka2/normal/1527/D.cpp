#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

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
    
    std::vector<int> toposort(){
        std::vector<std::pair<int, int>> p(n);
        for(int i = 0; i < n; i++) p[i] = std::pair<int, int>(dpt[i], i);
        sort(p.begin(), p.end(), std::greater<std::pair<int, int>>());
        std::vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
    
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

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Tree t(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            t.add_edge(u, v);
        }
        t.build(0);
        vector<int> p = t.toposort();
        ll s[200005];
        for(int i = 0; i < n; i++){
            int u = p[i];
            s[u] = 1;
            for(int v : t.t[u]) s[u] += s[v];
        }
        t.build_lca();
        int par[200005];
        int child[200005];
        for(int u = 0; u < n; u++) par[u] = child[u] = -1;
        par[1] = 0;
        child[0] = 1;
        int left = 0, right = 1;
        int w = 1;
        while(t.par[w] != 0) w = t.par[w];
        bool f = true;
        for(int u = 0; u < n; u++){
            bool g = true;
            if(u >= 2){
                int v = u;
                while(v >= u) v = t.par[v];
                if(v == 0){
                    if(t.lca(u, right) == u){
                        par[right] = u;
                        par[u] = 0;
                        child[u] = right;
                    }
                    else if(t.lca(u, left) == u){
                        par[left] = u;
                        par[u] = 0;
                        child[u] = left;
                    }
                    else if(left == 0 && t.lca(u, right) == 0){
                        par[u] = 0;
                        left = u;
                    }
                    else g = false;
                }
                else{
                    if(child[v] == -1){
                        par[u] = v;
                        child[v] = u;
                        if(v == left) left = u;
                        else right = u;
                    }
                    else{
                        if(t.lca(u, child[v]) != u) g = false;
                        else{
                            par[child[v]] = u;
                            par[u] = v;
                            child[u] = child[v];
                            child[v] = u;
                        }
                    }
                }
            }
            if(!f){
                cout << 0 << " ";
                continue;
            }
            ll ans = 0;
            if(u == 0){
                for(int v : t.t[u]) ans += s[v] * (s[v] - 1) / 2;
            }
            else if(u == 1){
                ans = (s[0] - s[1] - 1) * (s[0] - s[1] - 1);
                for(int v : t.t[0]){
                    if(v == w) ans -= (s[w] - s[1]) * (s[w] - s[1]);
                    else ans -= s[v] * s[v];
                }
                ans = ans / 2 + (s[0] - 1 - s[1]);
            }
            else if(!g && left == 0){
                ans = s[right] * (s[0] - s[w]);
                f = false;
            }
            else if(!g){
                ans = s[right] * s[left];
                f = false;
            }
            else if(right == u && left == 0){
                int r = par[u];
                ans = (s[r] - s[u]) * (s[0] - s[w]);
            }
            else if(left == u && par[u] == 0){
                ans = s[right] * (s[0] - s[w] - s[u]);
            }
            else if(right == u){
                int r = par[u];
                ans = (s[r] - s[u]) * s[left];
            }
            else if(left == u){
                int r = par[u];
                ans = (s[r] - s[u]) * s[right];
            }
            else ans = 0;
            cout << ans << " ";
        }
        if(f) cout << 1 << endl;
        else cout << 0 << endl;
    }
}