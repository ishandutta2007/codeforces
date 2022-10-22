#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> PP;

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

vector<int> lf[100005];

void change_tree(Tree &t, vector<PP> &ans){
    int n = t.n;
    int d[100005];
    for(int i = 0; i < n; i++) d[i] = t.t[i].size();
    vector<int> p = t.toposort();
    bool b[100005];
    for(int i = 0; i < n; i++) b[i] = true;
    for(int i = 0; i < n; i++) lf[i].clear();
    for(int i = 0; i < n - 1; i++){
        int u = p[i];
        if(d[u] == 0) lf[u].push_back(u);
        while(d[u] >= 2){
            int v = -1;
            for(int w : t.t[u]){
                if(b[w] && d[w] >= 2) v = w;
            }
            if(v == -1) break;
            b[v] = false;
            for(int w : t.t[u]){
                if(b[w]){
                    int l1 = lf[v].back(), l2 = lf[w].back();
                    lf[v].pop_back(); lf[w].pop_back();
                    ans.push_back(PP(P(u, v), P(l1, l2)));
                    d[u]--;
                    if(lf[w].size() < lf[v].size()) swap(lf[w], lf[v]);
                    for(int l : lf[v]) lf[w].push_back(l);
                    lf[v].clear();
                    break;
                }
            }
        }
        for(int v : t.t[u]){
            if(b[v]){
                if(lf[u].size() < lf[v].size()) swap(lf[u], lf[v]);
                for(int l : lf[v]) lf[u].push_back(l);
                lf[v].clear();
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Tree t0(n);
        int d[100005];
        for(int i = 0; i < n; i++) d[i] = 0;
        int a[100005], b[100005];
        for(int i = 0; i < n - 1; i++){
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
            t0.add_edge(a[i], b[i]);
            d[a[i]]++, d[b[i]]++;
        }
        for(int r = 0; r < n; r++){
            if(d[r] == 1){
                t0.build(r);
                break;
            }
        }
        vector<PP> ans;
        change_tree(t0, ans);
        set<P> st;
        Tree t1(n);
        for(PP pp : ans){
            st.insert(pp.first);
            t1.add_edge(pp.second.first, pp.second.second);
        }
        for(int i = 0; i < n - 1; i++){
            if(st.find(P(a[i], b[i])) == st.end() && st.find(P(b[i], a[i])) == st.end()){
                t1.add_edge(a[i], b[i]);
            }
        }
        int r;
        for(r = 0; r < n; r++){
            if(d[r] == 1){
                t1.build(r);
                break;
            }
        }
        vector<int> lf;
        for(int i = 0; i < n; i++){
            d[i] = t1.t[i].size();
            if(d[i] == 0) lf.push_back(i);
        }
        int l = lf.back();
        lf.pop_back();
        while(l != r){
            int u = t1.par[l];
            if(d[u] >= 2){
                int v = lf.back();
                lf.pop_back();
                d[u]--;
                d[v]++;
                ans.push_back(PP(P(l, u), P(l, v)));
                l = v;
            }
            else l = u;
        }
        cout << ans.size() << endl;
        for(PP pp : ans){
            cout << pp.first.first + 1 << " " << pp.first.second + 1 << " " <<
                pp.second.first + 1 << " " << pp.second.second + 1 << endl;
        }
    }
}