#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p[400005], q[400005];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
        }
        for(int i = 0; i < n; i++){
            cin >> q[i];
            q[i]--;
        }
        UnionFind uf(n);
        for(int i = 0; i < n; i++) uf.unite(p[i], q[i]);
        ll ans = 1;
        for(int i = 0; i < n; i++){
            if(uf.find(i) == i) ans = ans * 2 % 1000000007;
        }
        cout << ans << endl;
    }
}