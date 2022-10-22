#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> P;

struct UnionFind
{
    std::vector<int> par, sz;
    std::set<int> st;
    
    UnionFind(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
            st.insert(i);
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
        st.erase(j);
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
    for(int u = 1; u < n; u++){
        if(uf1.same(0, u)){
            if(uf2.same(0, u));
            else{
                for(int v : uf1.st){
                    if(uf1.same(u, v)) continue;
                    if(!uf2.same(u, v)){
                        ans.push_back(P(u, v));
                        uf1.unite(u, v);
                        uf2.unite(u, v);
                    }
                    else{
                        ans.push_back(P(0, v));
                        uf1.unite(0, v);
                        uf2.unite(0, v);
                    }
                    break;
                }
            }
        }
        else{
            if(uf2.same(0, u)){
                for(int v : uf2.st){
                    if(uf2.same(u, v)) continue;
                    if(!uf1.same(u, v)){
                        ans.push_back(P(u, v));
                        uf1.unite(u, v);
                        uf2.unite(u, v);
                    }
                    else{
                        ans.push_back(P(0, v));
                        uf1.unite(0, v);
                        uf2.unite(0, v);
                    }
                    break;
                }
            }
            else{
                ans.push_back(P(0, u));
                uf1.unite(0, u);
                uf2.unite(0, u);
            }
        }
    }
    cout << ans.size() << endl;
    for(P p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
}