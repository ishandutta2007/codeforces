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
        int d[300005];
        for(int i = 0; i < n; i++) d[i] = 0;
        int p[300005];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
            d[(i + n - p[i]) % n]++;
        }
        vector<int> ans;
        for(int r = 0; r < n; r++){
            if(d[r] < n / 3) continue;
            int q[300005];
            for(int i = 0; i < n; i++){
                q[i] = p[(i + r) % n];
            }
            UnionFind uf(n);
            int k = 0;
            for(int i = 0; i < n; i++){
                if(!uf.same(q[i], i)){
                    k++;
                    uf.unite(q[i], i);
                }
            }
            if(k <= m) ans.push_back(r);
        }
        cout << ans.size() << " ";
        for(int r : ans) cout << r << " ";
        cout << endl;
    }
}