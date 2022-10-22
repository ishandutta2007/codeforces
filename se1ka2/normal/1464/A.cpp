#include <iostream>
#include <vector>
using namespace std;

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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int b[100005];
        for(int i = 0; i < n; i++) b[i] = -1;
        UnionFind uf(n);
        int ans = m;
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            x--; y--;
            if(x == y){
                ans--;
                continue;
            }
            if(b[x] != -1) uf.unite(i, b[x]);
            else b[x] = i;
            if(b[y] != -1){
                if(uf.same(i, b[y])) ans++;
                else uf.unite(i, b[y]);
            }
            else b[y] = i;
        }
        cout << ans << endl;
    }
}