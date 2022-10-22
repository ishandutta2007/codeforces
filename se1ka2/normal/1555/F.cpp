#include <functional>
#include <iostream>
#include <queue>
using namespace std;

const int K = (1 << 9);

struct UnionFind
{
    std::vector<int> par, sz;
    
    UnionFind(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    void clear(){
        int n = par.size();
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int i){
        if(i == par[i]) return i;
        return par[i] = find(par[i]);
    }
    
    bool same(int i, int j){
        return find(i) == find(j);
    }
    
    void unite(int i, int j){
        i = find(i), j = find(j);
        if(i == j) return;
        if(sz[i] < sz[j]) std::swap(i, j);
        par[j] = i;
        sz[i] += sz[j];
    }
    
    int size(int i){
        return sz[find(i)];
    }
};

template <typename T>
struct SegmentTree
{
    using F = function<T(T, T)>;
    
    const F f;
    const T e;
    
    int n;
    vector<T> seg;
    
    SegmentTree(int nn, const F f, const T e) : f(f), e(e){
        n = 1;
        while(n <= nn) n <<= 1;
        seg.assign(n * 2, e);
    }
    
    void set(int i, T x){
        seg[i + n] = x;
    }
    
    void build(){
        for(int k = n - 1; k > 0; k--){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    void update(int i, T x){
        int k = i + n;
        seg[k] = x;
        while(k >>= 1){
            seg[k] = f(seg[k * 2], seg[k * 2 + 1]);
        }
    }
    
    T query(int l, int r){
        l += n, r += n;
        T L = e, R = e;
        for(; l != r; l >>= 1, r >>= 1){
            if(l % 2) L = f(L, seg[l++]);
            if(r % 2) R = f(seg[--r], R);
        }
        return f(L, R);
    }
    
    T operator[](const int i)const {
        return seg[i + n];
    }
    
    template<typename C>
    int right_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(x, seg[k * 2]))){
                k = k * 2;
            }
            else{
                x = f(x, seg[k * 2]);
                k = k * 2 + 1;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int right_bound(int i, const C &check){
        T x = e;
        for(int l = i + n, r = n * 2; l != r; l >>= 1, r >>= 1){
            if(l % 2){
                if(check(f(x, seg[l]))){
                    return right_bound_sub(l, check, x);
                }
                x = f(x, seg[l]);
                l++;
            }
        }
        return -1;
    }
    
    template <typename C>
    int left_bound_sub(int k, const C &check, T x){
        while(k < n){
            if(check(f(seg[k * 2 + 1], x))){
                k = k * 2 + 1;
            }
            else{
                x = f(seg[k * 2 + 1], x);
                k = k * 2;
            }
        }
        return k - n;
    }
    
    template <typename C>
    int left_bound(int i, const C &check){
        T x = e;
        for(int l = n, r = i + n; l != r; l >>= 1, r >>= 1){
            if(r % 2){
                if(check(f(seg[--r], x))){
                    return left_bound_sub(r, check, x);
                }
                x = f(x, seg[r]);
            }
        }
        return -1;
    }
};

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

int x[500005], y[500005], z[500005];
bool b[300005];
bool c[300005];

void mark(int u, int k, Tree &t){
    if(k == 0) return;
    for(int v : t.t[u]){
        b[v] = true;
        mark(v, k - 1, t);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n + 1);
    Tree t(n + 1);
    for(int i = 0; i < q; i++){
        cin >> x[i] >> y[i] >> z[i];
        if(uf.same(x[i], y[i])) continue;
        uf.unite(x[i], y[i]);
        t.add_edge(x[i], y[i]);
    }
    for(int u = 1; u <= n; u++){
        if(uf.same(u, 0)) continue;
        uf.unite(u, 0);
        t.add_edge(u, 0);
    }
    t.build(0);
    t.build_euler_tour();
    t.build_lca();
    SegmentTree<int> seg(n * 2, [](int a, int b){return a ^ b;}, 0);
    uf.clear();
    for(int i = 0; i < q; i++){
        int u = x[i], v = y[i];
        if(t.par[u] == v) swap(u, v);
        if(!uf.same(x[i], y[i])){
            cout << "YES\n";
            uf.unite(x[i], y[i]);
            int l = t.appear_on_tour[v][0] - 1, r = t.appear_on_tour[v].back();
            seg.update(l, z[i]);
            seg.update(r, z[i]);
        }
        else{
            int w = t.lca(u, v);
            int l = t.appear_on_tour[u][0], r = t.appear_on_tour[v][0], s = t.appear_on_tour[w][0];
            if((seg.query(s, l) ^ seg.query(s, r) ^ z[i]) != 1){
                cout << "NO\n";
                continue;
            }
            int a = u;
            bool f = true;
            while(t.dpt[a] - t.dpt[w] > K){
                if(b[a]){
                    f = false;
                    break;
                }
                a = t.anc[9][a];
            }
            while(t.dpt[a] - t.dpt[w]){
                if(c[a]){
                    f = false;
                    break;
                }
                if(t.dpt[a] - t.dpt[w] == 1) break;
                a = t.par[a];
            }
            if(!f){
                cout << "NO\n";
                continue;
            }
            a = v;
            while(t.dpt[a] - t.dpt[w] > K){
                if(b[a]){
                    f = false;
                    break;
                }
                a = t.anc[9][a];
            }
            while(t.dpt[a] - t.dpt[w]){
                if(c[a]){
                    f = false;
                    break;
                }
                if(t.dpt[a] - t.dpt[w] == 1) break;
                a = t.par[a];
            }
            if(!f){
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            while(u != w){
                c[u] = true;
                mark(u, K, t);
                u = t.par[u];
            }
            while(v != w){
                c[v] = true;
                mark(v, K, t);
                v = t.par[v];
            }
        }
    }
}