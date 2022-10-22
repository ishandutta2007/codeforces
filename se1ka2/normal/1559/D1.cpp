#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

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

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    UnionFind uf1(n), uf2(n);
    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf1.unite(u, v);
    }
    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf2.unite(u, v);
    }
    vector<P> ans;
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            if(!uf1.same(u, v) && !uf2.same(u, v)){
                uf1.unite(u, v);
                uf2.unite(u, v);
                ans.push_back(P(u, v));
            }
        }
    }
    cout << ans.size() << endl;
    for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
}